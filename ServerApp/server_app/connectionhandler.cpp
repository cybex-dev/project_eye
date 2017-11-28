#include "connectionhandler.h"

Q_LOGGING_CATEGORY(server_connectionhandler, "server.connectionhandler")

ConnectionHandler::ConnectionHandler()
{
    qDebug(server_connectionhandler) << "::Creating Server Socket";
    serverSocket = new QTcpServer();
    this->clientConnections = new QList();
}

ConnectionHandler::ConnectionHandler(QHostAddress hostAddress, int hostPort){
    this->hostAddress = hostAddress;
    this->hostPort = hostPort;
    ConnectionHandler();
}

void ConnectionHandler::run(){
    serverSocket->listen(hostAddress,hostPort);
    serverSocket->pauseAccepting();
    if (serverSocket->isListening()) {
        qDebug(server_connectionhandler) << "::Server Listening on" << hostAddress.toString() << ":" << QString::number(hostPort) ;
        qDebug(server_connectionhandler) << "[WAITING] Emitting ready signal & Waiting for goahead";
        emit onReadyListener();
    } else {
        qDebug(server_connectionhandler) << "Error: Server Socket not listening";
        emit onErrorListener(ConnectionError::SocketError);
    }
}

void ConnectionHandler::goAhead(){
    qDebug(server_connectionhandler) << "goAhead received";
    serverSocket->resumeAccepting();
}

void ConnectionHandler::newConnectionHandler(){
    QTcpSocket *socket = serverSocket->nextPendingConnection();
    qDebug(server_connectionhandler) << "New Connection Recevied from " << socket->peerAddress().toIPv4Address() << "[" << socket->peerAddress().toIPv6Address() << "]";
    ClientConnection *conn = new ClientConnection();
    conn->start();
    clientConnections->append(&conn);
}
