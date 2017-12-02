#include "logger.h"

Q_LOGGING_CATEGORY(system_default, SYSTEM_DEFAULT_LOG)
Verbosity Logger::verbosityLevel = Logger::Verbosity::Normal;

Logger::Logger()
{

}

Verbosity Logger::getVerbosity(){
    return Logger::verbosityLevel;
}

void Logger::setVerbosity(Verbosity level){
    Logger::verbosityLevel = level;
}

// DEBUG
void Logger::debug(QString message){
    printDebug(logger, message);
}

void Logger::debug(const char* message){
    printDebug(logger, QString(message));
}

void Logger::debug(QLoggingCategory logger = system_default(), QString message){
    printDebug(logger, message);
}

void Logger::debug(QLoggingCategory logger = system_default(), const char* message){
    printDebug(logger, QString(message));
}

void Logger::printDebug(QLoggingCategory logger, QString message){
    qDebug(logger) << message;
}

// INFO
void Logger::info(Verbosity verbosityLevel, QString message){
    printInfo(logger, verbosityLevel, message);
}

void Logger::info(Verbosity verbosityLevel, const char* message){
    printInfo(logger, verbosityLevel, QString(message));
}

void Logger::info(QLoggingCategory logger = system_default(), Verbosity verbosityLevel, QString message){
    printInfo(logger, verbosityLevel, message);
}

void Logger::info(QLoggingCategory logger = system_default(), Verbosity verbosityLevel, const char* message){
    printInfo(logger, verbosityLevel, QString(message));
}

void Logger::printInfo(QLoggingCategory logger, Verbosity verbosityLevel, QString message){
    if (checkPrint(verbosityLevel, LogType::Info))
        qInfo(logger) << message;
}

// WARNING
void Logger::warning(QString message){
    printWarning(logger, message);
}

void Logger::warning(const char* message){
    printWarning(logger, QString(message));
}

void Logger::warning(QLoggingCategory logger = system_default(), QString message){
    printWarning(logger, message);
}

void Logger::warning(QLoggingCategory logger = system_default(), const char* message){
    printWarning(logger, QString(message));
}

void Logger::printWarning(QLoggingCategory logger, QString message){
    qWarning() << message;
}

// CRITICAL
void Logger::critical(QString message){
    printCritical(logger, message);
}

void Logger::critical(const char* message){
    printCritical(logger, QString(message));
}

void Logger::critical(QLoggingCategory logger = system_default(), QString message){
    printCritical(logger, message);
}

void Logger::critical(QLoggingCategory logger = system_default(), const char* message){
    printCritical(logger, QString(message));
}

void Logger::printcritical(QLoggingCategory logger, QString message){
    qCritical() << message;
}

// FATAL
void Logger::fatal(QString message){
    printFatal(logger, message);
}

void Logger::fatal(const char* message){
    printFatal(logger, QString(message));
}

void Logger::fatal(QLoggingCategory logger = system_default(), QString message){
    printFatal(logger, message);
}

void Logger::fatal(QLoggingCategory logger = system_default(), const char* message){
    printFatal(logger, QString(message));
}

void Logger::printFatal(QLoggingCategory logger, QString message){
    qFatal() << message;
}

bool Logger::checkPrint(Verbosity verbosityLevel, Logger::LogType type){
    switch (type) {
    case LogType::Info:
        if (this->verbosityLevel) {
            break;
        }
    case LogType::Warning:
        if (this->verbosityLevel) {
            break;
        }
    case LogType::Critical:
    case LogType::Fatal:
    case LogType::Debug:
    default:
        return true;
    }
}
