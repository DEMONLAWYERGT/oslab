#include<stdio.h>
#include<stdlib.h>

void implimentFirstFit(int blockSize[], int blocks, int processSize[], int processes)
{
int allocate[processes];
int occupied[blocks],i,j;
for(i = 0; i < processes; i++)
{
allocate[i] = -1;
}
for(i = 0; i < blocks; i++)
{
occupied[i] = 0;
}
for (i = 0; i < processes; i++)
{
for (j = 0; j < blocks; j++)
{
if(!occupied[j] && blockSize[j] >= processSize[i])
{
allocate[i] = j;
occupied[j] = 1;
break;
}
}
}
printf("\nProcess No.\t\tProcess Size\t\tBlock no.\n");
for (i = 0; i < processes; i++)
{
printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
if (allocate[i] != -1)
printf("%d\n",allocate[i] + 1);
else
printf("Not Allocated\n");
}}
void implimentBestFit(int blockSize[], int blocks, int processSize[], int proccesses)
{
int allocation[proccesses];
int occupied[blocks],i,j;
for(i = 0; i < proccesses; i++)
{
allocation[i] = -1;
}
for(i = 0; i < blocks; i++)
{
occupied[i] = 0;
}
for(i = 0; i < proccesses; i++)
{
int indexPlaced = -1;
for (j = 0; j < blocks; j++)
{
if (blockSize[j] >= processSize[i] && !occupied[j])
{
if (indexPlaced == -1)
indexPlaced = j;
else if (blockSize[j] < blockSize[indexPlaced])
indexPlaced = j;
}}
if (indexPlaced != -1)
{
allocation[i] = indexPlaced;
occupied[indexPlaced] = 1;
}}
printf("\nProcess No.\t\tProcess Size\t\tBlock no.\n");
for (i = 0; i < proccesses; i++)
{
printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
if (allocation[i] != -1)
printf("%d\n",allocation[i] + 1);
else
printf("Not Allocated\n");
}
}
 void implimentWorstFit(int blockSize[], int blocks, int processSize[], int processes)
{
int allocation[processes];
int occupied[blocks],i,j;
for(i = 0; i < processes; i++)
{
allocation[i] = -1;
}
for(i = 0; i < blocks; i++)
{
occupied[i] = 0;
}
for (i=0; i < processes; i++)
{
int indexPlaced = -1;
for(j = 0; j < blocks; j++)
{
if(blockSize[j] >= processSize[i] && !occupied[j])
{
if (indexPlaced == -1)
indexPlaced = j;
else if (blockSize[indexPlaced] < blockSize[j])
indexPlaced = j;
}
}
if (indexPlaced != -1)
{
allocation[i] = indexPlaced;
occupied[indexPlaced] = 1;
blockSize[indexPlaced] -= processSize[i];
}
}
printf("\nProcess No.\t\tProcess Size\t\tBlock no.\n");
for (i = 0; i < processes; i++)
{
printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
if (allocation[i] != -1)
printf("%d\n",allocation[i] + 1);
else
printf("Not Allocated\n");
	}
}

int main()
{
	int m,n,choice,v,z;
	printf("Enter the block size:");
	scanf("%d",&m);
	int blockSize[m];
	printf("Enter the blocks:");
	for(z=0;z<m;z++)
	{
		scanf("%d",&blockSize[z]);
	}
	
	printf("Enter the number of processes:");
	scanf("%d",&n);
	int processSize[n];
	printf("Enter the processes:");
	for(v=0;v<n;v++)
	{
		scanf("%d",&processSize[v]);
	}
	do
	{
		printf("\n 1.First Fit\t 2.Best Fit\t3.Worst Fit\t4.EXIT");
		printf("\nEnter your choice :- ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Memory allocation using First Fit!");
				implimentFirstFit(blockSize, m, processSize, n);
				break;
			case 2:
				printf("Memory allocation using Best Fit!");
				implimentBestFit(blockSize, m, processSize, n);
				break;
			case 3:
				printf("Memory allocation using Worst Fit!");
				implimentWorstFit(blockSize, m, processSize, n);
				break;
			case 4:
				printf("Exiting program.......!!!!!");
;				exit(0);
			default:
				printf("Enter a vaild choice");
		}
               
        }while(choice!=6);
	return 0;
}
