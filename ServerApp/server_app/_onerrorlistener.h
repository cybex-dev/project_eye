#ifndef _ONERRORLISTENER_H
#define _ONERRORLISTENER_H

class IonErrorListener {
public:
    virtual ~IonErrorListener(){}

signals:
    virtual void onErrorListener() = 0;
};


#endif // _ONERRORLISTENER_H
