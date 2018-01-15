#ifndef NETWORKMASTER_HPP_
#define NETWORKMASTER_HPP_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netdb.h> 
#include <vector>

using namespace std;

class NetworkMaster
{
  private:
    int sock;
    std::string address;
    int port;
    struct sockaddr_in server;

  public:
    NetworkMaster();
    bool setup(string address, int port);
    bool Send(string data);
    string receive(int size = 4096);
    string read();
};

#endif // NETWORKMASTER_HPP_