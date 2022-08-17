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
    printf("Usage: client <port>\n");
    exit(0);
  }

  char *ip = "127.0.0.1";
  int port = atoi(argv[1]);

  int sockfd;
  struct sockaddr_in addr;
  char buffer[1024];
  socklen_t addrsize;

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

  memset(&addr, '\0', sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = inet_addr(ip);

  while (1)
  {
    bzero(buffer, sizeof(buffer));
    printf("[+] Send chat :- \n");
    fgets(buffer, 1024, stdin);
    sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, sizeof(addr));

    if (strcmp(buffer, "bye\n") == 0)
    {
      break;
    }

    bzero(buffer, sizeof(buffer));
    addrsize = sizeof(addr);
    recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, &addrsize);
    printf("[+] Server:- %s\n", buffer);

    if (strcmp(buffer, "bye\n") == 0)
    {
      break;
    }
  }

  return 0;
}