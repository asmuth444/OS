#include<sys/types.h>
#include<stdio.h>
int main()
{
	int i;
	pid_t pid;
	pid = fork();
	if(pid<0)
	{
		printf("Error");
	}
	else if(pid==0)
	{
		i=10;
		printf("Child pid:%d\n",getpid());
		while(i<=20)
		{
			printf("%d\n",i);
			i++;
		}
	}
	else
	{
		i=20;	
		printf("Parent pid:%d\n",getpid());
		while(i<=30)
		{
			printf("%d\n",i);
			i++;
		}
	}
	return 0;
}
