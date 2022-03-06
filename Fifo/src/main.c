#include "main.h"

int main(int argc, char *argv[])
{
    char myfifo[] = "myfifo";
    char out[100] = "This is FIFO and this is linux";
    char in[100];
    int rf, wf;

    if (mkfifo(myfifo, S_IRWXU | S_IRWXG | S_IRWXO) == -1) {
        if(errno != EEXIST) {
            perror("mkfifo error\n");
            return 1;
        }
    }
    
    wf = open(myfifo, O_WRONLY | O_NONBLOCK);
    if (wf < 0) {
        perror("open() error\n");
        return -1;
    }

    write(wf, out, strlen(out) + 1);
    close(wf);

    rf = open(myfifo, O_RDONLY);
    if (rf < 0) {
        perror("open() error\n");
    }

    read(myfifo, in, sizeof(in));

    printf("Read: %s\n", in);

    close (rf);
    unlink(myfifo);
    return 0;
}