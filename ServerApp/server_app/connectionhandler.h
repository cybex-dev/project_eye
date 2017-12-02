#ifndef CONNECTIONHANDLER_H
#define CONNECTIONHANDLER_H

#include <QThread>
#include <QLoggingCategory>
#include <QHostAddress>
#include <QTcpServer>
#include <QTcpSocket>
#include <QSocketNotifier>

#include "_onreadylistener.h"
#include "_onerrorlistener.h"
#include "_onshutdownlistener.h"
#include "_onnewconnectionlistener.h"
#include "clientconnection.h"

Q_DECLARE_LOGGING_CATEGORY(server_connectionhandler)
Q_DECLARE_INTERFACE(IonReadyListener, "IonReadyListener")
Q_DECLARE_INTERFACE(IonErrorListener, "IonErrorListener")
Q_DECLARE_INTERFACE(IonShutdownListener, "IonShutdownListener")
Q_DECLARE_INTERFACE(IonNewConnectionListener, "IonNewConnectionListener")

namespace Conn {
class ConnectionHandler;
}

class ConnectionHandler:
        public QThread,
        public IonReadyListener, public IonShutdownListener, public IonErrorListener, public IonNewConnectionListener
{

    Q_OBJECT
    Q_INTERFACES(IonReadyListener)
    Q_INTERFACES(IonShutdownListener)
    Q_INTERFACES(IonErrorListener)
    Q_INTERFACES(IonNewConnectionListener)

public:
    ConnectionHandler();
    ConnectionHandler(QHostAddress hostAddress, int server_port);
    void init();

    enum class ConnectionError {
        UnknownError, SocketError, PortUnavailableError, AlreadyRunningError, PermissionError
    };

private:
    QList<ClientConnection*> clientConnections;
    QHostAddress hostAddress = QHostAddress::Any;
    int hostPort = 5050;
    QTcpServer *serverSocket;

    void run();
    void newConnectionHandler();

private slots:
    void goAhead();

signals:
    void onReadyListener();
    void onErrorListener(ConnectionError error);
    void onShutdownListener();
    void onNewConnectionListener(); //possibly not used

};

#endif // CONNECTIONHANDLER_H
