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

int get_port(char *port_s)
{
   return atoi(port_s);
}

struct hostent* get_server(char *host)
{
   struct hostent *server = gethostbyname(host);
   if (server == NULL) 
   {
      fprintf(stderr,"ERROR, no such host: %s\n", host);
      exit(0);
   }

   return server;
}

void validate_input(int argc, char *argv[])
{
   if (argc < 3) 
   {
      fprintf(stderr,"usage %s hostname port\n", argv[0]);
      exit(0);
   }
}

struct sockaddr_in create_server_address(char *host_s, char *port_s)
{
   int port = get_port(port_s);
   struct hostent *server = get_server(host_s);

   struct sockaddr_in server_address;
   bzero((char *) &server_address, sizeof(server_address));
   server_address.sin_family = AF_INET;
   bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
   server_address.sin_port = htons(port);
   return server_address;
}

int connect_to_server(int argc, char *argv[])
{
   validate_input(argc, argv);

   int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
   if (socket_fd < 0) 
   {
      error("ERROR opening socket");
   }

   struct sockaddr_in server_address = create_server_address(argv[1], argv[2]);
   int connection = connect(socket_fd, (struct sockaddr *) &server_address, sizeof(server_address));
   if (connection < 0)
   {
      error("ERROR connecting");
   }

   return socket_fd;
}

void get_input(char *buffer)
{
   printf("Please enter the message: ");

   bzero(buffer, 256);
   fgets(buffer, 255, stdin);
}

void write_to_server(int socket_fd, char *buffer)
{
   int bytes_written_to_server = write(socket_fd, buffer, strlen(buffer));
   if (bytes_written_to_server < 0)
   {
      error("ERROR writing to socket");
   }
}

void read_response_from_server(int socket_fd, char *buffer)
{
   bzero(buffer, 256);
   int bytes_from_response = read(socket_fd, buffer, 255);
   if (bytes_from_response < 0)
   {
      error("ERROR reading from socket");
   }
}

int main(int argc, char *argv[])
{
   int socket_fd = connect_to_server(argc, argv);

   char buffer[256];

   get_input(buffer);

   write_to_server(socket_fd, buffer);

   read_response_from_server(socket_fd, buffer);

   printf("%s\n", buffer);

   close(socket_fd);

   return 0;
}
