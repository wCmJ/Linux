
socket tells the kernel that
even if this port is busy(in the TIME_WAIT state), go ahead and reuse it anyway.
if it is busy, but with another state, you will still get an address already in use error.

int on = 1;
setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (char*)&on, sizeof(on));
after set this option, when one port is in TIME_WAIT state, we can bind to this port again with other five tuple.

1.set this time socket to SO_REUSEADDR
2.this time can reuse this port

/---------------------------------------------------------------------------------------------------------------------/
SO_REUSEADDR
after test:
    whatever set/noset, can not bind specify ip/port and INADDR_ANY/port (Linux cmad-android-dailybuild 2.6.32-33)
    if set reuse, can bind to ip/port when it is TIME_WAIT
    
SO_REUSEPORT
    allow to more than one socket which set SO_REUSEPORT bind to smae ip/port 
    if first one do not set SO_REUSEPORT, later socket will fail when bind.

SO_LINGER
    if set SO_LINGER, when call close function TCP/IP stack will drop data in buffer and send RST
    









