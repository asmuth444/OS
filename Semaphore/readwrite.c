#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t mutex,wrt;
int data = 0, rcount = 0;

void *reader(void*);
void *writer(void*);

int main()
{
	int i;
	pthread_t read[5], write[5];
	sem_init(&mutex,0,1);
	sem_init(&wrt,0,1);
	for(i=0;i<=2;i++)
	{
		pthread_create(&write[i],NULL,writer,(void *)i);
		pthread_create(&read[i],NULL,reader,(void *)i);
	}
	for(i=0;i<=2;i++)
	{
		pthread_join(write[i],NULL);
		pthread_join(read[i],NULL);
	}
	return 0;
}

void *reader(void *arg)
{
	int id = (int)arg;
	sem_wait(&mutex);
	rcount++;
	if(rcount==1)
	{
		sem_wait(&wrt);
	}
	sem_post(&mutex);
	printf("\nData read by Thread%d: %d",id,data);
	sleep(1);
	sem_wait(&mutex);
	rcount--;
	if(rcount == 0)
	{
		sem_post(&wrt);
	}
	sem_post(&mutex);
}

void *writer(void *arg)
{
	int id = (int)arg;
	sem_wait(&wrt);
	data++;
	printf("\nData written by Thread%d: %d",id,data);
	sleep(1);
	sem_post(&wrt);
}
