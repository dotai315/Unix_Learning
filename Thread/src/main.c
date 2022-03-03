#include "main.h"

bool main_loop ;
bool thread_loop;

void sigint_handler()
{
	thread_loop = false;
}

void sigquit_handler()
{
	main_loop = false;
}

void *thread_rountine(void *args)
{
	while (thread_loop) {
		printf("thread\n");
		sleep(2);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t thread_1;
	
	main_loop = true;
	thread_loop = true;

	signal(SIGINT, sigint_handler);	
	signal(SIGQUIT, sigquit_handler);
	pthread_create(&thread_1, NULL, thread_rountine, NULL);

	while(main_loop) {
		printf("Main thread\n");
		sleep(1);
	}
	exit(EXIT_SUCCESS);
}
