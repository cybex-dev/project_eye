#ifndef SERVERAPP_H
#define SERVERAPP_H

#include <QCoreApplication>
#include <QThread>
#include <QSettings>
#include <QStandardPaths>
#include <QtDebug>

#include "crypt.h"

class ServerApp : public QThread
{
public:
    ServerApp();
    ~ServerApp();
    
    enum AppInfo {
        OrgName, OrgDomain, AppName
    };

private:
    QString orgName = "Default",
            appName = "Project_Eye",
            orgDomain = "default.com";
    bool processArg(QString argValue);
    void processArg(QString argName, QString argValue);
    void parseServerInfo(QSettings *settings);
    void readArgs(int argCount, char *args[]);
    void readConfigs();
    
protected:
    void run();
};

#endif // SERVERAPP_H
