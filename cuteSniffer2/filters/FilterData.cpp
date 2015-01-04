#include "FilterData.hh"


FilterData::FilterData() {

}

FilterData::FilterData(const FilterData &) : QObject(0) {

}

FilterData FilterData::intance = FilterData();

FilterData &FilterData::getInstance() {
    return intance;
}

// A R P

QString FilterData::getArpHlen() const {
	return arp_hlen;
}

void FilterData::setArpHlen(QString arpHlen) {
	arp_hlen = arpHlen;
    if (arp_hlen.isEmpty())
        arpFlag &= ~ARP_HLEN;
    else
        arpFlag |= ARP_HLEN;
    emit arpHlenChanged();
}

QString FilterData::getArpHtype() const {
	return arp_htype;
}

void FilterData::setArpHtype(QString arpHtype) {
	arp_htype = arpHtype;
    if (arp_htype.isEmpty())
        arpFlag &= ~ARP_HTYPE;
    else
        arpFlag |= ARP_HTYPE;
    emit arpHtypeChanged();
}

QString FilterData::getArpOper() const {
	return arp_oper;
}

void FilterData::setArpOper(QString arpOper) {
	arp_oper = arpOper;
    if (arp_oper.isEmpty())
        arpFlag &= ~ARP_OPER;
    else
        arpFlag |= ARP_OPER;
    emit arpOperChanged();
}

QString FilterData::getArpPlen() const {
	return arp_plen;
}

void FilterData::setArpPlen(QString arpPlen) {
	arp_plen = arpPlen;
    if (arp_plen.isEmpty())
        arpFlag &= ~ARP_PLEN;
    else
        arpFlag |= ARP_PLEN;
    emit arpPlenChanged();
}

QString FilterData::getArpPtype() const {
	return arp_ptype;
}

void FilterData::setArpPtype(QString arpPtype) {
	arp_ptype = arpPtype;
    if (arp_ptype.isEmpty())
        arpFlag &= ~ARP_PTYPE;
    else
        arpFlag |= ARP_PTYPE;
    emit arpPtypeChanged();
}

QString FilterData::getArpSha() const {
	return arp_sha;
}

void FilterData::setArpSha(QString arpSha) {
	arp_sha = arpSha;
    if (arp_sha.isEmpty())
        arpFlag &= ~ARP_SHA;
    else
        arpFlag |= ARP_SHA;
    emit arpShaChanged();
}

QString FilterData::getArpSpa() const {
	return arp_spa;
}

void FilterData::setArpSpa(QString arpSpa) {
	arp_spa = arpSpa;
    if (arp_spa.isEmpty())
        arpFlag &= ~ARP_SPA;
    else
        arpFlag |= ARP_SPA;
    emit arpSpaChanged();
}

QString FilterData::getArpTha() const {
	return arp_tha;
}

void FilterData::setArpTha(QString arpTha) {
	arp_tha = arpTha;
    if (arp_tha.isEmpty())
        arpFlag &= ~ARP_THA;
    else
        arpFlag |= ARP_THA;
    emit arpThaChanged();
}

QString FilterData::getArpTpa() const {
	return arp_tpa;
}

void FilterData::setArpTpa(QString arpTpa) {
	arp_tpa = arpTpa;
    if (arp_tpa.isEmpty())
        arpFlag &= ~ARP_TPA;
    else
        arpFlag |= ARP_TPA;
    emit arpTpaChanged();
}

short FilterData::getArpFlag() const {
	return arpFlag;
}

// E T H E R N E T

QString FilterData::getEtherDhost() const {
	return ether_dhost;
}

void FilterData::setEtherDhost(QString etherDhost) {
	ether_dhost = etherDhost;
    if (ether_dhost.isEmpty())
        etherFlag &= ~ETHER_DHOST;
    else
        etherFlag |= ETHER_DHOST;
    emit etherDhostChanged();
}

QString FilterData::getEtherShost() const {
	return ether_shost;
}

void FilterData::setEtherShost(QString etherShost) {
    ether_shost = etherShost;
    if (ether_shost.isEmpty())
        etherFlag &= ~ETHER_SHOST;
    else
        etherFlag |= ETHER_SHOST;
    emit etherShostChanged();
}

QString FilterData::getEtherType() const {
	return ether_type;
}

void FilterData::setEtherType(QString etherType) {
    ether_type = etherType;
    if (ether_type.isEmpty())
        etherFlag &= ~ETHER_TYPE;
    else
        etherFlag |= ETHER_TYPE;
    emit etherTypeChanged();
}

char FilterData::getEtherFlag() const {
	return etherFlag;
}

// I P

QString FilterData::getIpDst() const {
	return ip_dst;
}

void FilterData::setIpDst(QString ipDst) {
	ip_dst = ipDst;
    if (ip_dst.isEmpty())
        ipFlag &= ~IP_DST;
    else
        ipFlag |= IP_DST;
    emit ipDstChanged();
}

QString FilterData::getIpId() const {
	return ip_id;
}

void FilterData::setIpId(QString ipId) {
	ip_id = ipId;
    if (ip_id.isEmpty())
        ipFlag &= ~IP_ID;
    else
        ipFlag |= IP_ID;
    emit ipIdChanged();
}

QString FilterData::getIpLen() const {
	return ip_len;
}

void FilterData::setIpLen(QString ipLen) {
	ip_len = ipLen;
    if (ip_len.isEmpty())
        ipFlag &= ~IP_LEN;
    else
        ipFlag |= IP_LEN;
    emit ipLenChanged();
}

QString FilterData::getIpOff() const {
	return ip_off;
}

void FilterData::setIpOff(QString ipOff) {
	ip_off = ipOff;
    if (ip_off.isEmpty())
        ipFlag &= ~IP_OFF;
    else
        ipFlag |= IP_OFF;
    emit ipOffChanged();
}

QString FilterData::getIpP() const {
	return ip_p;
}

void FilterData::setIpP(QString ipP) {
	ip_p = ipP;
    if (ip_p.isEmpty())
        ipFlag &= ~IP_P;
    else
        ipFlag |= IP_P;
    emit ipPChanged();
}

QString FilterData::getIpSrc() const {
	return ip_src;
}

void FilterData::setIpSrc(QString ipSrc) {
	ip_src = ipSrc;
    if (ip_src.isEmpty())
        ipFlag &= ~IP_SRC;
    else
        ipFlag |= IP_SRC;
    emit ipSrcChanged();
}

QString FilterData::getIpSum() const {
	return ip_sum;
}

void FilterData::setIpSum(QString ipSum) {
	ip_sum = ipSum;
    if (ip_sum.isEmpty())
        ipFlag &= ~IP_SUM;
    else
        ipFlag |= IP_SUM;
    emit ipSumChanged();
}

QString FilterData::getIpTos() const {
	return ip_tos;
}

void FilterData::setIpTos(QString ipTos) {
	ip_tos = ipTos;
    if (ip_tos.isEmpty())
        ipFlag &= ~IP_TOS_;
    else
        ipFlag |= IP_TOS_;
    emit ipTosChanged();
}

QString FilterData::getIpTtl() const {
	return ip_ttl;
}

void FilterData::setIpTtl(QString ipTtl) {
	ip_ttl = ipTtl;
    if (ip_ttl.isEmpty())
        ipFlag &= ~IP_TTL_;
    else
        ipFlag |= IP_TTL_;
    emit ipTtlChanged();
}

QString FilterData::getIpVhl() const {
	return ip_vhl;
}

void FilterData::setIpVhl(QString ipVhl) {
	ip_vhl = ipVhl;
    if (ip_vhl.isEmpty())
        ipFlag &= ~IP_VHL;
    else
        ipFlag |= IP_VHL;
    emit ipVhlChanged();
}

short FilterData::getIpFlag() const {
	return ipFlag;
}

// I P V 6

QString FilterData::getIpv6Dest() const {
	return ipv6_dest;
}

void FilterData::setIpv6Dest(QString ipv6Dest) {
	ipv6_dest = ipv6Dest;
    if (ipv6_dest.isEmpty())
        ipv6Flag &= ~IPV6_DEST;
    else
        ipv6Flag |= IPV6_DEST;
    emit ipv6DestChanged();
}

QString FilterData::getIpv6Flow() const {
	return ipv6_flow;
}

void FilterData::setIpv6Flow(QString ipv6Flow) {
	ipv6_flow = ipv6Flow;
    if (ipv6_flow.isEmpty())
        ipv6Flag &= ~IPV6_FLOW;
    else
        ipv6Flag |= IPV6_FLOW;
    emit ipv6FlowChanged();
}

QString FilterData::getIpv6NextHead() const {
	return ipv6_next_head;
}

void FilterData::setIpv6NextHead(QString ipv6NextHead) {
	ipv6_next_head = ipv6NextHead;
    if (ipv6_next_head.isEmpty())
        ipv6Flag &= ~IPV6_NEXT_HEAD;
    else
        ipv6Flag |= IPV6_NEXT_HEAD;
    emit ipv6NextHeadChanged();
}

QString FilterData::getIpv6Plen() const {
	return ipv6_plen;
}

void FilterData::setIpv6Plen(QString ipv6Plen) {
	ipv6_plen = ipv6Plen;
    if (ipv6_plen.isEmpty())
        ipv6Flag &= ~IPV6_PLEN;
    else
        ipv6Flag |= IPV6_PLEN;
    emit ipv6PlenChanged();
}

QString FilterData::getIpv6Src() const {
	return ipv6_src;
}

void FilterData::setIpv6Src(QString ipv6Src) {
	ipv6_src = ipv6Src;
    if (ipv6_src.isEmpty())
        ipv6Flag &= ~IPV6_SRC;
    else
        ipv6Flag |= IPV6_SRC;
    emit ipv6SrcChanged();
}

QString FilterData::getIpv6Un2Vfc() const {
	return ipv6_un2_vfc;
}

void FilterData::setIpv6Un2Vfc(QString ipv6Un2Vfc) {
	ipv6_un2_vfc = ipv6Un2Vfc;
    if (ipv6_un2_vfc.isEmpty())
        ipv6Flag &= ~IPV6_UN2_VFC;
    else
        ipv6Flag |= IPV6_UN2_VFC;
    emit ipv6Un2VfcChanged();
}

char FilterData::getIpv6Flag() const {
	return ipv6Flag;
}

// I C M P

QString FilterData::getIcmpChecksum() const {
	return icmp_checksum;
}

void FilterData::setIcmpChecksum(QString icmpChecksum) {
	icmp_checksum = icmpChecksum;
    if (icmp_checksum.isEmpty())
        icmpFlag &= ~ICMP_CHECKSUM;
    else
        icmpFlag |= ICMP_CHECKSUM;
    emit icmpChecksumChanged();
}

QString FilterData::getIcmpCode() const {
	return icmp_code;
}

void FilterData::setIcmpCode(QString icmpCode) {
	icmp_code = icmpCode;
    if (icmp_code.isEmpty())
        icmpFlag &= ~ICMP_CODE;
    else
        icmpFlag |= ICMP_CODE;
    emit icmpCodeChanged();
}

QString FilterData::getIcmpGateway() const {
	return icmp_gateway;
}

void FilterData::setIcmpGateway(QString icmpGateway) {
	icmp_gateway = icmpGateway;
    if (icmp_gateway.isEmpty())
        icmpFlag &= ~ICMP_GATEWAY;
    else
        icmpFlag |= ICMP_GATEWAY;
    emit icmpGatewayChanged();
}

QString FilterData::getIcmpType() const {
	return icmp_type;
}

void FilterData::setIcmpType(QString icmpType) {
	icmp_type = icmpType;
    if (icmp_type.isEmpty())
        icmpFlag &= ~ICMP_TYPE;
    else
        icmpFlag |= ICMP_TYPE;
    emit icmpTypeChanged();
}

char FilterData::getIcmpFlag() const {
	return icmpFlag;
}

// I C M P V 6

QString FilterData::getIcmpv6Checksum() const {
	return icmpv6_checksum;
}

void FilterData::setIcmpv6Checksum(QString icmpv6Checksum) {
	icmpv6_checksum = icmpv6Checksum;
    if (icmpv6_checksum.isEmpty())
        icmpv6Flag &= ~ICMPV6_CHECKSUM;
    else
        icmpv6Flag |= ICMPV6_CHECKSUM;
    emit icmpv6ChecksumChanged();
}

QString FilterData::getIcmpv6Code() const {
	return icmpv6_code;
}

void FilterData::setIcmpv6Code(QString icmpv6Code) {
	icmpv6_code = icmpv6Code;
    if (icmpv6_code.isEmpty())
        icmpv6Flag &= ~ICMPV6_CODE;
    else
        icmpv6Flag |= ICMPV6_CODE;
    emit icmpv6CodeChanged();
}

QString FilterData::getIcmpv6Type() const {
	return icmpv6_type;
}

void FilterData::setIcmpv6Type(QString icmpv6Type) {
	icmpv6_type = icmpv6Type;
    if (icmpv6_type.isEmpty())
        icmpv6Flag &= ~ICMPV6_TYPE;
    else
        icmpv6Flag |= ICMPV6_TYPE;
    emit icmpv6TypeChanged();
}

char FilterData::getIcmpv6Flag() const {
	return icmpv6Flag;
}


// T C P

QString FilterData::getTcpAck() const {
	return tcp_ack;
}

void FilterData::setTcpAck(QString tcpAck) {
	tcp_ack = tcpAck;
    if (tcp_ack.isEmpty())
        tcpFlag &= ~TCP_ACK;
    else
        tcpFlag |= TCP_ACK;
    emit tcpAckChanged();
}

QString FilterData::getTcpDport() const {
	return tcp_dport;
}

void FilterData::setTcpDport(QString tcpDport) {
	tcp_dport = tcpDport;
    if (tcp_dport.isEmpty())
        tcpFlag &= ~TCP_DPORT;
    else
        tcpFlag |= TCP_DPORT;
    emit tcpDportChanged();
}

QString FilterData::getTcpFlags() const {
	return tcp_flags;
}

void FilterData::setTcpFlags(QString tcpFlags) {
	tcp_flags = tcpFlags;
    if (tcp_flags.isEmpty())
        tcpFlag &= ~TCP_FLAGS;
    else
        tcpFlag |= TCP_FLAGS;
    emit tcpFlagsChanged();
}

QString FilterData::getTcpOff() const {
	return tcp_off;
}

void FilterData::setTcpOff(QString tcpOff) {
	tcp_off = tcpOff;
    if (tcp_off.isEmpty())
        tcpFlag &= ~TCP_OFF;
    else
        tcpFlag |= TCP_OFF;
    emit tcpOffChanged();
}

QString FilterData::getTcpSeq() const {
	return tcp_seq;
}

void FilterData::setTcpSeq(QString tcpSeq) {
	tcp_seq = tcpSeq;
    if (tcp_seq.isEmpty())
        tcpFlag &= ~TCP_SEQ;
    else
        tcpFlag |= TCP_SEQ;
    emit tcpSeqChanged();
}

QString FilterData::getTcpSport() const {
	return tcp_sport;
}

void FilterData::setTcpSport(QString tcpSport) {
	tcp_sport = tcpSport;
    if (tcp_sport.isEmpty())
        tcpFlag &= ~TCP_SPORT;
    else
        tcpFlag |= TCP_SPORT;
    emit tcpSportChanged();
}

QString FilterData::getTcpSum() const {
	return tcp_sum;
}

void FilterData::setTcpSum(QString tcpSum) {
	tcp_sum = tcpSum;
    if (tcp_sum.isEmpty())
        tcpFlag &= ~TCP_SUM;
    else
        tcpFlag |= TCP_SUM;
    emit tcpSumChanged();
}

QString FilterData::getTcpUrp() const {
	return tcp_urp;
}

void FilterData::setTcpUrp(QString tcpUrp) {
	tcp_urp = tcpUrp;
    if (tcp_urp.isEmpty())
        tcpFlag &= ~TCP_URP;
    else
        tcpFlag |= TCP_URP;
    emit tcpUrpChanged();
}

QString FilterData::getTcpWin() const {
	return tcp_win;
}

void FilterData::setTcpWin(QString tcpWin) {
	tcp_win = tcpWin;
    if (tcp_win.isEmpty())
        tcpFlag &= ~TCP_WIN;
    else
        tcpFlag |= TCP_WIN;
    emit tcpWinChanged();
}

short FilterData::getTcpFlag() const {
	return tcpFlag;
}

// U D P

QString FilterData::getUdpChksum() const {
	return udp_chksum;
}

void FilterData::setUdpChksum(QString udpChksum) {
	udp_chksum = udpChksum;
    if (udp_chksum.isEmpty())
        tcpFlag &= ~UDP_CHKSUM;
    else
        tcpFlag |= UDP_CHKSUM;
    emit udpChksumChanged();
}

QString FilterData::getUdpDestport() const {
	return udp_destport;
}

void FilterData::setUdpDestport(QString udpDestport) {
	udp_destport = udpDestport;
    if (udp_destport.isEmpty())
        tcpFlag &= ~UDP_DESTPORT;
    else
        tcpFlag |= UDP_DESTPORT;
    emit udpDestportChanged();
}

QString FilterData::getUdpLen() const {
	return udp_len;
}

void FilterData::setUdpLen(QString udpLen) {
	udp_len = udpLen;
    if (udp_len.isEmpty())
        tcpFlag &= ~UDP_LEN;
    else
        tcpFlag |= UDP_LEN;
    emit udpLenChanged();
}

QString FilterData::getUdpSrcport() const {
	return udp_srcport;
}

void FilterData::setUdpSrcport(QString udpSrcport) {
	udp_srcport = udpSrcport;
    if (udp_srcport.isEmpty())
        tcpFlag &= ~UDP_SRCPORT;
    else
        tcpFlag |= UDP_SRCPORT;
    emit udpSrcportChanged();
}

char FilterData::getUdpFlag() const {
	return udpFlag;
}

// VALIDATORS

bool FilterData::validateTcp(Ethernet *packet) {
    IP<Ethernet> *ip = new IP<Ethernet>(*packet);
    TCP<IP<Ethernet>> *tcp = new TCP<IP<Ethernet>>(*ip);

    if (tcpFlag & TCP_SPORT)
        if (tcp->getThSport() != tcp_sport.toShort())
            return false;
    if (tcpFlag & TCP_DPORT)
        if (tcp->getThDport() != tcp_dport.toShort())
            return false;
    return true;
}

bool FilterData::validateTcp_V6(Ethernet *packet) {
    IPV6<Ethernet> *ipv6 = new IPV6<Ethernet>(*packet);
    TCP<IPV6<Ethernet>> *tcp = new TCP<IPV6<Ethernet>>(*ipv6);

    if (tcpFlag & TCP_SPORT)
        if (tcp->getThSport() != tcp_sport.toShort())
            return false;
    if (tcpFlag & TCP_DPORT)
        if (tcp->getThDport() != tcp_dport.toShort())
            return false;
    return true;
}

bool FilterData::validateUdp(Ethernet *packet) {
    IP<Ethernet> *ip = new IP<Ethernet>(*packet);
    UDP<IP<Ethernet>> *udp = new UDP<IP<Ethernet>>(*ip);

    if (udpFlag & UDP_SRCPORT)
        if (udp->getUdphDestport() != udp_destport.toShort())
            return false;
    if (udpFlag & UDP_DESTPORT)
        if (udp->getUdphSrcport() != udp_srcport.toShort())
            return false;
    return true;
}

bool FilterData::validateUdp_V6(Ethernet *packet) {
    IPV6<Ethernet> *ipv6 = new IPV6<Ethernet>(*packet);
    UDP<IPV6<Ethernet>> *udp = new UDP<IPV6<Ethernet>>(*ipv6);

    if (udpFlag & UDP_SRCPORT)
        if (udp->getUdphDestport() != udp_destport.toShort())
            return false;
    if (udpFlag & UDP_DESTPORT)
        if (udp->getUdphSrcport() != udp_destport.toShort())
            return false;
    return true;
}

bool FilterData::validateIcmp(Ethernet *packet) {
 // ???
    return true;
}

bool FilterData::validateIp(Ethernet *packet) {
    IP<Ethernet> *ip = new IP<Ethernet>(*packet);
    std::string type = ip->getIpP_string();

    //useless
    if (ipFlag & IP_VHL)
        if (((unsigned int) ip->getIpVhl()) != (unsigned int) std::stoi(ip_vhl.toStdString()))
            return false;
    if (ipFlag & IP_P)
        if (type != ip_p.toStdString())
            return false;
    if (ipFlag & IP_SRC)
        if (ip->getSource() != ip_src.toStdString())
            return false;
    if (ipFlag & IP_DST)
        if (ip->getDestination() != ip_dst.toStdString())
            return false;

    if (type == "TCP")
        return validateTcp(packet);
    else if (type == "UDP")
        return validateUdp(packet);
    else if (type == "ICMP")
        return validateIcmp(packet);

    return true;
}

bool FilterData::validateArp(Ethernet *packet) {
    ARP<Ethernet> *arp = new ARP<Ethernet>(*packet);

    if (arpFlag & ARP_SHA)
        if ( arp->getSha() != arp_sha.toStdString())
            return false;
    if (arpFlag & ARP_SPA)
        if (arp->getSpa() != arp_spa.toStdString())
            return false;
    if (arpFlag & ARP_THA)
        if (arp->getTha() != arp_tha.toStdString())
            return false;
    if (arpFlag & ARP_TPA)
        if (arp->getTpa() != arp_tpa.toStdString())
            return false;
    return true;
}

bool FilterData::validateIpv6(Ethernet *packet) {
    IPV6<Ethernet> *ipv6 = new IPV6<Ethernet>(*packet);
    std::string type = ipv6->getNextHead_String();

    if (ipFlag & IP_SRC)
        if (ipv6->getIp6Src() != ipv6_src.toStdString())
            return false;
    if (ipFlag & IP_DST)
        if (ipv6->getIp6Dest() != ipv6_dest.toStdString())
            return false;

    if (type == "TCP")
        return validateTcp_V6(packet);
    else if (type == "UDP")
        return validateUdp_V6(packet);

    return true;
}

bool FilterData::validateEthernet(Ethernet *packet){
    if (etherFlag & ETHER_DHOST)
        if (packet->getEther_dhost() != ether_dhost.toStdString())
            return false;
    if (etherFlag & ETHER_SHOST)
        if (packet->getEther_shost() != ether_shost.toStdString())
            return false;
    if (etherFlag & ETHER_TYPE)
        if (packet->getEther_typeString() != ether_type.toStdString())
            return false;
    return true;
}

bool FilterData::validate(Ethernet *packet) {
    bool isvalid = true;
    std::string type = packet->getEther_typeString();

    if (etherFlag & (ETHER_DHOST | ETHER_SHOST | ETHER_TYPE))
        isvalid = validateEthernet(packet);

    if (type == "IP") {
        if (!validateIp(packet))
            return false;
    }
    else if (type == "ARP") {
        if (!validateArp(packet))
            return false;
    }
    else if (type == "IPV6") {
        if (!validateIpv6(packet))
            return false;
    }

    return isvalid;
}