#include "main.h"

int main(int argc, char *argv[])
{
	pid_t proc ;
	
	proc = fork();
	if (proc != 0) {
		printf("Parent\n");
	} else {
		printf("Child\n");
	}

	exit(EXIT_SUCCESS);
}
