#ifndef LOGGER_H
#define LOGGER_H

#include <QDebug>
#include <QLoggingCategory>
#include <QtGlobal>

#define SYSTEM_DEFAULT_LOG "system.default"

Q_DECLARE_LOGGING_CATEGORY(system_default)

class Logger
{
    Q_OBJECT
public:
    Logger();

    enum Verbosity {
        Essential = 1,   //fatal, critical, warning, info[1], debug[1]
        Normal = 4,       //1, info[4], debug[4]
        Detail = 7      //4, info[7], debug[7]
    };

    enum LogType{
        Debug, Info, Warning, Critical, Fatal
    };

    static void setVerbosity(Verbosity level);
    static Verbosity getVerbosity();
    static void setDebugging(bool enabled);
    static bool debugEnabled();

    static void debug(const char* message);
    static void debug(QString message);
    static void debug(QLoggingCategory logger, const char* message);
    static void debug(QLoggingCategory logger, QString message);

    static void info(Verbosity verbosityLevel, const char* message);
    static void info(Verbosity verbosityLevel, QString message);
    static void info(QLoggingCategory logger, Verbosity verbosityLevel, const char* message);
    static void info(QLoggingCategory logger, Verbosity verbosityLevel, QString message);

    static void warning(const char* message);
    static void warning(QString message);
    static void warning(QLoggingCategory logger, const char* message);
    static void warning(QLoggingCategory logger, QString message);

    static void critical(const char* message);
    static void critical(QString message);
    static void critical(QLoggingCategory logger, const char* message);
    static void critical(QLoggingCategory logger, QString message);

    static void fatal(const char* message);
    static void fatal(QString message);
    static void fatal(QLoggingCategory logger, const char* message);
    static void fatal(QLoggingCategory logger, QString message);



private:
    static Verbosity verbosityLevel;

    static bool checkPrint(Verbosity verbosityLevel, Logger::LogType type);

    static void printDebug(QLoggingCategory logger, QString message);

    static void printInfo(QLoggingCategory logger, Verbosity verbosityLevel, QString message);
    static void printWarning(QLoggingCategory logger, QString message);
    static void printCritical(QLoggingCategory logger, QString message);
    static void printFatal(QLoggingCategory logger, QString message);
};

#endif // LOGGER_H
