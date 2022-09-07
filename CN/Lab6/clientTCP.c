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

  int port = atoi(argv[1]);

  int clientSocket;
  struct sockaddr_in serverAddr;
  char buffer[1024] = {0};

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  printf("[+]Client Socket Created Sucessfully.\n");

  memset(&serverAddr, '\0', sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(port);
  inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

  connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
  printf("[+]Connected to Server.\n");

  recv(clientSocket, buffer, 1024, 0);
  printf("[+]Data Recv: %s\n", buffer);
  printf("[+]Closing the connection.\n");

  return 0;
}