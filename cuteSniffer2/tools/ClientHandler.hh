/*
 * ClientHandler.hh
 *
 *  Created on: 27 déc. 2014
 *      Author: cursan_a
 */

#ifndef CUTESNIFFER2_TOOLS_CLIENTHANDLER_HH_
#define CUTESNIFFER2_TOOLS_CLIENTHANDLER_HH_

#include <QObject>


class ClientHandler : public QObject {
    Q_OBJECT

private:
    ClientHandler();
public:
    static ClientHandler &getInstance();
    static ClientHandler instance;

signals:

private:
    // QList

public:
};

#endif /* CUTESNIFFER2_TOOLS_CLIENTHANDLER_HH_ */
