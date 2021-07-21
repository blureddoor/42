#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define PORTNUMBER 12563

int main(void) {
    char buf[1024];
    int s, n, ns, len;
    struct sockaddr_in name;
    
    /* Se crea el socket */
    s = socket (PF_INET, SOCK_STREAM, 0);
    name.sin_family = AF_INET;
    name.sin_port = htons(PORTNUMBER);
    name.sin_addr.s_addr =htonl(INADDR_ANY);
    len = sizeof(struct sockaddr_in);
    
    /*Se publica la dirección y el puerto por el que
     se va a escuchar*/
    
    bind(s,(struct sockaddr *)&name, len);
    
    /*Escucha de peticiones*/
    
    listen(s, 5);
    
    /*aceptar conexiones*/
    ns = accept(s, (struct socket *)&name, &len);
    memset(&buf, '\0', sizeof(buf));
    
    /*Se lee el socket hasta el final del fichero*/
    while ((n = recv(ns, buf, sizeof(buf), 0))>0)
        /*se imprime lo que vayas leyendo*/
        printf("%s",buf);
    /*se cierran las conexiones*/
    close(ns);
    close(s);
 return(EXIT_SUCCESS);
}
