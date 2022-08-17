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
  char id[1024];
  char pswd[1024];
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

  char idStored[1024];
  char pswdStored[1024];
  printf("Enter the ID :-\n");
  fgets(idStored, 1024, stdin);
  printf("Enter the pswd:-\n");
  fgets(pswdStored, 1024, stdin);

  bzero(id, sizeof(id));
  addrsize = sizeof(clientaddr);
  recvfrom(sockfd, id, sizeof(id), 0, (struct sockaddr *)&clientaddr, &addrsize);
  printf("[+] Data received: %s\n", id);

  bzero(pswd, sizeof(pswd));
  addrsize = sizeof(clientaddr);
  recvfrom(sockfd, pswd, sizeof(pswd), 0, (struct sockaddr *)&clientaddr, &addrsize);
  printf("[+] Data received: %s\n", pswd);

  if (strcmp(id, idStored) == 0 && strcmp(pswd, pswdStored) == 0)
  {
    printf("[+] Login Successful\n");
  }
  else
  {
    printf("[-] Login Failed\n");
  }

  return 0;
}