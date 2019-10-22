#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

//int sem_wait(sem_t *sem);
//int sem_post(sem_t *sem);
//int sem_init(sem_t *sem, int pshared, unsigned int val);
//int sem_destroy(sem_t *mutex);

#if 0
sem_t mutex;

void* thread(void *arg)
{
	//wait
	sem_wait(&mutex);
	printf("\n Entered..\n");
	//critical section
	sleep(4);
	//signal
	printf("\n Just Exiting...\n");
	sem_post(&mutex);
}



int main()
{
	sem_init(&mutex, 0, 1);
	pthread_t t1, t2;
	pthread_create(&t1, NULL, thread, NULL);
	sleep(2);
	pthread_create(&t2, NULL, thread, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	sem_destroy(&mutex);

	return 0;
}
#endif

/*The code below is the consumer-producer simulation(over a max-limit on container)*/

sem_t semP, semC;
int stock_count = 0;
const int stock_max_limit = 5;

void* producer(void *arg)
{
	int i, sum = 0;
	for(i = 0; i<10; i++)
	{
		while(stock_max_limit == stock_count)
		{
			printf("\nstock overflow, production on wait..\n");
			sem_wait(&semC);
			printf("\nproduction operation continues..\n");
		}

		sleep(1);//produnction decided here
		stock_count++;
		printf("\nProducer::\n");
		printf("\nP::stock-count : %d\n",stock_count);
		sem_post(&semP);
		printf("\nP::post signal..\n");
	}
}

void* consumer(void *arg)
{
int i, sum = 0;
for(i=0; i<10; i++)
{
	while(0 == stock_count)
	{
		printf("\nstock empty, consumer on wait..\n");
		sem_wait(&semP);
		printf("\nconsumer operation continues..\n");
	}
	sleep(2);//consumer rate decided here
	stock_count--;
	printf("\nConsumer::\n");
	printf("C:: stock-count : %d\n",stock_count);
	sem_post(&semC);
	printf("\nC::post signal..\n");
}



}

int main()
{
	sem_init(&semP, 0 , 0);
	sem_init(&semC, 0 , 0);

	pthread_t tid0, tid1;

	pthread_create(&tid0, NULL, consumer, NULL);
	pthread_create(&tid1, NULL, producer, NULL);

	pthread_join(tid0, NULL);
	pthread_join(tid1, NULL);

	sem_destroy(&semP);
	sem_destroy(&semC);

	return 0;

}
