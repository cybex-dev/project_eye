#ifndef CLIENTCONNECTION_H
#define CLIENTCONNECTION_H

#include <QThread>

class ClientConnection : public QThread
{
public:
    ClientConnection();
};

#endif // CLIENTCONNECTION_H
