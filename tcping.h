#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#ifndef NETWORKING_H
#define NETWORKING_H
#define ACK "HOLA"
#define WKP "MARIO"

#define HANDSHAKE_BUFFER_SIZE 10
#define BUFFER_SIZE 1000

int server_setup();
int server_connect(int from_client);

int client_handshake();

#endif
