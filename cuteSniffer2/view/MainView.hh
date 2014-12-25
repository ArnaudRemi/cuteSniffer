#ifndef MAIN_VIEW_HH__
#define MAIN_VIEW_HH__

#include <QObject>
#include <QTimer>
#include <QQmlApplicationEngine>
#include <QQmlListProperty>
#include "EthernetDisplay.hh"
#include "RawSocket.hh"

class MainView : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<EthernetDisplay> packets READ getPackets NOTIFY packetsChanged)
private:
    void initView();
    void initNetwork();
    void initData();
public:
    MainView(QQmlApplicationEngine *engine);
    ~MainView();

    QQmlListProperty<EthernetDisplay> getPackets();

public slots:
    void runCapture();
    void stopCapture();
    void catchPacket();
    void rowDoubleClick(int row);

signals:
    void packetsChanged();

private:
    RawSocket socket;
    QTimer timerSocket;
    QList<EthernetDisplay *> packets;
    QQmlApplicationEngine *engine;
};

#endif // MAIN_VIEW_HH__
