//
//  udp.h
//  atemCPlus
//
//  Created by Wilson Luniz on 5/31/14.
//  Copyright (c) 2014 Luniz Pd. All rights reserved.
//

#ifndef __atemCPlus__udp__
#define __atemCPlus__udp__

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/ioctl.h>

using byte = uint8_t;

class udpHandle {
public:
    bool setup();
    int remotePort;
    int localPort;
    std::string remoteIP;
    const char * charRemoteIP;
    //int mode = 0; //0:client, 1:server
    int sid; //Socket ID(FD)
    int bid; //Bind ID
    void write(byte buffer[], int length);
    void read(int size);
    uint8_t readBuffer[96];
    void free();
    int available();
    int status = 0; //0:Idle, 1:Sending
    int error = -1; //-1:not setup yet, 0:normal, >0:error code
    struct sockaddr_in remoteAddr, localAddr;
    socklen_t addr_len =sizeof(struct sockaddr_in);
    
};

#endif /* defined(__atemCPlus__udp__) */
