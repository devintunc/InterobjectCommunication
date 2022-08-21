#pragma once

#ifndef BaseDataReceiver_H
#define BaseDataReceiver_H

#include"Message.h"


class BaseDataReceiver
{
protected:    
    Message* message;   
public:

    BaseDataReceiver(/* args */);
    ~BaseDataReceiver();
    void Receive(Message* msg);

    virtual void MessageHandler();
};




#endif