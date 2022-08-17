#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("Usage: server <port>\n");
    exit(0);
  }

  char *ip = "127.0.0.1";
  int port = atoi(argv[1]);

  int sockfd;
  struct sockaddr_in serveraddr, clientaddr;
  char buffer[1024];
  socklen_t addrsize;
  int n;

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);

  if (sockfd < 0)
  {
    perror("[-] socket error");
    exit(1);
  }
  else
  {
    printf("[+] socket success\n");
  }

  memset(&serveraddr, '\0', sizeof(serveraddr));
  serveraddr.sin_family = AF_INET;
  serveraddr.sin_port = htons(port);
  serveraddr.sin_addr.s_addr = inet_addr(ip);

  n = bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

  if (n < 0)
  {
    perror("[-] bind error");
    exit(2);
  }
  else
  {
    printf("[+] bind success\n");
  }

  while (1)
  {
    bzero(buffer, sizeof(buffer));
    addrsize = sizeof(clientaddr);
    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&clientaddr, &addrsize);
    printf("[+] Client:- %s\n", buffer);

    if (strcmp(buffer, "bye\n") == 0)
    {
      break;
    }

    bzero(buffer, sizeof(buffer));
    printf("[+] Send chat :-");
    fgets(buffer, 1024, stdin);
    sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));

    if (strcmp(buffer, "bye\n") == 0)
    {
      break;
    }
  }

  return 0;
}