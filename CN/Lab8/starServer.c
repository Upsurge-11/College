#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

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

  int newSocket1, newSocket2;
  struct sockaddr_in newAddr;

  socklen_t addr_size;
  char buffer1[1024], buffer2[1024];

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

  newSocket1 = accept(sockfd, (struct sockaddr *)&newAddr, &addr_size);
  newSocket2 = accept(sockfd, (struct sockaddr *)&newAddr, &addr_size);

  recv(newSocket1, buffer1, sizeof(buffer1), 0);
  printf("[+] Data received from client 1: %s\n", buffer1);
  recv(newSocket2, buffer2, sizeof(buffer2), 0);
  printf("[+] Data received from client 2: %s\n", buffer2);
  send(newSocket1, buffer2, sizeof(buffer2), 0);
  send(newSocket2, buffer1, sizeof(buffer1), 0);
  printf("[+]Data swapped and sent to both clients.\n");
  printf("[+]Closing the connection.\n");
  close(newSocket2);
  close(newSocket1);

  shutdown(sockfd, SHUT_RDWR);

  return 0;
}