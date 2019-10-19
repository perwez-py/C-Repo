#include<stdio.h>
#include<pthread.h>

void *threadFunc(void *args);
int main()
{
	pthread_t tid;
	int ret, i = 0;

	ret = pthread_create(&tid, NULL, threadFunc, "Processing...");

	if(ret == 0)
		printf("Thread created successfully\n");
	else
	{
		printf("Thread creation failed");
		return 0;
	}

	pthread_join(tid, NULL);

	while(i < 10)
	{
		usleep(1);
		printf("main() is running...\n");
		++i;
	}

	return 0;
}

void *threadFunc(void *args)
{
	char *str;
	int i = 0;

	str = (char *)args;
	while(i <= 10)
	{
		usleep(1);
		printf("Thread function says: %s\n",str);
		++i;
	}

	return NULL;
}

