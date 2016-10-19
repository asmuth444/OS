#include<pthread.h>
#include<stdio.h>
//int a;
void* newthread(void *arg)
{
	printf("\nNew thread %d",(int)arg);
	(int)arg++;
	pthread_exit(arg);
}
int main()
{
	int a;
	pthread_t t1;
	void* result;
	printf("Enter a No.:");
	scanf("%d",&a);
	pthread_create(&t1, NULL,newthread,(void*)a);
	printf("Orignal thread finished");
	pthread_join(t1,&result);
	printf("\nValue recieved from new thread : %d",(void*)result);
	return 0;
}
