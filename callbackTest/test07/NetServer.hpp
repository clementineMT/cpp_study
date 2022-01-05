#ifndef __NETSERVER_HPP__
#define __NETSERVER_HPP__
#include <functional>
#include <string.h>
#include <iostream>
typedef char Connection;
//负责实现发送消息和服务器运行的逻辑实现
class NetServer
{
public:
    typedef std::function<void(Connection*)> ConnectionCallback;
    typedef std::function<void(Connection*, const void*, int len)> MessageCallback;

    NetServer(uint16_t port);
    ~NetServer();
    void registerConnectionCallback(const ConnectionCallback&);
    void registerMessageCallback(const MessageCallback&);
    void sendMessage(Connection*, const void* buf, int len);
    void run();
private:
    uint16_t port_;
    ConnectionCallback connectionCb_;
    MessageCallback messageCb_;
};
NetServer::NetServer(uint16_t port)
{
    port_ = port;
}
NetServer::~NetServer()
{
   
}
void NetServer::sendMessage(Connection* conn, const void* buf, int len)
{
   // conn_ = conn;
   // strcpy(buf_, (const char*)buf);
   // len_ = len;
    std::cout << "send Message to :" << conn << ", content is: "  << (const char*) buf << std::endl;

}
void NetServer::registerConnectionCallback(const ConnectionCallback& ConnectionCb)
{
    connectionCb_ = ConnectionCb;
}

void NetServer::registerMessageCallback(const MessageCallback& MessageCb)
{
    messageCb_ = MessageCb;
}

void NetServer::run()
{
    char *tmp = "hello";
    connectionCb_("conn");
    messageCb_("conn", (const void*) tmp, 6);
    
    
    std::cout << "EchoService completed!" << std::endl;
}
#endif