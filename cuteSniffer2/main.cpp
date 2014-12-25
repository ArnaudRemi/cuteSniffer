#include <QApplication>
#include <QQmlApplicationEngine>
#include "MainView.hh"

void fillData(QList<QObject *> &data);

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    MainView mainView(&engine);
    return app.exec();
}
