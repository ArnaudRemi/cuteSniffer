#ifndef	__STRINGFILTER
#define	__STRINGFILTER

#include "Filter.hh"
#include "Ethernet.hh"
//#include "StringFilterWidget.hh"

class StringFilterWidget;

class StringFilter : public Filter {

std::string theString;

public:
    StringFilter();
    virtual ~StringFilter();

    bool isValid(Ethernet *packet);
    void update();
};

#endif