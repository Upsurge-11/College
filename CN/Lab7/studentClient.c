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
  char name[1024];
  int highestMarks;

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  printf("[+]Client Socket Created Sucessfully.\n");

  memset(&serverAddr, '\0', sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(port);
  inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

  connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
  printf("[+]Connected to Server.\n");

  bzero(name, sizeof(name));
  printf("Enter name :-\n");
  fgets(name, 1024, stdin);
  send(clientSocket, name, sizeof(name), 0);
  printf("[+] Data sent: %s\n", name);

  int marks[5];
  printf("Enter subject marks :-\n");
  for (int i = 0; i < 5; i++)
  {
    scanf("%d", &marks[i]);
  }
  send(clientSocket, marks, sizeof(marks), 0);
  printf("[+] Data sent,\n");

  bzero(name, sizeof(name));
  recv(clientSocket, name, sizeof(name), 0);
  printf("[+] Data received: %s\n", name);

  recv(clientSocket, &highestMarks, sizeof(highestMarks), 0);
  printf("[+] Data received: %d\n", highestMarks);

  printf("[+]Closing the connection.\n");

  return 0;
}