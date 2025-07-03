#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include "MusicController.h"
#include <QIcon>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    app.setWindowIcon(QIcon(":/assets/music.ico"));
    MusicController controller;
    engine.rootContext()->setContextProperty("musicController", &controller);

    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));
    if (engine.rootObjects().isEmpty()) {
        qDebug() << "Failed to load QML file";
        return -1;
    }

    return app.exec();
}
