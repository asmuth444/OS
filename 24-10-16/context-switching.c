#include<stdio.h>
#include<pthread.h>
int count = 0;
void *func(void *);
int main()
{
	pthread_t thread[3];
	int i=0;
	for(i=0;i<=2;i++)
	{
		pthread_create(&thread[i],NULL,func,(void*)i);
	}
	for(i=0;i<=2;i++)
	{
		pthread_join(thread[i],NULL);
	}
	printf("\nCount %d",count);
	return 0;
}

void *func(void *arg)
{
	int id = (int)arg;
	printf("\nRunning Thread%d",id);
	sleep(3);
	printf("\nThread%d Resumed",id);
	count++;
}
