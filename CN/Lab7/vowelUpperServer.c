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

  bzero(buffer, sizeof(buffer));
  recv(newSocket, buffer, sizeof(buffer), 0);
  printf("[+] Data received: %s\n", buffer);

  for (int i = 0; buffer[i] != '\0'; i++)
  {
    if (buffer[i] >= 'a' && buffer[i] <= 'z' && (buffer[i] == 'a' || buffer[i] == 'e' || buffer[i] == 'i' || buffer[i] == 'o' || buffer[i] == 'u'))
    {
      buffer[i] = buffer[i] - 32;
    }
  }
  printf("[+] Changed data: %s\n", buffer);
  send(newSocket, buffer, sizeof(buffer), 0);
  printf("[+] Data sent: %s\n", buffer);

  printf("[+]Closing the connection.\n");
  close(newSocket);
  shutdown(sockfd, SHUT_RDWR);

  return 0;
}