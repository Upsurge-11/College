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
  char id[1024];
  char pswd[1024];
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

  bzero(id, sizeof(id));
  printf("Enter the id :-");
  fgets(id, 1024, stdin);
  sendto(sockfd, id, sizeof(id), 0, (struct sockaddr *)&addr, sizeof(addr));
  printf("[+] ID Sent: %s\n", id);

  bzero(pswd, sizeof(pswd));
  printf("Enter the pswd :-");
  fgets(pswd, 1024, stdin);
  sendto(sockfd, pswd, sizeof(pswd), 0, (struct sockaddr *)&addr, sizeof(addr));
  printf("[+] Pswd Sent: %s\n", pswd);

  return 0;
}