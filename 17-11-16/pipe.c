#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
    char buff[100];
    int fd[2],n;
    pid_t p;
    pipe(fd);
    p = fork();
    if(p<0)
        printf("Process Error");
    else if(p>0)
    {
        close(fd[0]);
        printf("Passing value to child\n");
        write(fd[1],"hello",5);
        wait();
    }
    else
    {
        close(fd[1]);
        n=read(fd[0],buff,100);
        write(1,buff,n);
    }
    return 0;
}
