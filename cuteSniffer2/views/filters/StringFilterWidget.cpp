#include "StringFilterWidget.hh"
//#include "StringFilter.hh"
//#include "Filter.hh"

StringFilterWidget::StringFilterWidget(StringFilter *stringfilter){
    this->filter = stringfilter;
}

StringFilterWidget::~StringFilterWidget(){}

void StringFilterWidget::startConfig(){
    this->layout = new QVBoxLayout;
    this->text = new QLineEdit;
    this->button = new QPushButton("Filtrer");

    QObject::connect(button, SIGNAL(clicked()), this, SLOT(endConfig()));

    layout->addWidget(text);
    layout->addWidget(button);
    this->setWindowTitle("Configuration du filtre");
    this->setLayout(layout);
    this->show();
}

void StringFilterWidget::endConfig(){
    this->filter->update();
    this->close();
}

std::string StringFilterWidget::getTheString(){
    return this->text->text().toStdString();
}