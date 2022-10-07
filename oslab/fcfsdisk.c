#include<stdio.h>
#include<string.h>
void main()
{
int bt[10],tt[10],wt[10],n,b[10],i,j,w=0,t=0;
char a[10];
float p,q;
printf("enter the number of process");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nenter the process name");
scanf("%s",&a[i]);
printf("\n enter the cpu burst time");
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
printf("\n process name");
printf("\t\tWaiting time:");
printf("\t\tTurnaround time:");
for(i=0;i<n;i++)
{
printf("\n%c\t%d\t%d\n",a[i],tt[i],bt[i]);
w=w+wt[i];
t=t+bt[i];
}
p=(float)w/n;
q=(float)t/n;
printf("\n avg waiting time:%f",p);
printf("\n avg turnaround time:%f\n",q);
}
