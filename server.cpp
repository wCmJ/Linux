#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<time.h>
#include<vector>
using namespace std;

const int INVALID_FD = -1;

int main()
{
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    //sa.sin_addr.s_addr = htonl(INADDR_ANY);
    sa.sin_port = htons(50000);
    
    if(bind(serverfd, (struct sockaddr*)&sa, sizeof(sa)) == -1)
    {
        cout <<"bind error" <<endl;
        return -1;
    }
    
    if(listen(serverfd, 10) == -1)
    {
        cout << "listen error" <<endl;
        return -1;
    }
    vecor<int> fds;
    int maxfd = serverfd;
    while(true)
    {
        fd_set readset;
        FD_ZERO(&readset);
        FD_SET(serverfd, &readset);
        timeval tm;
        tm.tv_sec = 3;
        tm.tv_usec = 0;
        for(int i=0;i<fds.size();++i)
        {
            if(fds[i] != -1)
                FD_SET(fds[i], &readset);
        }
        int ret = select(maxfd + 1, &readset, NULL, NULL, &tm);
        if(ret == -1)
        {
            //error
            cout <<"select error" <<endl;
            break;
        }
        else if(ret == 0)
        {
            //timeout
            continue;
        }
        else
        {
            if(FD_ISSET(serverfd, &readset))
            {
                struct sock_addr clientsa;
                int tmpfd = accept(serverfd, (sturct sockaddr*)&clientsa, sizeof(clientsa));
                if(tmpfd == -1)
                {
                    cout << "accept error" <<endl;
                    break;
                }
                fds.push_back(tmpfd);
                if(tmpfd > maxfd)
                    maxfd = tmpfd;
            }
            else
            {                
                char buffer[36];
                memset(buffer, 0, 36);
                for(int i=0;i<fds.size();i++)
                {
                    if(fds[i] != INVALID_FD && FD_ISSET(fds[i], &readset))
                    {
                        int len = recv(serverfd, buffer, 36, 0)
                        if(len < 0)
                        {
                            //error
                        }
                        else if(len == 0)
                        {
                            //disconnect
                            cout <<"fd: "<< fds[i] << " disconnect"<<endl;
                            fds[i] = INVALID_FD;
                        }
                        else
                        {
                            cout << "fd is: "<<fds[i] << ", data is: "<<buffer<<endl; 
                        }                  
                    }
                }            
            }        
        }
    }
    int len = fds.size();
    for(int i=0;i<len;i++)
    {
        if(fds[i] != INVALID_FD)
            close(fds[i]);
    }
    close(serverfd);
    return 0;
}
