
#include "network.hpp"

void Network::network_activate_peer_server(int argc, const char** argv) {
    int sockfd, newsockfd,portno, ions;
    struct sockaddr_in server_address, client_address; char buffer[255];
    socklen_t aclient_len;

   sockfd = socket(AF_INET, SOCK_STREAM, 0);
   if(sockfd < 0) network_error_msg("socket initialisation error");
   portno = atoi(argv[1]);
   bzero((char*)&server_address, sizeof(server_address));
   server_address.sin_family = AF_INET;
   server_address.sin_addr.s_addr = INADDR_ANY;
   server_address.sin_port = htons(portno);

   if (bind(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0 )
	network_error_msg("error binding port to socket");
   if (listen(sockfd, Network::get_max_conn()) < 0)
	network_error_msg("max conns reached");

	aclient_len = sizeof(client_address);
	newsockfd = accept(sockfd, (struct sockaddr*)&client_address, &aclient_len);
	if(newsockfd < 0) network_error_msg("failed to accept incoming client connection");
	while(Network::get_incoming_connections()){
		bzero(buffer, 255);
		ions = read(newsockfd,buffer, 255);
        bzero(buffer, 255);
        fgets(buffer,255, stdin);
		if(ions < 0) network_error_msg("error reading from client");
		ions = write(newsockfd,buffer, 255);
		if(ions < 0) network_error_msg("error writing to client");
		if(strncmp(buffer, "sample", 6) == 0) break;
	}
	close(newsockfd);
	close(sockfd);
}

void Network::network_activate_peer_client(int argc, const char **argv) {
    int sockfd, portno, ions;
    struct sockaddr_in server_address;
    struct hostent *server;
    char buffer[255];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) network_error_msg("client connection failed");
    portno = atoi(argv[2]);
    bzero((char*)&server_address, sizeof(server_address)); 
    server_address.sin_family = AF_INET;
    bcopy((char*)&server->h_addr, (char*)&server_address.sin_addr, server->h_length);
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(portno);

    server = gethostbyname(argv[1]);
    if(server == nullptr) network_error_msg("server identification failed");
    if(connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0)
        network_error_msg("connection to server failed");
    while(Network::get_incoming_connections()){
        bzero(buffer, 255);
        fgets(buffer, 255, stdin);
        ions = write(sockfd, buffer, strlen(buffer));
        if(ions < 0) network_error_msg("client write failed");
        ions = read(sockfd, buffer, 255);
        if(ions < 0) network_error_msg("client read failed");
        if(strncmp(buffer, "sample", 6) == 0) break;
    }
    close(sockfd);
}

bool Network::network_error_msg(const char* msg) {
    perror(msg); return false;
}