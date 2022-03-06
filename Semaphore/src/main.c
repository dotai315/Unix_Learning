#include "main.h"

#define KEY 0x1111

union semun {
    int value;
    struct semid_ds *buf;
    unsigned short *arr;
};

struct sembuf a = {0, -1, SEM_UNDO};
struct sembuf b = {0, +1, SEM_UNDO};

int main(void)
{
    int id = semget(KEY, 1, 0666 | IPC_CREAT);
    if (id < 0) {
        perror("semget\n");
        exit(0);
    }
    union semun su;
    su.value = 1;

    if(semctl(id, 0, SETVAL, su) < 0) {
        perror("semctl error");
        exit(0);
    }

    int pid;

    pid = fork();
    srand(pid);

    if (pid < 0) {
        perror("fork error\n");
        exit(0);
    } else if (pid) {
        char *se = "abc";
        int l = strlen(se);

        for (int i = 0; i < l; i++) {
            if (semop(id, &a, 1) < 0) {
                perror("semop error with a\n");
                exit(0);
            } 
            putchar(se[i]);
            fflush(stdout);
            sleep(1);
            putchar(se[i]);
            fflush(stdout);
            if (semop(id, &b, 1) < 0) {
                perror("semop error with b\n");
                exit(0);
            }

            sleep(1);
        }
    } else {
        char *se = "abc";
        int l = strlen(se);

        for (int i = 0; i < l; i++) {
            if (semop(id, &a, 1) < 0) {
                perror("semop error with a\n");
                exit(0);
            } 
            putchar(se[i]);
            fflush(stdout);
            sleep(1);
            putchar(se[i]);
            fflush(stdout);
            if (semop(id, &b, 1) < 0) {
                perror("semop error with b\n");
                exit(0);
            }

            sleep(1);
        }       
    }
    return 0;
}
