#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void displayLarger(int n, int m)
{
  if (n > m)
  {
    printf("%d is larger than %d\n", n, m);
  }
  else
  {
    printf("%d is larger than %d\n", m, n);
  }
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
  int nums[2];

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

  recv(newSocket, &nums, sizeof(nums), 0);
  printf("[+]Data Received: %d, %d\n", nums[0], nums[1]);
  displayLarger(nums[0], nums[1]);

  printf("[+]Closing the connection.\n");
  close(newSocket);
  shutdown(sockfd, SHUT_RDWR);

  return 0;
}