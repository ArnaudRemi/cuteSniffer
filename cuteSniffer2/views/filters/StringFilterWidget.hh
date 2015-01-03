#ifndef		__FILTER
# define	__FILTER

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <iostream>
#include "FilterWidget.hh"
#include "StringFilter.hh"
#include "Ethernet.hh"

class StringFilterWidget : public FilterWidget {

    QVBoxLayout *layout;
    QLineEdit *text;
    QPushButton *button;

public:
    StringFilterWidget(StringFilter *);
    virtual ~StringFilterWidget();

    void startConfig();
    void endConfig();

    std::string getTheString();
};

#endif