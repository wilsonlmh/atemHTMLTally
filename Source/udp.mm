//
//  udp.cpp
//  atemCPlus
//
//  Created by Wilson Luniz on 5/31/14.
//  Copyright (c) 2014 Luniz Pd. All rights reserved.
//

#include "udp.h"



bool udpHandle::setup() {
    charRemoteIP = remoteIP.c_str();
    //Create socket
    sid = socket(AF_INET,SOCK_DGRAM,0);
    if (sid < 0) {
        return false;
        error = 1;
    } else {
        bzero(&remoteAddr,sizeof(remoteAddr));
        remoteAddr.sin_family = AF_INET;
        remoteAddr.sin_port = htons(remotePort);
        remoteAddr.sin_addr.s_addr = inet_addr(charRemoteIP);
        localAddr.sin_family = AF_INET;
        localAddr.sin_port = htons(localPort);
        bid = bind(sid, (struct sockaddr *)&localAddr, sizeof(struct sockaddr));
        error = 0;
        return true;
        
    }
    
}

int udpHandle::available() {
    int returnInt = 0;
    char trying;
    if (error == 0) {
        //ioctl(sid,FIONREAD,&returnInt);
        returnInt = recvfrom(sid, &trying, 1024 , MSG_PEEK, (struct sockaddr *)&remoteAddr,&addr_len);
        std::cout << returnInt;
    }
    return returnInt;
}

void udpHandle::read(int size) {
    if (error == 0) {
        recvfrom(sid,readBuffer,size,0,(struct sockaddr *)&remoteAddr,&addr_len);
    }
}

void udpHandle::write(byte buffer[], int length) {
    if (error == 0 && status == 0) {
        status = 1;
        sendto(sid,buffer,length,0,(struct sockaddr *)&remoteAddr,addr_len);
        std::cout << "\n";
        std::cout << "sent;";
        status = 0;
    }
}

void udpHandle::free() {
    close(sid);
}