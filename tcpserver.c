#include "tcping.h"

int main() {
  int from_client;
  int sd;

  sd = server_setup();

  while(1) {
    from_client = server_connect(sd);

    char * mess = malloc(BUFFER_SIZE);
    char * temp = malloc(BUFFER_SIZE);

    int f = fork();
    if (f == 0) {
      read(from_client, mess, BUFFER_SIZE);
      int i;
      for (i = strlen(mess) - 1; i >= 0; i--){
        if (*(mess + i) != 20){
          strncat(temp, mess + i, 1);
          strcat(temp, "!");
        }
      }
      write(sd, temp, BUFFER_SIZE);
      free(mess);
      free(temp);
      printf("Server: Client's requests have been fulfilled\n");
    } else {
      close(from_client);
    }
    exit(0);
  }
}
