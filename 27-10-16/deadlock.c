#include<pthread.h>
#include<stdio.h>
pthread_mutex_t lock[2];
void *func1();
void *func2();
int main()
{
	int i=0;
	pthread_t thread[2];
	for(i=0;i<=1;i++)
	{
		pthread_mutex_init(&lock[i],NULL);
	}
	pthread_create(&thread[0],NULL,func1,NULL);
	pthread_create(&thread[1],NULL,func2,NULL);
	for(i=0;i<=1;i++)
	{
		pthread_join(thread[i],NULL);
	}
	return 0;
}

void *func1()
{
	printf("\nLocking Thread 1 Lock=1");
	pthread_mutex_lock(&lock[0]);
	sleep(2);
	printf("\nLocking Thread 1 Lock=2");
	pthread_mutex_lock(&lock[1]);
	pthread_mutex_unlock(&lock[0]);
}
void *func2()
{
	printf("\nLocking Thread 2 Lock=2");
	pthread_mutex_lock(&lock[1]);
	sleep(2);
	printf("\nLocking Thread 2 Lock=1");
	pthread_mutex_lock(&lock[0]);
	pthread_mutex_unlock(&lock[1]);
}
