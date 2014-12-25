#ifndef MYQLIST_H
#define MYQLIST_H

#include <QAbstractListModel>
#include <QList>
class MyQList : public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(QList<QObject *> _datas READ getDatas NOTIFY _datasChanged)
public:
    MyQList();
    MyQList(const MyQList &other);
    MyQList &operator=(const MyQList &other);
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    void push_back(QObject * elm);
    QList<QObject *> getDatas() const;

signals:
    void _datasChanged();
public:
    QList<QObject *> _datas;
};
#endif // MYQLIST_H

