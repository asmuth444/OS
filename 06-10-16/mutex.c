#include<pthread.h>
#include<stdio.h>
void *func1();
void *func2();
int count = 1;
pthread_mutex_t l;
int main()
{
	pthread_mutex_init(&l,NULL);
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
	pthread_mutex_lock(&l);
        int x;
        x=count;
        x+=1;
        sleep(1);//Error introduced
        count=x;
	pthread_mutex_unlock(&l);
}
void *func2()
{
        pthread_mutex_lock(&l);
        int y;
        y=count;
        y-=1;
        sleep(1);//Error introduced
        count=y;
        pthread_mutex_unlock(&l);
}

