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
  int buffer[5];
  printf("Enter the array :- ");
  for (int i = 0; i < 5; i++)
  {
    scanf("%d", &buffer[i]);
  }
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

  sendto(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, sizeof(addr));
  printf("[+] Data sent: %s\n", buffer);

  int ans;

  addrsize = sizeof(addr);
  recvfrom(sockfd, &ans, sizeof(ans), 0, (struct sockaddr *)&addr, &addrsize);
  printf("[+] Data received: %d\n", ans);

  return 0;
}