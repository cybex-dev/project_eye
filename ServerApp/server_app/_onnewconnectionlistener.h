#ifndef _ONNEWCONNECTIONLISTENER_H
#define _ONNEWCONNECTIONLISTENER_H

class IonNewConnectionListener {
public:
    virtual ~IonNewConnectionListener(){}

signals:
    virtual void onNewConnectionListener() = 0;
};

#endif // _ONNEWCONNECTIONLISTENER_H
