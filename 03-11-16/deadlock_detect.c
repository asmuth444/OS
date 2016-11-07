#include<stdio.h>
int alloc[3][3], avail[3], need[3][3], request[3], max[3][3], flag[3], seq[3];
void check();
int main()
{
	int i=0,j=0,clear=1;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			printf("Enter instances for allocation matrix for process %d and resource %d: ",i,j);
			scanf("%d",&alloc[i][j]);
		}
	}
	for(i=0;i<=2;i++)
        {
                for(j=0;j<=2;j++)
                {
                        printf("Enter instances for max matrix for process %d and resource %d: ",i,j);
                        scanf("%d",&max[i][j]);
			need[i][j]=max[i][j]-alloc[i][j];
                }
        }
        for(i=0;i<=2;i++)
        {
                printf("Enter instances for available matrix for resource %d : ",i);
                scanf("%d",&avail[i]);
		flag[i]=0;
        }
	check();
	for(i=0;i<=2;i++)
	{
			if(flag[i]==0)
			{
				printf("\nSystem not safe");
				clear = 0;
				break;
			}
	}
	if(clear!=0)
	{
		printf("\nSafe Sequence:");
		for(i=0;i<=2;i++)
		{
			printf("\n%d",seq[i]);
		}
	}
	return 0;
}

void check()
{
	int k=0,i=0,j=0,c=0,l=0,h=0;
	for(k=0;k<=2;k++)
	{
		for(i=0;i<=2;i++)
		{
			l=0;
			for(j=0;j<=2;j++)
			{
				if(flag[i]==0 && need[i][j]<=avail[j])
				{
					l++;
				}
			}
			if(l==3)
			{
				for(h=0;h<=2;h++)
                                {
                                        avail[h]+=alloc[i][h];
                                }
				flag[i]=1;
				seq[c]=i;
				c++;
			}
		}
	}
}
