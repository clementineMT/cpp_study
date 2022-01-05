/*
    网络库
    以boost::function作为桥梁，NetServer class对其使用者没有任何类型上的现在，
    只对成员函数的参数和返回类型有限制。使用者EchoService也完全不知道NetServer的
    存在，只要在main()里把两者装配到一起，程序就跑起来了
*/

//这里模仿一个echo服务器的交互模式，在NetServer::run()中直接写了收到的消息，conn用字符串代替，
//运行可以看到如下：
// Connection  from :conn
// Received Message from: conn, content is: hello
// send Message to :conn, content is: hello
// EchoService completed!

#include "NetServer.hpp"
#include "EchoService.hpp"
#include <functional>
#include <iostream>
using std::placeholders::_1;
using std::placeholders::_2;
using std::placeholders::_3;

int main()
{
    NetServer server(80);
    EchoService echo(std::bind(&NetServer::sendMessage, &server, _1, _2, _3));

    server.registerMessageCallback(std::bind(&EchoService::onMessage, &echo, _1, _2, _3));

    server.registerConnectionCallback(std::bind(&EchoService::onConnection, &echo, _1));

    server.run();

    return 0;
}