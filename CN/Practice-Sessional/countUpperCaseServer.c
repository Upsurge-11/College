#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int countUpperCase(char *buffer)
{
  int count = 0;
  for (int i = 0; i < strlen(buffer); i++)
  {
    if (buffer[i] >= 'A' && buffer[i] <= 'Z')
    {
      count++;
    }
  }
  return count;
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
  char buffer[1024] = {0};

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

  memset(buffer, '\0', sizeof(buffer));
  recv(newSocket, buffer, 1024, 0);
  printf("[+]Data Recv: %s\n", buffer);
  int ans = countUpperCase(buffer);
  send(newSocket, &ans, sizeof(ans), 0);
  printf("[+] Data sent: %d\n", ans);

  printf("[+]Closing the connection.\n");
  close(newSocket);
  shutdown(sockfd, SHUT_RDWR);

  return 0;
}