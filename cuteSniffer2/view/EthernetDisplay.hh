#ifndef ETHERNETDISPLAY_H
#define ETHERNETDISPLAY_H

#include <QObject>
#include <QString>
#include "Ethernet.hh"

class EthernetDisplay : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString dhost READ getDhost NOTIFY dhostChanged)
    Q_PROPERTY(QString shost READ getShost NOTIFY shostChanged)
    Q_PROPERTY(QString type READ getType NOTIFY typeChanged)
    Q_PROPERTY(QString data READ getData NOTIFY dataChanged)

public:
    EthernetDisplay();
    EthernetDisplay(Ethernet *);
    ~EthernetDisplay();
    QString getDhost() const;
    QString getShost() const;
    QString getType() const;
    QString getData() const;

signals:
    void dhostChanged();
    void shostChanged();
    void typeChanged();
    void dataChanged();

private:
    Ethernet *paquet;
    QString shost;
    QString dhost;
    QString type;
    QString data;
};

#endif // ETHERNETDISPLAY_H
