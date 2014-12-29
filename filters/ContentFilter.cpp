#include "ContentFilter.hh"

bool ContentFilter::isValid(AProtocol *packet) { //AProtocol* ou ASubProtocol*

    char* buffer = packet->getBuffer();
    char* found = std::search(buffer, buffer + packet->getBufferSize(), this->toFind, this->toFind + strlen(this->toFind));

    if(found < buffer + packet->getBufferSize())
        return true;
    return false;
}

void ContentFilter::showConfig(){
    this->window = new QWidget;
    this->layout = new QVBoxLayout;
    this->text = new QLineEdit;
    this->button1 = new QPushButton("Filtrer");

    QObject::connect(button1, SIGNAL(clicked()), this, SLOT(config()));

    layout->addWidget(text);
    layout->addWidget(button1);
    window->setWindowTitle("Configuration du filtre");
    window->setLayout(layout);
    window->show();
}

void ContentFilter::config(){
    std::cout << "CLOSE" << std::endl;

    this->toFind = (char *) this->text->text().toStdString().c_str();

    this->window->close();
}

