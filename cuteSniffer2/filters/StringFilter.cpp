#include "StringFilter.hh"
//#include "StringFilterWidget.hh"

StringFilter::StringFilter(){
    this->active = false;
    this->widget = new StringFilterWidget(this);
}

StringFilter::~StringFilter(){
    delete this->widget;
}

bool StringFilter::isValid(Ethernet *packet){
    char* buffer = packet->getBuffer();
    char* toFind = this->theString->c_str();
    char* found = std::search(buffer, buffer + packet->getBufferSize(), toFind, toFind + strlen(toFind));

    if(found < buffer + packet->getBufferSize())
        return true;
    return false;
}

void StringFilter::update(){
    this->theString = this->widget->getTheString();
    this->active = true;
}