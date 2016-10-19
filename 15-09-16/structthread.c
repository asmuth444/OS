#include<stdio.h>
#include<pthread.h>
struct add
{
	int first,second;
}s1;

void *func(void *arg)
{
	struct add *s2; 
	s2 = (struct add*)arg;
	int sum;
	//printf("%d%d",s2->first,s2->second);
	sum = s2->first + s2->second;
	pthread_exit((void*)sum);
}

int main()
{
	pthread_t t;
	void* result;
	printf("Enter two  nos. :");
	scanf("%d",&s1.first);
	scanf("%d",&s1.second);
	pthread_create(&t,NULL,func,&s1);
	printf("\nStarting New thread:");
	pthread_join(t,&result);
	printf("Sum is %d",(int)result);
	return 0;
}
