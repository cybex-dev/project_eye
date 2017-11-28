#ifndef _ONREADLISTENER_H
#define _ONREADLISTENER_H

class IonReadyListener {
public:
    virtual ~IonReadyListener(){}

signals:
    virtual void onReadyListener() = 0;
};

#endif // _ONREADLISTENER_H
