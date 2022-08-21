#pragma once

#include "BaseDataReceiver.h"
#define ReceiversCount 5

class BaseDataSndr
{
protected:
    BaseDataReceiver *Receivers[ReceiversCount];

public:
    Sender ID;

    inline void Send(Message *);
    inline void Send(Message *, BaseDataReceiver *);

    inline Message *CreateMessage(Sender);
    inline Message *CreateMessage(String, String);
    inline Message *CreateMessage(Sender, String, String);
    inline Message *CreateMessage(Command);
    inline Message *CreateMessage(Command, String, String);

    inline BaseDataSndr();
    inline ~BaseDataSndr();

private:
};
// Returns Info type message.
Message *BaseDataSndr::CreateMessage(Sender ID)
{
    Message &msg = (Message::GetInstance(MSGType::Info));
    msg.Set(ID, "", "");

    return &msg;
}
// Returns Info type message.
Message *BaseDataSndr::CreateMessage(String data0, String data1)
{
    Message &msg = (Message::GetInstance(MSGType::Info));    
    msg.Set(ID, data0, data1);    
    return &msg;
}
// Returns Info type message.
Message *BaseDataSndr::CreateMessage(Sender ID, String data0, String data1)
{
    Message &msg = (Message::GetInstance(MSGType::Info));
    msg.Set(ID, data0, data1);
    
    return &msg;
}
// Returns Controller type message.
Message *BaseDataSndr::CreateMessage(Command cmd)
{
    Message &msg = (Message::GetInstance(MSGType::Controller));
    msg.Set(ID, cmd, "", "");

    return &msg;
}
Message *BaseDataSndr::CreateMessage(Command cmd, String data0, String data1)
{
    Message &msg = (Message::GetInstance(MSGType::Controller));
    msg.Set(ID, cmd, data0, data1);

    return &msg;
}

void BaseDataSndr::Send(Message *msg)
{
    // unsigned long m;
    // uint8_t oldSREG = SREG;
    // cli();
    for (int i = 0; i < ReceiversCount; i++)
    {
        if (Receivers[i])
            Receivers[i]->Receive(msg);
    }
    // SREG=oldSREG;
}
void BaseDataSndr::Send(Message *msg, BaseDataReceiver *Receiver)
{

    // uint8_t oldSREG = SREG;
    // cli();
    Receiver->Receive(msg);
    // SREG=oldSREG;
}

BaseDataSndr::BaseDataSndr()
{
}
BaseDataSndr::~BaseDataSndr()
{
}
