#ifndef		__CONTENTFILTER
# define	__CONTENTFILTER


#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include	<iostream>

#include "Filter.hh"

class ContentFilter : public Filter{
    Q_OBJECT

    char *toFind;

    QVBoxLayout *layout;
    QLineEdit *text;
    QPushButton *button1;

public:
    bool isValid(AProtocol *packet); //AProtocol* ou ASubProtocol*
    void showConfig();

public slots:
    void config();
};

#endif