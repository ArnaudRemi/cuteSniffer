#ifndef	__FILTER
#define	__FILTER

#include <QObject>
#include "FilterWidget.hh"
#include "Ethernet.hh"

class FilterWidget;

class Filter {

protected:
    FilterWidget *widget;
    bool active;

public:
    virtual bool isValid(Ethernet *packet) = 0;
    virtual void update() = 0;

    void setActive(bool b){
        this->active = b;
    }

    bool isActive() {
        return active;
    }

    FilterWidget *getWidget() const {
        return widget;
    }

};

#endif