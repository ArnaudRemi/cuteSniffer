#ifndef __FILTER_DATA__
#define __FILTER_DATA__

#include <QString>
#include <QObject>

class FilterData : public QObject {
    Q_OBJECT

    //Ethernet
    Q_PROPERTY(QString ether_dhost READ getEther_dhost WRITE setEther_dhost NOTIFY ether_dhostChanged)
    Q_PROPERTY(QString ether_shost READ getEther_shost WRITE setEther_shost NOTIFY ether_shostChanged)
    Q_PROPERTY(QString ether_type READ getEther_type WRITE setEther_type NOTIFY ether_typeChanged)
    QString ether_dhost;
    QString ether_shost;
    QString ether_type;

    //ARP
    QString arp_htype;
    QString arp_ptype;
    QString arp_hlen;
    QString arp_plen;
    QString arp_oper;
    QString arp_sha;
    QString arp_spa;
    QString arp_tha;
    QString arp_tpa;

    //IP
    //IPV6
    //ICMP
    //ICMPV6
    //TCP
    //UDP

    FilterData();
    FilterData(const FilterData &);
    static FilterData intance;
public :
    QString getEther_dhost();
    QString getEther_shost();
    QString getEther_type();
    void setEther_dhost(QString const &dhost);
    void setEther_shost(QString const &shost);
    void setEther_type(QString const &type);

    static FilterData &getInstance();

signals:
    void ether_dhostChanged();
    void ether_shostChanged();
    void ether_typeChanged();
};

#endif
