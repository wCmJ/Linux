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








