#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string>
#include <netinet/in.h>
#include <pthread.h>

static const pthread_mutex_t network_mutex = PTHREAD_MUTEX_INITIALIZER;
static const pthread_cond_t network_condix = PTHREAD_COND_INITIALIZER;

class Network {
	private:
	static const int MAX_CONN = 5;
	static const bool incoming_connections_maxed = true;

	public:
	Network();
	~Network();
	Network(const Network& network);
	Network& operator=(const Network& network);
	int get_max_conn() {return MAX_CONN;}
	bool get_incoming_connections() {return incoming_connections_maxed;}
	void network_activate_peer_server(int argc, const char ** argv);
	void network_activate_peer_client(int argc, const char **argv);
	bool network_error_msg(const char *msg);
};