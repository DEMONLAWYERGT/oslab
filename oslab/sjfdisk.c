#include<stdio.h>
#include<string.h>
void main()
{
 int n,i,ct[10],wt,st,bt,temp,j;
float tb,tw;
wt=0;
st=0;
bt=0;
tb=0;
tw=0;
char proc[10][10],ta[10];
printf("Enter the no of process:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nenter process name:");
scanf("%s",proc[i]);
printf("Enter the cpu time:");
scanf("%d",&ct[i]);
}

for(i=0;i<n;i++)
{
for(j=i;j<n-i-1;j++)
{
if(ct[j]>ct[j+1])
{
temp=ct[j];
ct[j]=ct[j+1];
ct[j+1]=temp;
strcpy(ta,proc[j]);
strcpy(proc[j],proc[j+1]);
strcpy(proc[j+1],ta);
}
}
}

for(i=0;i<n;i++)
{
printf("%s\t",proc[i]);
printf("%d\t",ct[i]);
}
printf("\nProcess name\tStart Time\tWait time\tBurst Time\n");
for(i=0;i<n;i++)
{
st=bt;
wt=st;
bt=bt+ct[i];
printf("%s\t\t%d\t\t%d\t\t%d\n",proc[i],st,wt,bt);
tw=tw+wt;
tb=tb+bt;
}
printf("\naverage waiting time=%f\n",(tw/n));
printf("\nAverage turn around time=%f\n",(tb/n));
}

