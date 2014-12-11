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

MainScreen::MainScreen(QWidget *parent)
{
  Interaction *n1 = new Interaction("n1", "p1");
  Interaction *n2 = new Interaction("n2", "p2");
  Interaction *n3 = new Interaction("n3", "p3");
  Interaction *n4 = new Interaction("n4", "p4");
  
  _mylist.push_front(n1);
  _mylist.push_front(n2);
  _mylist.push_front(n3);
  _mylist.push_front(n4);

  this->init();
}

void	MainScreen::init()
{
  this->setFixedSize(1200, 780);
  this->addButon(900,100, "quiter", MainScreen::Quit);
  this->addButon(900,200, "Capturer", MainScreen::Capture);
  this->addButon(900,300, "Filtrer", MainScreen::Filtre);
  this->addButon(900,400, "Forger", MainScreen::Forge);
  this->addButon(900,500, "Man in the middle", MainScreen::Man);
  this->addButon(900,600, "Modifier", MainScreen::Modif);
  this->_table = new QTableWidget(this);
  _table->setGeometry(10,10,300,300);
  _table->setColumnCount(2);
  connect(_table, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(cellSelected(int, int)));
  this->fillInfo();
  this->show();
}

void	MainScreen::fillInfo()
{
  int	y;
  std::list<Interaction *>::const_iterator it(_mylist.begin());

  _table->setRowCount(this->_mylist.size());
  //_table->setHorizontalHeaderLabels(_tableHeader);
  y = 1;
  while (it != _mylist.end())
    it++;
  it--;
  while (y <= (this->_mylist.size()))
    {
      addItem(QString((*it)->getName().c_str()), y - 1, 0);
      addItem(QString((*it)->getPort().c_str()), y - 1, 1);
      it--;
      y++;
    }
  _table->show();
}

void	MainScreen::repop()
{
  this->show();
}

//----------------ADDERS------------------------

void	MainScreen::addButon(int x, int y, const QString & text, int who)
{
  void (MainScreen::*ptr[6])(QPushButton *) = { &MainScreen::connectQuit,
						&MainScreen::connectCapture,
						&MainScreen::connectFiltre,
						&MainScreen::connectForge,
						&MainScreen::connectMan,
						&MainScreen::connectModif};
  QPushButton	*m_bouton	=	new QPushButton(text, this);
  QPalette	pal		=	m_bouton->palette();

  m_bouton->setCursor(Qt::PointingHandCursor);
  m_bouton->setGeometry(x, y, 230, 50);
  m_bouton->setFont(QFont("Arial", 25));
  (this->*ptr[who])(m_bouton);
  m_bouton->show();
}

void	MainScreen::addItem(const QString &title, int y, int x)
{
  QTableWidgetItem	*WItem = new QTableWidgetItem(title);

  _table->setItem(y, x, WItem);
  WItem->setFlags(WItem->flags() & ~Qt::ItemIsEditable);
 }

void	MainScreen::addLabel(int x, int y, QString text)
{
  QLabel	*myLabel	= new QLabel(this);
  QPalette	pal		= myLabel->palette();

  myLabel->move(x, y);
  myLabel->setAutoFillBackground(true);
  myLabel->setText(text);
  myLabel->setPalette(pal);
  myLabel->show();
}


 //---------------CONECTORS----------------------

void	MainScreen::connectQuit(QPushButton * bouton)
{
  QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(quit()));
}

void	MainScreen::connectCapture(QPushButton * bouton)
{
  QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(capture()));
}

void	MainScreen::connectFiltre(QPushButton * bouton)
{
  QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(filtring()));
}

void	MainScreen::connectForge(QPushButton * bouton)
{
  QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(forging()));
}

void	MainScreen::connectMan(QPushButton * bouton)
{
  QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(manInMiddle()));
}

void	MainScreen::connectModif(QPushButton * bouton)
{
 QObject::connect(bouton, SIGNAL(clicked()), this, SLOT(modifier()));
}

 //--------------SLOTS---------------------------

void	MainScreen::quit()
{
  this->close();
}

void	MainScreen::capture()
{
  this->close();
}

void	MainScreen::filtring()
{
  this->close();
}

void	MainScreen::forging()
{
  this->close();
}

void	MainScreen::manInMiddle()
{
  this->close();
}

void	MainScreen::modifier()
{
  this->close();
}

void	MainScreen::cellSelected(int nRow, int nCol)
{
  (void) nCol;
  int i = 0;
 
  std::list<Interaction*> liste2 = _mylist;
  liste2.reverse();
  std::list<Interaction*>::const_iterator it(liste2.begin());
  while (i < nRow)
    {
      it++;
      i++;
    }
  FocusView* focus = new FocusView((*it), this);
  focus->init();
  this->hide();
}
