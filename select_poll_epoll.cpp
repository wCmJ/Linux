#include<sys/types.h>
fd_set event;
FD_ZERO(&event);
FD_SET(fd1, &event);
timeval tm;
tm.tv_sec = 3;
tm.tv_usec = 0;
int n = select(maxfd + 1, &event, NULL, NULL, &tm);


#include<poll.h>
vector<pollfd> v;
pollfd info;
info.fd = clientfd;
info.events = POLLIN;
info.revents = 0;
v.push_back(info);
int n = poll(&v[0], v.size(), 1000);


#include<sys/epoll.h>
int epollfd = create_epoll(1);
epoll_event event;
event.data.fd = listenfd;
event.events = EPOLLIN;
//event.events = EPOLLET;
epoll_ctl(epollfd, EPOLL_CTL_ADD, listenfd, &event);

epoll_event epoll_events[1024];
int n = epoll_wait(epollfd, epoll_events, 1024, 1000);


ET模式下：
client： nc -v localhost portnum
server:50000 -> client:58382
client端数据发送完成后，ctrl+c，client->server方向进入FIN_WAIT2，server->client方向进入CLOSE_WAIT。
挥手流程（推测）:   client  send FIN            -> FIN_WAIT1
                  server  recv FIN send ACK     ->CLOSE_WAIT
                  client  recv ACK              ->FIN_WAIT2
一段时间后，处于FIN_WAIT2状态的连接超时，退出。
            处于CLOSE_WAIT状态的连接仍然存在。
此时，重新使用58382端口连接50000端口，连接成功，均处于ESTABLISHED状态。


