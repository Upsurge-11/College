#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

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

  int port = atoi(argv[1]);

  int sockfd;
  struct sockaddr_in serverAddr;

  int newSocket;
  struct sockaddr_in newAddr;

  socklen_t addr_size;
  char name[1024];
  int marks[5];

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

  bzero(name, sizeof(name));
  recv(newSocket, name, sizeof(name), 0);
  printf("[+] Data received: %s\n", name);

  recv(newSocket, marks, sizeof(marks), 0);
  printf("[+] Data received.");

  int highestMarks = greatestInArray(marks);

  send(newSocket, name, sizeof(name), 0);
  printf("[+] Data sent: %s\n", name);

  send(newSocket, &highestMarks, sizeof(highestMarks), 0);
  printf("[+] Data sent: %d\n", highestMarks);

  printf("[+]Closing the connection.\n");
  close(newSocket);
  shutdown(sockfd, SHUT_RDWR);

  return 0;
}