#ifndef MAIN_VIEW_HH__
#define MAIN_VIEW_HH__

#include <QObject>
#include <QTimer>
#include <QList>
#include <list>
#include <QString>
#include <QQmlApplicationEngine>
#include <QQmlListProperty>
#include "EthernetDisplay.hh"
#include "RawSocket.hh"
//#include "StringFilter.hh"
//#include "FilterWidget.hh"

class MainView : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<EthernetDisplay> packets READ getPackets NOTIFY packetsChanged)
    Q_PROPERTY(QString interface READ getInterface WRITE setInterface NOTIFY interfaceChanged)
    Q_PROPERTY(QString openFile READ getOpenFile WRITE setOpenFile NOTIFY openFileChanged)
    Q_PROPERTY(QString saveFile READ getSaveFile WRITE setSaveFile NOTIFY saveFileChanged)
private:
    void initView();
    int initNetwork();

public:
    MainView(QQmlApplicationEngine *engineApp);
    ~MainView();

    QQmlListProperty<EthernetDisplay> getPackets();
    QString getInterface() const;
    void setInterface(QString value);
    void setOpenFile(QString const &openFile);
    QString getOpenFile() const;
    void setSaveFile(QString const &saveFile);
    QString getSaveFile() const;
    //void addFilter(Filter *filter);

public slots:
    void runCapture();
    void stopCapture();
    void saveCapture();
    void openCapture();
    void deleteCapture();
    void catchPacket();
    void displayUsers();
    void rowDoubleClick(int row);

    void openFileSelect();
    void saveFileSelect();
//    void addStringFilter();

signals:
    void packetsChanged();
    void interfaceChanged();
    void promisciousError();
    void openFileChanged();
    void saveFileChanged();

private:
    QTimer timerSocket;
    QList<EthernetDisplay *> packets;
    std::list<Ethernet *> packetsData;
    QQmlApplicationEngine *engineApp;
    QString interface;
    QString openFile;
    QString saveFile;
//    QList<Filter *> filters;
};

#endif // MAIN_VIEW_HH__
