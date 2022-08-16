#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int greatestInArray(int *a)
{
  int ans = a[0];
  for (int i = 1; i < 5; i++)
  {
    if (a[i] > ans)
    {
      ans = a[i];
    }
  }
  return ans;
}

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
  char name[1024];
  int marks[5];
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

  bzero(name, sizeof(name));
  addrsize = sizeof(clientaddr);
  recvfrom(sockfd, name, sizeof(name), 0, (struct sockaddr *)&clientaddr, &addrsize);
  printf("[+] Data received: %s\n", name);

  recvfrom(sockfd, marks, sizeof(marks), 0, (struct sockaddr *)&clientaddr, &addrsize);
  printf("[+] Data received.");

  int highestMarks = greatestInArray(marks);

  sendto(sockfd, name, sizeof(name), 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
  printf("[+] Data sent: %s\n", name);

  sendto(sockfd, &highestMarks, sizeof(highestMarks), 0, (struct sockaddr *)&clientaddr, sizeof(clientaddr));
  printf("[+] Data sent: %d\n", highestMarks);

  return 0;
}