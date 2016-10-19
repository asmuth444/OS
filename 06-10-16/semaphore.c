#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
void *func1();
void *func2();
int count = 1;
sem_t s;
int main()
{
	sem_init(&s,0,1);
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
	sem_wait(&s);
        int x;
        x=count;
        x+=1;
        sleep(1);//Error introduced
        count=x;
	sem_post(&s);
}
void *func2()
{
        sem_wait(&s);
        int y;
        y=count;
        y-=1;
        sleep(1);//Error introduced
        count=y;
        sem_post(&s);
}

