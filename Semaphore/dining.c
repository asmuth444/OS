#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define LEFT (i+4)%5
#define RIGHT (i+1)%5
sem_t mutex,self[5];
enum{THINKING,HUNGRY,EATING} state[5];
int i[5]={0,1,2,3,4};
void pickup(int);
void putdown(int);
void test(int);
void *philospher(void *num);
int main()
{
	int j;
	pthread_t thread_id[5];
	sem_init(&mutex,0,1);
	for(j=0;j<5;j++)
	{
		sem_init(&self[j],0,0);
	}
	for(j=0;j<5;j++)
	{
		pthread_create(&thread_id[j],NULL,philospher,&i[j]);
		printf("Philospher %d is Thinking\n",j+1);
	}
	for(j=0;j<5;j++)
	{
		pthread_join(thread_id[j],NULL);
	}
}

void *philospher(void *num)
{
	while(1)
	{
		int *i = num;
		sleep(1);
		pickup(*i);
		sleep(0);
		putdown(*i);
	}
}

void pickup(int i)
{
	sem_wait(&mutex);
	state[i]=HUNGRY;
	printf("Philospher %d is Hungry\n",i+1);
	test(i);
	sem_post(&mutex);
	sem_wait(&self[i]);
	sleep(1);
}

void putdown(int i)
{
	sem_wait(&mutex);
	state[i]=THINKING;
	sleep(2);
	printf("Philospher %d putting fork %d and %d down\n",i+1,LEFT+1,i+1);
	printf("Philospher %d is Thinking\n",i+1);
	test(LEFT);
	test(RIGHT);
	sem_post(&mutex);
}

void test(int i)
{
	if(state[(i+4)%5]!=EATING && state[i]==HUNGRY && state[(i+1)%5]!=EATING)
	{
		sleep(2);
		printf("Philospher %d takes fork %d and %d\n",i+1,LEFT+1,i+1);
		printf("Philospher %d is Eating\n",i+1);
		state[i]=EATING;
		sem_post(&self[i]);
	}
}
