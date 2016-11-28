#include<sys/shm.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
int main()
{
    void *shm = (void*)0;
    char buff[100];
    int shmid;
    shmid = shmget((key_t)2345,1000,0666|IPC_CREAT);//1000 size of memory in bytes
    printf("%d",shmid);
    shm = shmat(shmid,NULL,0);//0 can have arguments IPC_WRONLY or IPC_RDONLY
    printf("\nMemory Attached");
    read(0,buff,100);
    strcpy(shm,buff);
    printf("\nYou wrote %s",shm);
    shmdt(shm);
}
