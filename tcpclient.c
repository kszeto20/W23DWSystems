#include "tcping.h"

int main() {

  int socket = client_handshake();

  while (1){

    char *in = malloc(BUFFER_SIZE);
    printf("Send the server something: ");

    fgets(in, BUFFER_SIZE, stdin);
    printf("Client: got %s\n", in);
    write(socket, in, BUFFER_SIZE);
    printf("Client: Wrote %s\n", in);

    char *out = malloc(BUFFER_SIZE);
    read(socket, out, BUFFER_SIZE);
    printf("Client: Got back from server: %s\n", out);
    free(in);
    free(out);
  }

  return 0;
}
