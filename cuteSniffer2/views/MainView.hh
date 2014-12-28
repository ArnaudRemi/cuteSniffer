#ifndef MAIN_VIEW_HH__
#define MAIN_VIEW_HH__

#include <QObject>
#include <QTimer>
#include <QString>
#include <QQmlApplicationEngine>
#include <QQmlListProperty>
#include "EthernetDisplay.hh"
#include "RawSocket.hh"

class MainView : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<EthernetDisplay> packets READ getPackets NOTIFY packetsChanged)
    Q_PROPERTY(QString interface READ getInterface WRITE setInterface NOTIFY interfaceChanged)
private:
    void initView();
    int initNetwork();
public:
    MainView(QQmlApplicationEngine *engineApp);
    ~MainView();

    QQmlListProperty<EthernetDisplay> getPackets();
    QString getInterface() const;
    void setInterface(QString value);

public slots:
    void runCapture();
    void stopCapture();
    void catchPacket();
    void displayUsers();
    void rowDoubleClick(int row);

signals:
    void packetsChanged();
    void interfaceChanged();
    void promisciousError();

private:
    QTimer timerSocket;
    QList<EthernetDisplay *> packets;
    QQmlApplicationEngine *engineApp;
    QString interface;
};

#endif // MAIN_VIEW_HH__
