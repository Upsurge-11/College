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

  pid_t childpid;

  int sockfd, flag = 1;
  struct sockaddr_in serverAddr;

  int n;
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

  printf("[+]Enter the number of Clients:- ");
  scanf("%d", &n);

  printf("[+]Listening...\n");

  // int newSocket[n];

  // for (int i = 0; i < n; i++)
  // {
  //   newSocket[i] = accept(sockfd, (struct sockaddr *)&newAddr, &addr_size);
  //   printf("[+]Connection Accepted from %s:%d.\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
  // }

  // while (flag)
  // {
  //   for (int i = 0; i < n; i++)
  //   {
  //     recv(newSocket[i], buffer, sizeof(buffer), 0);
  //     printf("[+] Message Received: %s\n", buffer);
  //     bzero(buffer, sizeof(buffer));
  //     if (strcmp(buffer, "exit\n") == 0)
  //     {
  //       printf("[+]Closing the connection.\n");
  //       flag = 0;
  //     }
  //     if (flag)
  //     {
  //       bzero(buffer, sizeof(buffer));
  //       strcpy(buffer, "Hello Client  ");
  //       buffer[13] = i + 1 + '0';
  //       send(newSocket[i], buffer, sizeof(buffer), 0);
  //       printf("[+] Message Sent: %s\n", buffer);
  //       bzero(buffer, sizeof(buffer));
  //     }
  //   }
  // }

  // for (int i = 0; i < n; i++)
  // {
  //   close(newSocket[i]);
  // }

  int newSocket;

  while (n--)
  {
    newSocket = accept(sockfd, (struct sockaddr *)&newAddr, &addr_size);
    printf("[+]Connection Accepted from %s:%d.\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

    if ((childpid = fork()) == 0)
    {
      while (flag)
      {
        printf("[+]Waiting for message from Client %d...\n", n + 1);
        recv(newSocket, buffer, sizeof(buffer), 0);
        printf("[+] Message Received: %s\n", buffer);
        bzero(buffer, sizeof(buffer));
        if (strcmp(buffer, "exit\n") == 0)
        {
          printf("[+]Closing the connection.\n");
          flag = 0;
        }
        if (flag)
        {
          bzero(buffer, sizeof(buffer));
          strcpy(buffer, "Hello Client  ");
          buffer[13] = n + 1 + '0';
          send(newSocket, buffer, sizeof(buffer), 0);
          printf("[+] Message Sent: %s\n", buffer);
          bzero(buffer, sizeof(buffer));
        }
      }
    }
  }

  close(sockfd);

  shutdown(sockfd, SHUT_RDWR);

  return 0;
}