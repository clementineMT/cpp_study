#ifndef __ECHOSERVICE_HPP__
#define __ECHOSERVICE_HPP__
#include<functional>
#include<iostream>
#include<string>
typedef char Connection;
//这是使用者类，在初始化时，把发送消息的逻辑交给NetServe类去完成
class EchoService
{
public:
    typedef std::function<void (Connection*, const void*, int)> SendMessageCallback;
    EchoService(const SendMessageCallback& sendMsgCb)
    : sendMessageCb_(sendMsgCb)
    {

    }

    void onMessage(Connection* conn, const void* buf, int size)
    {
        std::cout << //"EchoService::onMessage(Connection* conn, const void* buf, int size):\n" <<
        "Received Message from: " << conn << ", content is: "<< (const char*)buf << std::endl;
        sendMessageCb_(conn, buf, size);//echo back

    }

    void onConnection(Connection* conn)
    {
        std::cout << //"EchoService::onConnection(Connection* conn, const void* buf, int size):\n" <<
        "Connection  from :" << conn << std::endl;
    }

private:
    SendMessageCallback sendMessageCb_;
};

#endif