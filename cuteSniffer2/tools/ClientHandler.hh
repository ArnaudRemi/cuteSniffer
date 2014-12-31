/*
 * ClientHandler.hh
 *
 *  Created on: 27 déc. 2014
 *      Author: cursan_a
 */

#ifndef CUTESNIFFER2_TOOLS_CLIENTHANDLER_HH_
#define CUTESNIFFER2_TOOLS_CLIENTHANDLER_HH_

#include <QObject>
#include <QList>
#include <QQmlListProperty>
#include <string>
#include "Client.hh"
#include "Ethernet.hh"
#include "ARP.hpp"
#include "IP.hpp"
#include "IPV6.hpp"

class ClientHandler : public QObject {
private:
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Client> clients READ getClients NOTIFY clientsChanged)
public:
    ClientHandler();
    ClientHandler(ClientHandler const &);
    ClientHandler &operator=(ClientHandler const &);
    ClientHandler(QString const &userMac);
    QQmlListProperty<Client> getClients();
    void addClient(std::string const &mac, bool router);
    void addClient(std::string const &mac, std::string const &ip, bool router);
    void addClient(Ethernet *packet);
	QString getUserMac() const;
    void setUserMac(QString const &userMac);
signals:
    void clientsChanged();

private:
    QList<Client *> clients;
    QString userMac;

};

#endif /* CUTESNIFFER2_TOOLS_CLIENTHANDLER_HH_ */
