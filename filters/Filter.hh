#ifndef		__FILTER
# define	__FILTER

#include <QObject>
#include "AProtocol.hh"

class Filter : public QObject{

protected:
    QWidget *window;

public:
    virtual bool isValid(AProtocol *packet) = 0; //AProtocol* ou ASubProtocol*
    virtual void showConfig() = 0;

    QWidget *getWindow() const {
        return window;
    }

//public slots:
//    virtual void config() = 0;
};

#endif