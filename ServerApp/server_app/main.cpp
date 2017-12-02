#include <QCoreApplication>
#include <QLoggingCategory>
#include <QDebug>
#include <QProcessEnvironment>

#include "serverapp.h"
#include "logger.h"
#include "global.h"

Q_DECLARE_LOGGING_CATEGORY(main_starter)
Q_LOGGING_CATEGORY(main_starter, "main.starter")

QSettings *config;
QProcessEnvironment env = QProcessEnvironment::systemEnvironment();

void setEnvironmentVariables(){
    // QT_MESSAGE_PATTERN

    QString defaultPattern = "%{time} - [%{type}] %{category}: %{message}";
    if (!config->contains(Global::QT_MESSAGE_PATTERN)) {
        config->setValue(Global::QT_MESSAGE_PATTERN, defaultPattern);
    }
    QString messagePattern = config->value(Global::QT_MESSAGE_PATTERN, defaultPattern).toString();
    env.insert(Global::QT_MESSAGE_PATTERN, messagePattern);

    // QT_LOGGING_DEBUG

    QString defaultRules = "*.debug=false";
    if (!config->contains(Global::QT_LOGGING_DEBUG)) {
        config->setValue(Global::QT_LOGGING_DEBUG, defaultRules);
    }
    QString value = config->value(Global::QT_LOGGING_DEBUG, defaultRules).toString();
    env.insert(Global::QT_LOGGING_DEBUG, value);
}

void loadPreRunConfig(){
    // Determine Log Level

    config = new QSettings(Global::SETTINGS_CONFIG, QSettings::Format::IniFormat);

    bool *b;
    int level = config->value(Global::LOG_LEVEL, 4).toInt(b);
    Logger::Verbosity v;
    if (*b == false) {
        v = Logger::Verbosity::Normal;
    }
    if (level < 2) {
        v = Logger::Verbosity::Essential;
    } else if (level < 5) {
        v = Logger::Verbosity::Normal;
    } else {
        v = Logger::Verbosity::Detail;
    }
    Logger::setVerbosity(v);
}

void loadPreRunSettings(){

    QCoreApplication::setApplicationName("Project_EYE");
    QCoreApplication::setOrganizationName("default");

    Logger::info(Logger::Verbosity::Normal, "Initializing Environment");
    setEnvironmentVariables();
    Logger::info(Logger::Verbosity::Normal, "Loading Prerun Configuration");
    loadPreRunConfig();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug(main_starter) << "Server Initializing Prerun";
    loadPreRunSettings();
    Logger::info(Logger::Verbosity::Essential, "Starting Server Thread");
    (new ServerApp())->start();
    return a.exec();
}

