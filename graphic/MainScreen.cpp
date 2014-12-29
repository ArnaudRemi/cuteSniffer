//
// MainScreen.cpp for SN in /home/orsini_a//SN
// 
// Made by antoine orsini
// Login   <orsini_a@epitech.net>
// 
// Started on  Fri Dec  5 17:22:20 2014 antoine orsini
// Last update Fri Dec  5 18:22:15 2014 antoine orsini
//

#include "FocusView.hh"
#include "MainScreen.hh"

MainScreen::MainScreen(QWidget * parent) {
    Interaction *n1 = new Interaction("n1", "p1");
    Interaction *n2 = new Interaction("n2", "p2");
    Interaction *n3 = new Interaction("n3", "p3");
    Interaction *n4 = new Interaction("n4", "p4");

    _mylist.push_front(n1);
    _mylist.push_front(n2);
    _mylist.push_front(n3);
    _mylist.push_front(n4);

    this->init();

    this->ifList = NULL;
    this->filters = NULL;

}

void    MainScreen::init() {
    this->setFixedSize(1200, 780);
    this->addButon(900, 100, "Quitter", MainScreen::Quit);
    this->addButon(900, 200, "Capturer", MainScreen::Capture);
    this->addButon(900, 300, "Filtrer", MainScreen::Filtre);
    this->addButon(900, 400, "Forger", MainScreen::Forge);
    this->addButon(900, 500, "Man in the middle", MainScreen::Man);
    this->addButon(900, 600, "Modifier", MainScreen::Modif);
    this->_table = new QTableWidget(this);
    _table->setGeometry(10, 10, 300, 300);
    _table->setColumnCount(2);
    connect(_table, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(cellSelected(int, int)));
    this->fillInfo();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getPacket()));
    timer->start(100);
    this->show();
}

std::list <std::string> *MainScreen::getAllInterfaces() {
    std::list <std::string> *lif = new std::list <std::string>;
    struct ifaddrs *ifaddr, *ifa;
    int n;

    if (getifaddrs(&ifaddr) == -1) {
        std::cout << "Error getifaddrs" << std::endl;
        return NULL;
    }

    for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
        if (ifa->ifa_addr == NULL)
            continue;
        if (std::find(std::begin(*lif), std::end(*lif), ifa->ifa_name) == std::end(*lif))
            lif->push_back(ifa->ifa_name);
    }

    freeifaddrs(ifaddr);

    return lif;
}

void    MainScreen::getPacket() {
    Ethernet *pqt = socket.getPacket();
    if (pqt)
        std::cout << *pqt << std::endl;

    if (filters != NULL)
        for (Filter *filter : *filters)
            if (!filter->isValid(pqt))
                return;

    std::cout << "valid packet" << std::endl;
}

void    MainScreen::fillInfo() {
    int y;
    std::list<Interaction *>::const_iterator it(_mylist.begin());

    _table->setRowCount(this->_mylist.size());
    //_table->setHorizontalHeaderLabels(_tableHeader);
    y = 1;
    while (it != _mylist.end())
        it++;
    it--;
    while (y <= (this->_mylist.size())) {
        addItem(QString((*it)->getName().c_str()), y - 1, 0);
        addItem(QString((*it)->getPort().c_str()), y - 1, 1);
        it--;
        y++;
    }
    _table->show();
}

void    MainScreen::repop() {
    this->show();
}

//----------------ADDERS------------------------

void    MainScreen::addButon(int x, int y, const QString &text, int who) {
    void (MainScreen::*ptr[6])(QPushButton *) = {&MainScreen::connectQuit,
            &MainScreen::connectCapture,
            &MainScreen::connectFiltre,
            &MainScreen::connectForge,
            &MainScreen::connectMan,
            &MainScreen::connectModif};
    QPushButton *m_bouton = new QPushButton(text, this);
    QPalette pal = m_bouton->palette();

    m_bouton->setCursor(Qt::PointingHandCursor);
    m_bouton->setGeometry(x, y, 230, 50);
    m_bouton->setFont(QFont("Arial", 25));
    (this->*ptr[who])(m_bouton);
    m_bouton->show();
}

void    MainScreen::addItem(const QString &title, int y, int x) {
    QTableWidgetItem *WItem = new QTableWidgetItem(title);

    _table->setItem(y, x, WItem);
    WItem->setFlags(WItem->flags() & ~Qt::ItemIsEditable);
}

void    MainScreen::addLabel(int x, int y, QString text) {
    QLabel *myLabel = new QLabel(this);
    QPalette pal = myLabel->palette();

    myLabel->move(x, y);
    myLabel->setAutoFillBackground(true);
    myLabel->setText(text);
    myLabel->setPalette(pal);
    myLabel->show();
}

void    MainScreen::addList(int x, int y, std::list <std::string> *lstr) {
    if (this->ifList == NULL) {
        this->ifList = new QListWidget();
        connect(this->ifList, SIGNAL(itemClicked(QListWidgetItem * )), this, SLOT(itemClicked(QListWidgetItem * )));
    }
    else
        this->ifList->clear();
    for (std::string str : *lstr)
        this->ifList->addItem(str.c_str());

    this->ifList->move(x, y);
    this->ifList->show();
}

void MainScreen::itemClicked(QListWidgetItem * item) {
    QMessageBox::information(this, "Hello!", "Capture start on \"" + item->text() + "\"");
    socket.goPromiscious((char *) item->text().toStdString().c_str());

    //TODO : start sniffing

    this->ifList->close();
};

//---------------CONECTORS----------------------

void    MainScreen::connectQuit(QPushButton * bouton) {
    QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(quit()));
}

void    MainScreen::connectCapture(QPushButton * bouton) {
    QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(capture()));
}

void    MainScreen::connectFiltre(QPushButton * bouton) {
    QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(filtring()));
}

void    MainScreen::connectForge(QPushButton * bouton) {
    QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(forging()));
}

void    MainScreen::connectMan(QPushButton * bouton) {
    QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(manInMiddle()));
}

void    MainScreen::connectModif(QPushButton * bouton) {
    QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(modifier()));
}

//--------------SLOTS---------------------------

void    MainScreen::quit() {
    this->close();
}

void    MainScreen::capture() {
    this->addList(800, 200, this->getAllInterfaces());
}

void    MainScreen::filtring() {
    ContentFilter filter;

    filter.showConfig();

    QWidget * w = filter.getWindow();
}

void    MainScreen::forging() {
    this->close();
}

void    MainScreen::manInMiddle() {
    this->close();
}

void    MainScreen::modifier() {
    this->close();
}

void    MainScreen::cellSelected(int nRow, int nCol) {
    (void) nCol;
    int i = 0;

    std::list < Interaction * > liste2 = _mylist;
    liste2.reverse();
    std::list<Interaction *>::const_iterator it(liste2.begin());
    while (i < nRow) {
        it++;
        i++;
    }
    FocusView *focus = new FocusView((*it), this);
    focus->init();
    this->hide();
}
