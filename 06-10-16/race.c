#include<pthread.h>
#include<stdio.h>
void *func1();
void *func2();
int count = 1;
int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,&func1,NULL);
	pthread_create(&t2,NULL,&func2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("%d",count);
	return 0;
}
void *func1()
{
	int x;
	x=count;
	x+=1;
	sleep(1);//Error introduced
	count=x;
}
void *func2()
{
        int y;
        y=count;
        y-=1;
	sleep(1);//Error introduced
        count=y;
}
