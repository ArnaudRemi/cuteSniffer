#ifndef	__FILTERWIDGET
#define	__FILTERWIDGET

#include <QWidget>
//#include "Filter.hh"

class Filter;

class FilterWidget : public QWidget {

protected:
    Filter *filter;

public:
    virtual void startConfig() = 0;
    virtual void endConfig() = 0;

    Filter *getfilter() const {
        return filter;
    }

};

#endif