#include<stdio.h>
void fifo();
void lru();
int m,n,p[20],a[20];
void main()
{
	int i,j,c;
	printf("\nEnter the no. of process and no. of frames");
       scanf("%d%d",&n,&m);
       printf("\nEnter the processes nos.\n");
       for(i=0;i<n;i++)
       {
	       scanf("%d",&p[i]);
	       a[i]=-1;
       }
       printf("Enter your choice 1.fifo 2.lru");
       scanf("%d",&c);
       switch(c)
       {
		case 1:fifo();
		      break;
		case 2:lru();
		      break;
	}
}
void fifo()
{
	int i,j=0,k,flag,count=0;
	for(i=0;i<n;i++)
	{
		flag=0;
		for(k=0;k<m;k++)
		{
			if(a[k]==p[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			if(j==m)
			{
				for(k=1;k<m;k++)
				{
					a[k-1]=a[k];
				}
				j--;
			}
			a[j]=p[i];
			count++;
			j++;
		}
	}
	printf("\nthe no. of page faults are:%d",count);
}
void lru()
{
	int i,l=0,y,j=0,k,x[10],count=0,q,flag=0;
	for(i=0;i<n;i++)
	{
		flag=0;
		if(m==j)
		{
			for(k=0;k<l;k++)
			{
				if(x[k]==p[i])
				{
					for(y=k+1;y<l;y++)
					{
						x[y-1]=x[y];
					}
					x[l-1]=p[i];
					flag=1;
					break;
				}
			}
				for(k=0;k<l;k++)
				{
					if(flag==0)
					{
					for(y=0;y<j;y++)
					{
						if(x[k]==a[y])
						{
							for(q=k+1;q<l;q++)
							{
								x[q-1]=x[q];
							}
							for(q=y+1;q<j;q++)
							{
								a[q-1]=a[q];
							}
							x[l-1]=p[i];
							a[j-1]=p[i];
							count++;
							flag=1;
							break;
						}
					}
				}
			}
		}
		else
		{
			x[l]=p[i];
			l++;
			a[j]=p[i];
			j++;
			count++;
		}
	}
	printf("the no. of page faults are:%d",count);
}




		
