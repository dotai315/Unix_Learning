#include "main.h"

int main(int argc, char *argv[])
{
    char buff[BUFFER_SIZE];
    FILE *fp = popen("ls", "r");
    while (fgets(buff, BUFFER_SIZE, fp))
    {
        printf("LS:%s", buff);
    }
    
    pclose(fp);

    return 0;
}