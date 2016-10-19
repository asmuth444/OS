#include<pthread.h>
#include<stdio.h>
void *allsum(void *arg)
{
	int i=1,sum=0;
	//printf("\narg=%d",(int)arg);
	while(i<=(int)arg)
	{
		sum+=i;
		i++;
	}
	pthread_exit((void*)sum);
}
int main()
{
	pthread_t t;
	int n;
	void* sum;
	printf("Enter a no. :");
	scanf("%d",&n);
	pthread_create(&t,NULL,allsum,(void*)n);
	printf("Starting new thread");
	pthread_join(t,&sum);
	printf("\nThe sum is %d",(int)sum);
	printf("\nEnd");
}
