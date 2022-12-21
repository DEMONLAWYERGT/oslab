#include<stdio.h>
#include<string.h>
void main()
{
int bt[10],tt[10],wt[10],n,b[10],i,j,w=0,t=0;
char a[10];
float p,q;
printf("Enter the number of process:-\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter the process name:-\n");
scanf("%s",&a[i]);
printf("\nEnter the cpu burst time:-\n");
scanf("%d",&b[i]);
}
tt[0]=0;
wt[0]=0;
bt[0]=b[0];
for(j=1;j<n;j++)
{
tt[j]=bt[j-1];
wt[j]=tt[j];
bt[j]=tt[j]+b[j];
}
printf("\nProcess Name");
printf("\tWaiting Time:");
printf("\tTurnaround Time:");
for(i=0;i<n;i++)
{
printf("\n%c\t\t%d\t\t%d\n",a[i],tt[i],bt[i]);
w=w+wt[i];
t=t+bt[i];
}
p=(float)w/n;
q=(float)t/n;
printf("\nAvg Waiting Time:- %f",p);
printf("\nAvg Turnaround Time:- %f\n",q);
}
