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
  char id[1024] = {0};
  char pswd[1024] = {0};

  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  printf("[+]Client Socket Created Sucessfully.\n");

  memset(&serverAddr, '\0', sizeof(serverAddr));
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(port);
  inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

  connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
  printf("[+]Connected to Server.\n");

  printf("Enter the id :- ");
  fgets(id, 1024, stdin);
  send(clientSocket, id, sizeof(id), 0);
  printf("[+] ID Sent: %s\n", id);

  printf("Enter the pswd :- ");
  fgets(pswd, 1024, stdin);
  send(clientSocket, pswd, sizeof(pswd), 0);
  printf("[+] Pswd Sent: %s\n", pswd);

  return 0;
}