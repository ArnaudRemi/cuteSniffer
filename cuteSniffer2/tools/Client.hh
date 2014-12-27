/*
 * Client.hh
 *
 *  Created on: 27 déc. 2014
 *      Author: cursan_a
 */

#ifndef CUTESNIFFER2_TOOLS_CLIENT_HH_
#define CUTESNIFFER2_TOOLS_CLIENT_HH_

#include <QObject>
#include <QString>

class Client : public QObject {
	Q_OBJECT

    private:
	QString mac;

};

#endif /* CUTESNIFFER2_TOOLS_CLIENT_HH_ */
