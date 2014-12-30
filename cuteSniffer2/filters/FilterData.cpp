#include "FilterData.hh"


FilterData::FilterData() {

}

FilterData::FilterData(const FilterData &) : QObject(0) {

}

FilterData FilterData::intance = FilterData();

FilterData &FilterData::getInstance() {
    return intance;
}

QString FilterData::getEther_dhost() {
    return ether_dhost;
}

QString FilterData::getEther_shost() {
    return ether_shost;
}

QString FilterData::getEther_type() {
    return ether_type;
}

void FilterData::setEther_dhost(QString const &dhost) {
    ether_dhost = dhost;
}

void FilterData::setEther_shost(QString const &shost) {
    ether_shost = shost;
}

void FilterData::setEther_type(QString const &type) {
    ether_type = type;
}
