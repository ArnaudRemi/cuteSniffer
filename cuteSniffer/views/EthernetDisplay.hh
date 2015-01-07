#ifndef ETHERNETDISPLAY_H
#define ETHERNETDISPLAY_H

#include <QObject>
#include <QString>
#include "Ethernet.hh"

class EthernetDisplay : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString dhost READ getDhost WRITE setDhost NOTIFY dhostChanged)
    Q_PROPERTY(QString shost READ getShost WRITE setShost NOTIFY shostChanged)
    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString data READ getData WRITE setData NOTIFY dataChanged)
    Q_PROPERTY(QString dotData READ getDotData WRITE setDotData NOTIFY dotDataChanged)

public:
    EthernetDisplay();
    EthernetDisplay(Ethernet *);
    ~EthernetDisplay();
    QString getDhost() const;
    QString getShost() const;
    QString getType() const;
    QString getData() const;
    QString getDotData() const;
    Ethernet *getPacket() const;
    void setDhost(QString);
    void setShost(QString);
    void setType(QString);
    void setData(QString);
    void setDotData(QString);
    void actualizePacket();

signals:
    void dhostChanged();
    void shostChanged();
    void typeChanged();
    void dataChanged();
    void dotDataChanged();

public slots:
    void sendPacket();

private:
    Ethernet *packet;
    QString shost;
    QString dhost;
    QString type;
    QString dotData;
    QString data;
};

#endif // ETHERNETDISPLAY_H
