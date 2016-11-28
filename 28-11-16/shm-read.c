#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main()
{
    void *shm = (void*)0;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)2345,1000,0666);
    printf("%d",shmid);
    shm = shmat(shmid,NULL,0);//0 can have arguments IPC_WRONLY or IPC_RDONLY
    printf("\nMemory Attached");
    printf("\nYou wrote %s",shm);
    shmdt(shm);
}
