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
  char name[1024];
  int highestMarks;
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

  bzero(name, sizeof(name));
  printf("Enter name :-\n");
  fgets(name, 1024, stdin);
  sendto(sockfd, name, sizeof(name), 0, (struct sockaddr *)&addr, sizeof(addr));
  printf("[+] Data sent: %s\n", name);

  int marks[5];
  printf("Enter subject marks :-\n");
  for (int i = 0; i < 5; i++)
  {
    scanf("%d", &marks[i]);
  }
  sendto(sockfd, marks, sizeof(marks), 0, (struct sockaddr *)&addr, sizeof(addr));
  printf("[+] Data sent,\n");

  bzero(name, sizeof(name));
  addrsize = sizeof(addr);
  recvfrom(sockfd, name, sizeof(name), 0, (struct sockaddr *)&addr, &addrsize);
  printf("[+] Data received: %s\n", name);

  recvfrom(sockfd, &highestMarks, sizeof(highestMarks), 0, (struct sockaddr *)&addr, &addrsize);
  printf("[+] Data received: %d\n", highestMarks);

  return 0;
}