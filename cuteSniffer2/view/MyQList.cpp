#include "MyQList.hh"
#include <iostream>

MyQList::MyQList() : QAbstractListModel() {

}

MyQList::MyQList(const MyQList &other) : QAbstractListModel(), _datas(other._datas) {

}

MyQList &MyQList::operator=(const MyQList &other) {
    this->_datas = other._datas;
    return *this;
}

QVariant MyQList::data(const QModelIndex &index, int role) const {
    std::cout << "#YOLO \\o/ : MyQList::data" << std::endl;
    if (!index.isValid())
        return QVariant();

    if (index.row() >= _datas.size())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole) {
        QObject *item = _datas[index.row()];
        return QVariant::fromValue(item);
    }
    else
        return QVariant();
}
int MyQList::rowCount(const QModelIndex &/*parent*/) const {
    std::cout << "MyQList::rowCount" << std::endl;
    //return _datas.count();
    return 10;
}
void MyQList::push_back(QObject * elm) {
    this->beginInsertRows(QModelIndex(), _datas.count() - 1, _datas.count() - 1);
    _datas.push_back(elm);
    this->endInsertRows();
    emit this->_datasChanged();
    std::cout << "MyQList::push_back :" << _datas.count() << "elm" << std::endl;
}
QList<QObject *> MyQList::getDatas() const {
    return this->_datas;
}
