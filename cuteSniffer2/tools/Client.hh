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

    Q_PROPERTY(QString ip READ getIp WRITE setIp NOTIFY ipChanged)
    Q_PROPERTY(QString mac READ getMac WRITE setMac NOTIFY macChanged)
    Q_PROPERTY(bool router READ isRouter WRITE setRouter NOTIFY routerChanged)
    private:
	QString mac;
	QString ip;
    bool router;

    public:
    Client();
    Client(QString const &mac);
    Client(QString const &mac, QString const &ip);
    Client(QString const &mac, bool router);
    Client(QString const &mac, QString const &ip, bool router);

	QString getIp() const;
	void setIp(QString ip);
	QString getMac() const;
	void setMac(QString mac);
    bool isRouter() const;
    void setRouter(bool router);

    signals:
    void ipChanged();
    void macChanged();
    void routerChanged();
};

#endif /* CUTESNIFFER2_TOOLS_CLIENT_HH_ */
