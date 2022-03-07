#include "main.h"

int main(int argc, char *argv[])
{
    int sock_1, v_read;
    struct sockaddr_in address;
    char buffer[1024] = {0};
    char *hey = "Hey I am client!";

    if ((sock_1 = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket creation failure!\n");
        return -1;
    }
    
    address.sin_family = AF_INET;
    address.sin_port = htons( PORT );
    
    if (inet_pton(AF_INET, "127.0.0.1", &address.sin_addr) <= 0)
    {
        printf("Invalid IP Address\n");
        return -1;
    }

    if (connect(sock_1, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        printf("connection failure!\n");
        return -1;
    }    
    send(sock_1, hey, strlen(hey), 0);
    printf("Hello msg is sent: \n");
    v_read = read(sock_1, buffer, 1024);
    printf("buffer content: %s\n", buffer);
        
}