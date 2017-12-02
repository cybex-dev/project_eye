#include "serverapp.h"

ServerApp::ServerApp()
{

}

ServerApp::~ServerApp(){
    delete this;
}

void ServerApp::run(){
    qInfo(serverapp_main) << "::Starting";
    qSettings = new QHash();
    qInfo(serverapp_main) << "::Reading Configs";
    readConfigs();
    readArgs(argc, argv);
    qInfo(serverapp_main) << "::Loading Modules";
    loadModules();
    qInfo(serverapp_main) << "::Initializing Modules";
    connectModuleSignals();
    qInfo(serverapp_main) << "::Starting Modules";
    startModules();
    qInfo(serverapp_main) << "::Awaiting Modules' Ready Signal";
    waitForModulesReady();
    qInfo(serverapp_main) << "::Go Ahead!";
    goAhead();
}

void ServerApp::readConfigs(){
    parseServerInfo(&settings_serverinfo);
    qInfo(serverapp_main) << ":: Loading Default Config";w
    QSettings settings_system = QSettings(QSettings::Format::IniFormat, QSettings::Scope::SystemScope, QCoreApplication::organizationName(), QCoreApplication::applicationName());
    
    QStringList list = settings_system.allKeys();
    for (int var = 0; var < list.size(); var++) {
        QString key = list.at(var),
            value = settings_system.value(key);
        processArg(key, value);
    }
}


void ServerApp::readArgs(int argCount, char *args[]){
    QString argName = QString();
    bool kvPair = false;
    int count = 0;
    while (count < argCount) {
        argName = QString(args[++count]);
        if (kvPair) {
            processArg(argName, QString(args[++count]));
            kvPair = false;
        }
        if (!processArg(argName))
            kvPair = true;
    }
}

bool ServerApp::processArg(QString argValue){

}

void ServerApp::processArg(QString argName, QString argValue){

}

void ServerApp::parseServerInfo(QSettings *settings){
    appName = settings->value(AppInfo::AppName, appName);
    orgName = settings->value(AppInfo::OrgName, orgName);
    orgDomain = settings->value(AppInfo::OrgDomain, orgDomain);
    QCoreApplication::setApplicationName(appName);
    QCoreApplication::setOrganizationName(orgName);
    QCoreApplication::setOrganizationDomain(orgDomain);
}

