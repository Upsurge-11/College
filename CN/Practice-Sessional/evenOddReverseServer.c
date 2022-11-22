#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void displayEvenOdd(int *buffer)
{
  printf("Even numbers are: ");
  for (int i = 0; i < 5; i++)
  {
    if (buffer[i] % 2 == 0)
    {
      printf("%d ", buffer[i]);
    }
  }
  printf("\nOdd numbers are: ");
  for (int i = 0; i < 5; i++)
  {
    if (buffer[i] % 2 != 0)
    {
      printf("%d ", buffer[i]);
    }
  }
  printf("\n");
}

void reverse(int *buffer)
{
  int temp;
  for (int i = 0; i < 5 / 2; i++)
  {
    temp = buffer[i];
    buffer[i] = buffer[4 - i];
    buffer[4 - i] = temp;
  }
}

void display(int *buffer)
{
  printf("The array is: ");
  for (int i = 0; i < 5; i++)
  {
    printf("%d ", buffer[i]);
  }
  printf("\n");
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
  int buffer[5] = {0};

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

  recv(newSocket, buffer, sizeof(buffer), 0);
  printf("[+]Data Recieved.\n");

  display(buffer);

  printf("[+]Seperating Even and Odd Numbers.\n");

  displayEvenOdd(buffer);

  reverse(buffer);

  printf("[+]Reversing the array.\n");

  display(buffer);

  send(newSocket, buffer, sizeof(buffer), 0);
  printf("[+]Data Sent.\n");

  printf("[+]Closing the connection.\n");
  close(newSocket);
  shutdown(sockfd, SHUT_RDWR);

  return 0;
}