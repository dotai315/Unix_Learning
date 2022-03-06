#include "main.h"

struct msg_buffer {
    long msg_type;
    char msg_txt[500];
}message;

int main(int argc, char *argv[])
{
    key_t key;
    int msg_id; 

    key = ftok("/home/blackally/message_queue/progfile", 65);

    msg_id = msgget(key, IPC_CREAT);
    
    msgrcv(msg_id, &message, sizeof(message), 1, 0);

    printf("The msg that we have received is : %s\n", message.msg_txt);

    msgctl(msg_id, IPC_RMID, NULL);
    return 0;
}