#include"BaseDataReceiver.h"
#include"Arduino.h"
BaseDataReceiver::BaseDataReceiver(/* args */)
{
   
}

void BaseDataReceiver::Receive(Message* msg){   
    message = msg;    
    MessageHandler();
}
BaseDataReceiver::~BaseDataReceiver()
{
}