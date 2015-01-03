#ifndef __FILTER_DATA__
#define __FILTER_DATA__

#include <QString>
#include <QObject>

class FilterData : public QObject {
	Q_OBJECT

	Q_PROPERTY(QString ether_dhost READ getEtherDhost WRITE setEtherDhost NOTIFY etherDhostChanged)
	Q_PROPERTY(QString ether_shost READ getEtherShost WRITE setEtherShost NOTIFY etherShostChanged)
	Q_PROPERTY(QString ether_type READ getEtherType WRITE setEtherType NOTIFY etherTypeChanged)

    Q_PROPERTY(QString arp_htype READ getArpHtype WRITE setArpHtype NOTIFY arpHtypeChanged)
    Q_PROPERTY(QString arp_ptype READ getArpPtype WRITE setArpPtype NOTIFY arpPtypeChanged)
    Q_PROPERTY(QString arp_hlen READ getArpHlen WRITE setArpHlen NOTIFY arpHlenChanged)
    Q_PROPERTY(QString arp_plen READ getArpPlen WRITE setArpPlen NOTIFY arpPlenChanged)
    Q_PROPERTY(QString arp_oper READ getArpOper WRITE setArpOper NOTIFY arpOperChanged)
    Q_PROPERTY(QString arp_sha READ getArpSha WRITE setArpSha NOTIFY arpShaChanged)
    Q_PROPERTY(QString arp_spa READ getArpSpa WRITE setArpSpa NOTIFY arpSpaChanged)
    Q_PROPERTY(QString arp_tha READ getArpTha WRITE setArpTha NOTIFY arpThaChanged)
    Q_PROPERTY(QString arp_tpa READ getArpTpa WRITE setArpTpa NOTIFY arpTpaChanged)

    Q_PROPERTY(QString ip_vhl READ getIpVhl WRITE setIpVhl NOTIFY ipVhlChanged)
    Q_PROPERTY(QString ip_tos READ getIpTos WRITE setIpTos NOTIFY ipTosChanged)
    Q_PROPERTY(QString ip_len READ getIpLen WRITE setIpLen NOTIFY ipLenChanged)
    Q_PROPERTY(QString ip_id READ getIpId WRITE setIpId NOTIFY ipIdChanged)
    Q_PROPERTY(QString ip_off READ getIpOff WRITE setIpOff NOTIFY ipOffChanged)
    Q_PROPERTY(QString ip_ttl READ getIpTtl WRITE setIpTtl NOTIFY ipTtlChanged)
    Q_PROPERTY(QString ip_p READ getIpP WRITE setIpP NOTIFY ipPChanged)
    Q_PROPERTY(QString ip_sum READ getIpSum WRITE setIpSum NOTIFY ipSumChanged)
    Q_PROPERTY(QString ip_src READ getIpSrc WRITE setIpSrc NOTIFY ipSrcChanged)
    Q_PROPERTY(QString ip_dst READ getIpDst WRITE setIpDst NOTIFY ipDstChanged)

    Q_PROPERTY(QString ipv6_flow READ getIpv6Flow WRITE setIpv6Flow NOTIFY ipv6FlowChanged)
    Q_PROPERTY(QString ipv6_plen READ getIpv6Plen WRITE setIpv6Plen NOTIFY ipv6PlenChanged)
    Q_PROPERTY(QString ipv6_next_head READ getIpv6NextHead WRITE setIpv6NextHead NOTIFY ipv6NextHeadChanged)
    Q_PROPERTY(QString ipv6_un2_vfc READ getIpv6Un2Vfc WRITE setIpv6Un2Vfc NOTIFY ipv6Un2VfcChanged)
    Q_PROPERTY(QString ipv6_src READ getIpv6Src WRITE setIpv6Src NOTIFY ipv6SrcChanged)
    Q_PROPERTY(QString ipv6_dest READ getIpv6Dest WRITE setIpv6Dest NOTIFY ipv6DestChanged)

    Q_PROPERTY(QString icmp_type READ getIcmpType WRITE setIcmpType NOTIFY icmpTypeChanged)
    Q_PROPERTY(QString icmp_code READ getIcmpCode WRITE setIcmpCode NOTIFY icmpCodeChanged)
    Q_PROPERTY(QString icmp_checksum READ getIcmpChecksum WRITE setIcmpChecksum NOTIFY icmpChecksumChanged)
    Q_PROPERTY(QString icmp_gateway READ getIcmpGateway WRITE setIcmpGateway NOTIFY icmpGatewayChanged)

    Q_PROPERTY(QString icmpv6_type READ getIcmpv6Type WRITE setIcmpv6Type NOTIFY icmpv6TypeChanged)
    Q_PROPERTY(QString icmpv6_code READ getIcmpv6Code WRITE setIcmpv6Code NOTIFY icmpv6CodeChanged)
    Q_PROPERTY(QString icmpv6_checksum READ getIcmpv6Checksum WRITE setIcmpv6Checksum NOTIFY icmpv6ChecksumChanged)

    Q_PROPERTY(QString tcp_sport READ getTcpSport WRITE setTcpSport NOTIFY tcpSportChanged)
    Q_PROPERTY(QString tcp_dport READ getTcpDport WRITE setTcpDport NOTIFY tcpDportChanged)
    Q_PROPERTY(QString tcp_seq READ getTcpSeq WRITE setTcpSeq NOTIFY tcpSeqChanged)
    Q_PROPERTY(QString tcp_ack READ getTcpAck WRITE setTcpAck NOTIFY tcpAckChanged)
    Q_PROPERTY(QString tcp_off READ getTcpOff WRITE setTcpOff NOTIFY tcpOffChanged)
    Q_PROPERTY(QString tcp_flags READ getTcpFlags WRITE setTcpFlags NOTIFY tcpFlagsChanged)
    Q_PROPERTY(QString tcp_win READ getTcpWin WRITE setTcpWin NOTIFY tcpWinChanged)
    Q_PROPERTY(QString tcp_sum READ getTcpSum WRITE setTcpSum NOTIFY tcpSumChanged)
    Q_PROPERTY(QString tcp_urp READ getTcpUrp WRITE setTcpUrp NOTIFY tcpUrpChanged)

    Q_PROPERTY(QString udp_srcport READ getUdpSrcport WRITE setUdpSrcport NOTIFY udpSrcportChanged)
    Q_PROPERTY(QString udp_destport READ getUdpDestport WRITE setUdpDestport NOTIFY udpDestportChanged)
    Q_PROPERTY(QString udp_len READ getUdpLen WRITE setUdpLen NOTIFY udpLenChanged)
    Q_PROPERTY(QString udp_chksum READ getUdpChksum WRITE setUdpChksum NOTIFY udpChksumChanged)

	//Ethernet
	QString ether_dhost;
	QString ether_shost;
	QString ether_type;
	char etherFlag;
#define ETHER_DHOST 1
#define ETHER_SHOST 2
#define ETHER_TYPE 4

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
	short arpFlag;
#define ARP_HTYPE 1
#define ARP_PTYPE 2
#define ARP_HLEN 4
#define ARP_PLEN 8
#define ARP_OPER 16
#define ARP_SHA 32
#define ARP_SPA 64
#define ARP_THA 128
#define ARP_TPA 256

	//IP
	QString ip_vhl;
	QString ip_tos;
	QString ip_len;
	QString ip_id;
	QString ip_off;
	QString ip_ttl;
	QString ip_p;
	QString ip_sum;
	QString ip_src;
	QString ip_dst;
	short ipFlag;
#define IP_VHL 1
#define IP_TOS_ 2
#define IP_LEN 4
#define IP_ID 8
#define IP_OFF 16
#define IP_TTL_ 32
#define IP_P 64
#define IP_SUM 128
#define IP_SRC 256
#define IP_DST 512

	//IPV6
	QString ipv6_flow;
	QString ipv6_plen;
	QString ipv6_next_head;
	QString ipv6_un2_vfc;
	QString ipv6_src;
	QString ipv6_dest;
	char ipv6Flag;
#define IPV6_FLOW 1
#define IPV6_PLEN 2
#define IPV6_NEXT_HEAD 4
#define IPV6_UN2_VFC 8
#define IPV6_SRC 16
#define IPV6_DEST 32

	//ICMP
	QString icmp_type;
	QString icmp_code;
	QString icmp_checksum;
	QString icmp_gateway;
	char icmpFlag;
#define ICMP_TYPE 1
#define ICMP_CODE 2
#define ICMP_CHECKSUM 4
#define ICMP_GATEWAY 8

	//ICMPV6
	QString icmpv6_type;
	QString icmpv6_code;
	QString icmpv6_checksum;
	char icmpv6Flag;
#define ICMPV6_TYPE 1
#define ICMPV6_CODE 2
#define ICMPV6_CHECKSUM 4

	//TCP
	QString tcp_sport;
	QString tcp_dport;
	QString tcp_seq;
	QString tcp_ack;
	QString tcp_off;
	QString tcp_flags;
	QString tcp_win;
	QString tcp_sum;
	QString tcp_urp;
	short tcpFlag;
#define TCP_SPORT 1
#define TCP_DPORT 2
#define TCP_SEQ 4
#define TCP_ACK 8
#define TCP_OFF 16
#define TCP_FLAGS 32
#define TCP_WIN 64
#define TCP_SUM 128
#define TCP_URP 256

	//UDP
	QString udp_srcport;
	QString udp_destport;
	QString udp_len;
	QString udp_chksum;
	char udpFlag;
#define UDP_SRCPORT 1
#define UDP_DESTPORT 2
#define UDP_LEN 4
#define UDP_CHKSUM 8

	FilterData();
	FilterData(const FilterData &);
	static FilterData intance;
public :

	QString getEtherDhost() const;
	void setEtherDhost(QString etherDhost);
	QString getEtherShost() const;
	void setEtherShost(QString etherShost);
	QString getEtherType() const;
	void setEtherType(QString etherType);
	char getEtherFlag() const;

	QString getArpHlen() const;
	void setArpHlen(QString arpHlen);
	QString getArpHtype() const;
	void setArpHtype(QString arpHtype);
	QString getArpOper() const;
	void setArpOper(QString arpOper);
	QString getArpPlen() const;
	void setArpPlen(QString arpPlen);
	QString getArpPtype() const;
	void setArpPtype(QString arpPtype);
	QString getArpSha() const;
	void setArpSha(QString arpSha);
	QString getArpSpa() const;
	void setArpSpa(QString arpSpa);
	QString getArpTha() const;
	void setArpTha(QString arpTha);
	QString getArpTpa() const;
	void setArpTpa(QString arpTpa);
	short getArpFlag() const;

	QString getIpDst() const;
	void setIpDst(QString ipDst);
	QString getIpId() const;
	void setIpId(QString ipId);
	QString getIpLen() const;
	void setIpLen(QString ipLen);
	QString getIpOff() const;
	void setIpOff(QString ipOff);
	QString getIpP() const;
	void setIpP(QString ipP);
	QString getIpSrc() const;
	void setIpSrc(QString ipSrc);
	QString getIpSum() const;
	void setIpSum(QString ipSum);
	QString getIpTos() const;
	void setIpTos(QString ipTos);
	QString getIpTtl() const;
	void setIpTtl(QString ipTtl);
	QString getIpVhl() const;
	void setIpVhl(QString ipVhl);
	short getIpFlag() const;

	QString getIpv6Dest() const;
	void setIpv6Dest(QString ipv6Dest);
	QString getIpv6Flow() const;
	void setIpv6Flow(QString ipv6Flow);
	QString getIpv6NextHead() const;
	void setIpv6NextHead(QString ipv6NextHead);
	QString getIpv6Plen() const;
	void setIpv6Plen(QString ipv6Plen);
	QString getIpv6Src() const;
	void setIpv6Src(QString ipv6Src);
	QString getIpv6Un2Vfc() const;
	void setIpv6Un2Vfc(QString ipv6Un2Vfc);
	char getIpv6Flag() const;

	QString getIcmpChecksum() const;
	void setIcmpChecksum(QString icmpChecksum);
	QString getIcmpCode() const;
	void setIcmpCode(QString icmpCode);
	QString getIcmpGateway() const;
	void setIcmpGateway(QString icmpGateway);
	QString getIcmpType() const;
	void setIcmpType(QString icmpType);
	char getIcmpFlag() const;

	QString getIcmpv6Checksum() const;
	void setIcmpv6Checksum(QString icmpv6Checksum);
	QString getIcmpv6Code() const;
	void setIcmpv6Code(QString icmpv6Code);
	QString getIcmpv6Type() const;
	void setIcmpv6Type(QString icmpv6Type);
	char getIcmpv6Flag() const;

	QString getTcpAck() const;
	void setTcpAck(QString tcpAck);
	QString getTcpDport() const;
	void setTcpDport(QString tcpDport);
	QString getTcpFlags() const;
	void setTcpFlags(QString tcpFlags);
	QString getTcpOff() const;
	void setTcpOff(QString tcpOff);
	QString getTcpSeq() const;
	void setTcpSeq(QString tcpSeq);
	QString getTcpSport() const;
	void setTcpSport(QString tcpSport);
	QString getTcpSum() const;
	void setTcpSum(QString tcpSum);
	QString getTcpUrp() const;
	void setTcpUrp(QString tcpUrp);
	QString getTcpWin() const;
	void setTcpWin(QString tcpWin);
	short getTcpFlag() const;

	QString getUdpChksum() const;
	void setUdpChksum(QString udpChksum);
	QString getUdpDestport() const;
	void setUdpDestport(QString udpDestport);
	QString getUdpLen() const;
	void setUdpLen(QString udpLen);
	QString getUdpSrcport() const;
	void setUdpSrcport(QString udpSrcport);
	char getUdpFlag() const;

	static FilterData &getInstance();

    signals:
    void etherDhostChanged();
    void etherShostChanged();
    void etherTypeChanged();

    void arpHtypeChanged();
    void arpPtypeChanged();
    void arpHlenChanged();
    void arpPlenChanged();
    void arpOperChanged();
    void arpShaChanged();
    void arpSpaChanged();
    void arpThaChanged();
    void arpTpaChanged();

    void ipVhlChanged();
    void ipTosChanged();
    void ipLenChanged();
    void ipIdChanged();
    void ipOffChanged();
    void ipTtlChanged();
    void ipPChanged();
    void ipSumChanged();
    void ipSrcChanged();
    void ipDstChanged();

    void ipv6FlowChanged();
    void ipv6PlenChanged();
    void ipv6NextHeadChanged();
    void ipv6Un2VfcChanged();
    void ipv6SrcChanged();
    void ipv6DestChanged();

    void icmpTypeChanged();
    void icmpCodeChanged();
    void icmpChecksumChanged();
    void icmpGatewayChanged();

    void icmpv6TypeChanged();
    void icmpv6CodeChanged();
    void icmpv6ChecksumChanged();

    void tcpSportChanged();
    void tcpDportChanged();
    void tcpSeqChanged();
    void tcpAckChanged();
    void tcpOffChanged();
    void tcpFlagsChanged();
    void tcpWinChanged();
    void tcpSumChanged();
    void tcpUrpChanged();

    void udpSrcportChanged();
    void udpDestportChanged();
    void udpLenChanged();
    void udpChksumChanged();
};

#endif
