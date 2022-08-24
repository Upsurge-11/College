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
  struct sockaddr_in serveraddr, clientaddr1, clientaddr2;
  int a, b;
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

  addrsize = sizeof(clientaddr1);
  recvfrom(sockfd, &a, sizeof(a), 0, (struct sockaddr *)&clientaddr1, &addrsize);
  printf("[+] Data received: %d\n", a);

  addrsize = sizeof(clientaddr2);
  recvfrom(sockfd, &b, sizeof(b), 0, (struct sockaddr *)&clientaddr2, &addrsize);
  printf("[+] Data received: %d\n", b);

  int ans;
  if (a >= b)
    ans = a;
  else
    ans = b;

  sendto(sockfd, &ans, sizeof(ans), 0, (struct sockaddr *)&clientaddr1, sizeof(clientaddr1));
  printf("[+] Data sent: %d\n", ans);

  sendto(sockfd, &ans, sizeof(ans), 0, (struct sockaddr *)&clientaddr2, sizeof(clientaddr2));
  printf("[+] Data sent: %d\n", ans);

  return 0;
}