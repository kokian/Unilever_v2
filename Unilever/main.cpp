#include "mainwindow.h"
#include <QApplication>

#include <QFile>
#include <QDateTime>
#include <QDebug>
#include <QTextStream>



void myMessageOutput(QtMsgType type, const QMessageLogContext& context, const QString& msg) {
    QFile fMessFile(qApp->applicationDirPath() + "/unilever.log");
    if(!fMessFile.open(QIODevice::Append | QIODevice::Text)){
        return;
    }
    QString sCurrDateTime = "[" + QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz") + "]";
    QTextStream tsTextStream(&fMessFile);
    switch(type){
    case QtDebugMsg:
        tsTextStream << QString("UnileverLogDebug%1: %2\n").arg(sCurrDateTime).arg(msg);
        break;
    case QtWarningMsg:
        tsTextStream << QString("UnileverLogWarning%1: %2\n").arg(sCurrDateTime).arg(msg);
        break;
    case QtCriticalMsg:
        tsTextStream << QString("UnileverLogCritical%1: %2\n").arg(sCurrDateTime).arg(msg);
        break;
    case QtFatalMsg:
        tsTextStream << QString("UnileverLogFatal%1: %2\n").arg(sCurrDateTime).arg(msg);
        abort();
    }
    tsTextStream.flush();
    fMessFile.flush();
    fMessFile.close();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qInstallMessageHandler(myMessageOutput);

    MainWindow w;
    w.showMaximized();

    return a.exec();
}
