#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void* tryThis(void *args);
pthread_mutex_t lock;
pthread_t tid[2];
int counter;

int main()
{	
	int i = 0, error;

	if(pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("mutex init has failed\n");
		return 1;
	}
	
	while(i < 2)
	{
		error = pthread_create(&(tid[i]), NULL, &tryThis, NULL);
		if(error != 0)
		{
			printf("Thread creation failed: [%s]\n",strerror(error));
		}
		i++;
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	pthread_mutex_destroy(&lock);

	return 0;	
}

void* tryThis(void *args)
{
	pthread_mutex_lock(&lock);

	unsigned long i = 0;
	counter += 1;

	printf("\n job %d started\n",counter);

	for(i = 0; i < 2; i++)
	
	printf("\n job %d finished\n",counter);

	pthread_mutex_unlock(&lock);

	return NULL;

}
