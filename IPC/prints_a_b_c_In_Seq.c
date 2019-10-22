#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t cond1, cond2, cond3;

void t1()
{
	sem_wait(&cond1);
	fprintf(stderr, "%c", 'a');
	sem_post(&cond2);
}
void t2()
{
	sem_wait(&cond2);
	fprintf(stderr, "%c", 'b');
	sem_post(&cond3);
}
void t3()
{
	sem_wait(&cond3);
	fprintf(stderr, "%c", 'c');
	sem_post(&cond1);
	fprintf(stderr,"%c",'-');	
}

int main()
{
	pthread_t th1, th2, th3;
	int err;
	sem_init(&cond1, 0 ,1);
	sem_init(&cond2, 0 ,1);
	sem_init(&cond3, 0 ,1);

	while(1)
	{
		usleep(1000000);	
		err = pthread_create(&th1, NULL, &t1, NULL);
		usleep(1000000);	
		err = pthread_create(&th2, NULL, &t2, NULL);
		usleep(1000000);	
		err = pthread_create(&th3, NULL, &t3, NULL);
		usleep(1000000);
	}	

	return 0;
}
