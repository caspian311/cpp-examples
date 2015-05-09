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

int connect_to_server(struct hostent *server, int port)
{
   int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
   if (socket_fd < 0) 
   {
      error("ERROR opening socket");
   }
   struct sockaddr_in server_address;
   bzero((char *) &server_address, sizeof(server_address));
   server_address.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
   server_address.sin_port = htons(port);
   int connection = connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address));
   if (connection < 0)
   {
      error("ERROR connecting");
   }

   return socket_fd;
}

struct hostent *get_server(char *argv[])
{
   struct hostent *server = gethostbyname(argv[1]);
   if (server == NULL) 
   {
      fprintf(stderr,"ERROR, no such host\n");
      exit(0);
   }

   return server;
}

int main(int argc, char *argv[])
{
   validate_input(argc, argv);

   int port = get_port(argv);
   struct hostent *server = get_server(argv);

   int socket_fd = connect_to_server(server, port);

   printf("Please enter the message: ");

   char buffer[256];
   bzero(buffer, 256);
   fgets(buffer, 255, stdin);

   int bytes_written_to_server = write(socket_fd, buffer, strlen(buffer));
   if (bytes_written_to_server < 0)
   {
      error("ERROR writing to socket");
   }
   bzero(buffer, 256);
   int bytes_from_response = read(socket_fd, buffer, 255);
   if (bytes_from_response < 0)
   {
      error("ERROR reading from socket");
   }
   printf("%s\n", buffer);

   close(socket_fd);

   return 0;
}
