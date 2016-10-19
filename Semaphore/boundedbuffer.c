#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#define SIZE 10
pthread_mutex_t mutex;
sem_t full,empty;
pthread_t producer[5],consumer[5];
int counter,buffer[SIZE];
void *produce(void*);
void *consume(void*);

int main()
{
	pthread_mutex_init(&mutex,NULL);
	sem_init(&full,1,0);
	sem_init(&empty,1,SIZE);
	counter=0;
	int i=0;
	for(i=0;i<=2;i++)
	{
		pthread_create(&producer[i],NULL,produce,NULL);
		pthread_create(&consumer[i],NULL,consume,NULL);

	}
	for(i=0;i<=2;i++)
	{
		pthread_join(producer[i],NULL);
		pthread_join(consumer[i],NULL);
	}
	return 0;
}

void *produce(void *arg)
{
	int item = rand()%5;
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	printf("\nProducer produced:%d",item);
	buffer[counter++]=item;
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
}

void *consume(void *arg)
{
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	int item=buffer[--counter];
	printf("\nConsumer consumed:%d",item);
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
}
