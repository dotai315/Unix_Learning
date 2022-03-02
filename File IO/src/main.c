#include "main.h"

bool getString_loop = true;

void endGetString()
{
	getString_loop = false;
}

int main(int argc, char *argv[])
{
	int* inputFd = NULL;
	char str[1024];

	if (argc < 2) {
		fprintf(stderr, "usage: file_no [FILES]\n");
		exit(EXIT_FAILURE);
	}
	
	inputFd = (int*)malloc((argc - 1) * sizeof(int));
	
	signal(SIGINT, endGetString);

	for (int i = 0; i < (argc - 1); i++) {
		*(inputFd + i) = open(argv[i + 1], O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG | S_IRWXO);
		if (*(inputFd + i ) < 0) {
			fprintf(stderr, "open file %s error\n", argv[i + 1]);
			exit(EXIT_FAILURE);
		}
	}
	
	while (getString_loop) {
		fgets(str, sizeof(str), stdin);
		for (int i = 0; i < (argc - 1); i++) {
			if (write(*(inputFd + i), str, strlen(str)) < 0) {
				fprintf(stderr, "write file %s error\n", argv[i + 1]);
				exit(EXIT_FAILURE);
			}
		}
		memset(str, '\0', sizeof(str));
	}

	for (int i = 0; i < (argc - 1); i++) {
		if (close(*(inputFd + i)) < 0) {
			fprintf(stderr, "close file %s error\n", argv[i + 1]);
			exit(EXIT_FAILURE);
		}
	}

	exit(EXIT_SUCCESS);
}
