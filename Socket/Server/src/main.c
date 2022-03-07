#include "main.h"

int main(int argc, char *argv[])
{
    int serv_fd, n_socket, v_read;
    struct sockaddr_in address;

    int opt = 1;
    int addr_length = sizeof(address);
    char buffer[1024] = {0};

    char *hey = "Hey I am server!";

    if ((serv_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failure!\n");
        exit(0);
    }
    
    if (setsockopt(serv_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt error\n");
        exit(0);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
    
    if (bind(serv_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failure\n");
        exit(0);
    }

    if (listen(serv_fd, 3) < 0) 
    {
        perror("listen error\n");
        exit(0);
    }

    if ((n_socket = accept(serv_fd, (struct sockaddr *)&address, (socklen_t *)&addr_length)) < 0)
    {
        perror("accept error\n");
        exit(0);
    }

    v_read = read(n_socket, buffer, 1024);
    printf("buffer content: %s\n", buffer);
    send(n_socket, hey, strlen(hey), 0);
    printf("Hello msg is sent: \n");
    
}
