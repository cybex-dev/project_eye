#include <QCoreApplication>
#include <QLoggingCategory>
#include <QDebug>

#include "../../Libraries/cryptopp/aes.h"

#include "serverapp.h"

Q_DECLARE_LOGGING_CATEGORY(serverapp_main)
Q_LOGGING_CATEGORY(serverapp_main, "serverapp.main")

QHash<QString, QVariant> *qSettings;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug(serverapp_main) << "Project_Eye Server Start (" << QDateTime::currentDateTime().toString("hh:mm:ss, dd.MM.yyyy (ddd)") << ")";
    (new ServerApp())->start();
    return a.exec();
}

