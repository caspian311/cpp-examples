/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int get_port(int argc, char *argv[])
{
   if (argc < 2) 
   {
      fprintf(stderr,"ERROR, no port provided\n");
      exit(1);
   }

   return atoi(argv[1]);
}

int bind_to_port(int port) 
{
   int server_socket = socket(AF_INET, SOCK_STREAM, 0);
   if (server_socket < 0)
   {
      error("ERROR opening socket");
   }

   struct sockaddr_in server_address;
   bzero((char *) &server_address, sizeof(server_address));
   server_address.sin_family = AF_INET;
   server_address.sin_addr.s_addr = INADDR_ANY;
   server_address.sin_port = htons(port);
   if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) 
   {
      error("ERROR on binding");
   }

   listen(server_socket, 5);

   return server_socket;
}

int wait_for_client(int server_socket)
{
   struct sockaddr_in client_address;
   socklen_t client_address_length;
   client_address_length = sizeof(client_address);
   int socket_to_client = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
   if (socket_to_client < 0) 
   {
      error("ERROR on accept");
   }

   return socket_to_client;
}

void read_data_from_client(int socket_to_client, char* buffer)
{
   bzero(buffer, 256);
   int bytesReadFromClient = read(socket_to_client, buffer, 255);
   if (bytesReadFromClient < 0) 
   {
      error("ERROR reading from socket");
   }
}

void send_response_to_client(int socket_to_client)
{
   int bytesSentBack = write(socket_to_client, "I got your message", 18);
   if (bytesSentBack < 0) 
   {
      error("ERROR writing to socket");
   }
}

int main(int argc, char *argv[])
{
   int port = get_port(argc, argv);
   int server_socket = bind_to_port(port);

   while (1)
   {
      int socket_to_client = wait_for_client(server_socket);

      char buffer[256];
      read_data_from_client(socket_to_client, buffer);
      printf("Message from client: %s\n", buffer);

      send_response_to_client(socket_to_client);

      close(socket_to_client);
   }

   close(server_socket);

   return 0; 
}
