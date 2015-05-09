#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

void validate_input(int argc, char *argv[])
{
   if (argc < 3) 
   {
      fprintf(stderr,"usage %s hostname port\n", argv[0]);
      exit(0);
   }
}

int get_port(char *argv[])
{
   return atoi(argv[2]);
}

int main(int argc, char *argv[])
{
   validate_input(argc, argv);

   int port = get_port(argv);

   int sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if (sockfd < 0) 
   {
      error("ERROR opening socket");
   }
   struct hostent *server;
   server = gethostbyname(argv[1]);
   if (server == NULL) 
   {
      fprintf(stderr,"ERROR, no such host\n");
      exit(0);
   }
   struct sockaddr_in serv_addr;
   bzero((char *) &serv_addr, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
   serv_addr.sin_port = htons(port);
   if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
   {
      error("ERROR connecting");
   }

   printf("Please enter the message: ");

   char buffer[256];
   bzero(buffer, 256);
   fgets(buffer, 255, stdin);
   int bytes_written_to_server = write(sockfd, buffer, strlen(buffer));
   if (bytes_written_to_server < 0)
   {
      error("ERROR writing to socket");
   }
   bzero(buffer, 256);
   int bytes_from_response = read(sockfd, buffer, 255);
   if (bytes_from_response < 0)
   {
      error("ERROR reading from socket");
   }
   printf("%s\n", buffer);

   close(sockfd);

   return 0;
}
