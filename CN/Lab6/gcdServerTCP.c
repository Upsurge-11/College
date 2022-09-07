#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int gcd(int a, int b)
{
  int result;
  if (a > b)
  {
    result = b;
  }
  else
  {
    result = a;
  }
  while (result > 0)
  {
    if (a % result == 0 && b % result == 0)
    {
      break;
    }
    result--;
  }
  return result;
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("Usage: server <port>\n");
    exit(0);
  }

  int port = atoi(argv[1]);

  int sockfd;
  struct sockaddr_in serverAddr;

  int newSocket;
  struct sockaddr_in newAddr;

  socklen_t addr_size;
  int a, b, ans;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  printf("[+]Server Socket Created Sucessfully.\n");
  memset(&serverAddr, '\0', sizeof(serverAddr));

  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(port);
  serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
  printf("[+]Bind to Port number %d.\n", port);

  listen(sockfd, 5);
  printf("[+]Listening...\n");

  newSocket = accept(sockfd, (struct sockaddr *)&newAddr, &addr_size);

  recv(newSocket, &a, sizeof(a), 0);
  printf("[+]Received first number: %d.\n", a);
  recv(newSocket, &b, sizeof(b), 0);
  printf("[+]Received second number: %d.\n", b);
  ans = gcd(a, b);
  send(newSocket, &ans, sizeof(ans), 0);
  printf("[+]Sent GCD: %d.\n", ans);
  printf("[+]Closing the connection.\n");
  close(newSocket);
  shutdown(sockfd, SHUT_RDWR);

  return 0;
}