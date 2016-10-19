#include<sys/types.h>
#include<stdio.h>
int main()
{
	pid_t pid1, pid2;
	int n,fact=1,i=1;
	printf("Enter a no.:\n");
	scanf("%d",&n);
	pid1 = fork();
	if(pid1 < 0)
	{
		printf("\nError creating child1");
	}
	else if(pid1 == 0)
	{
		printf("\nChild1 pid:%d",getpid());
		while(i <= n)
		{
			fact *= i;
			i++;	
		}
		printf("\nFactorial of %d is %d",n,fact);
	}
	else
	{
		pid2 =fork();
		if(pid2 < 0)
		{
			printf("\nError creating child2");	
		}
		else if(pid2 == 0)
		{
			printf("\nChild2 pid:%d",getpid());
			if(n%2==0)
			{
				printf("\n%d is even",n);
			}
			else
			{
				printf("\n%d is odd",n);
			}
		}
		else
		{
			printf("\nParent pid:%d",getpid());
		}
	}
	return 0;
}
