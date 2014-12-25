/*
 * AProtocol.cpp
 *
 *  Created on: 8 déc. 2014
 *      Author: cursan_a
 */

#include "AProtocol.hh"


std::ostream& operator <<(std::ostream& stream, AProtocol &p)
{
    stream << p.toString();
    return stream;
}


