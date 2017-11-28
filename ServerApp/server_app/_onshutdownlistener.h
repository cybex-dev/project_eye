#ifndef _ONSHUTDOWNLISTENER_H
#define _ONSHUTDOWNLISTENER_H

class IonShutdownListener {
public:
    virtual ~IonShutdownListener(){}

signals:
    virtual void onShutdownListener() = 0;
};


#endif // _ONSHUTDOWNLISTENER_H
