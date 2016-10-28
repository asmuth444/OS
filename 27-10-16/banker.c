#include<stdio.h>
#define RSIZE 9999
#define PSIZE 9999

int MAX[RSIZE][PSIZE],avail[RSIZE],alloc[RSIZE][PSIZE],need[RSIZE][PSIZE],resource,process,flag[PSIZE];
void readyNeedMatrix(int,int);
void readyFlagMatrix(int);
void getSafeState(int,int);
void matrixsum(int,int,int);
int main()
{
	printf("\nEnter no. of resources:");
	scanf("%d",&resource);
	printf("\nEnter no. of processes:");
	scanf("%d",&process);
	int i=0,j=0;
	readyFlagMatrix(process);
	for(i=0;i<resource;i++)
	{
		for(j=0;j<process;j++)
		{
			printf("\nEnter Maximum instances for resource %d and process %d:\n",i+1,j+1);
			scanf("%d",&MAX[i][j]);
		}
	}
	for(i=0;i<resource;i++)
	{
		for(j=0;j<process;j++)
		{
			printf("\nEnter allocated instances for resource %d and process %d:\n",i+1,j+1);
			scanf("%d",&alloc[i][j]);
		}
	}
	for(i=0;i<resource;i++)
	{
		printf("\nEnter available instances for resource %d:\n",i+1);
		scanf("%d",&avail[i]);
	}
	readyNeedMatrix(resource,process);
	getSafeState(resource,process);
	return 0;
}

void readyNeedMatrix(int n,int m)
{
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			need[i][j]=MAX[i][j]-alloc[i][j];
		}
	}
}

void readyFlagMatrix(int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		flag[i]=0;
	}
}

void getSafeState(int n,int m)
{
	int i=0,j=0;
	int check=1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(need[i][j]<=avail[j] && flag[i]==0)
			{
				check=1;
			}
			else
			{
				check=0;
			}
		}
		if(check)
		{
			matrixsum(n,j,i);
		}
	}
	for(i=0;i<m;i++)
	{
		if(flag[i])
		{
			printf("\nProcess %d is safe",i);
		}
		else
		{
			printf("\nProcess %d is not safe",i);
			check = 0;
		}
	}
	if(!check)
	{
		printf("\nSystem not Safe\n");
	}
	else
	{
		printf("\nSystem Safe\n");
	}
}

void matrixsum(int n,int j,int i)
{
	int k=0;
	for(k=0;k<n;k++)
	{
		avail[k]+=alloc[k][j];
	}
	flag[i]=1;
}
