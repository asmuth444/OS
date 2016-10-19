#include<sys/types.h>
#include<stdio.h>
int main()
{
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
		printf("Error pid:%d\n",pid );
	}
	else if(pid==0)
	{
		printf("I am the child pid:%d\n",getpid());
		printf("Parent id: %d\n",getppid());
	}
	else
	{
		printf("I am the parent pid:%d\n",getpid());
		printf("Child id: %d\n",pid);
	}
	return 0;
}
