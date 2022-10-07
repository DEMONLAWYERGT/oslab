#include<stdio.h>
#include<string.h>
void main()
{
int bt[10],st[10],wt[10],n,b[10],i,j,w=0,t=0,pp[10];
char a[10][10], temp,temp1[10];
float p,q;
int temp2,temp3;
printf("enter the number of process");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nenter the process name");
scanf("%s",a[i]);
printf("\n enter the cpu burst time");
scanf("%d",&b[i]);
printf("\n enter the priority");
scanf("%d",&pp[i]); 
}
for(i=0;i<n;i++)
{
        for(j=i+1;j<n;j++)
{
          
if(pp[i]>pp[j])
{
strcpy(temp1,a[i]);
strcpy(a[i],a[j]);
strcpy(a[j],temp1); 
temp2=b[i];
b[i]=b[j];
b[j]=temp2;
temp3=pp[i];
pp[i]=pp[j];
pp[j]=temp3;

} 
}
} 

st[0]=0;
wt[0]=0;
bt[0]=b[0];
for(j=1;j<n;j++)
{
st[j]=bt[j-1];
wt[j]=st[j];
bt[j]=st[j]+b[j];
}
printf("\n process name");
printf("\t\tstart time:");
printf("\t\tburst time:");
printf("\t\tprority:");
for(i=0;i<n;i++)
{
printf("\n%s",a[i]);
printf("\t%d\t%d%d\n",st[i],bt[i],pp[i]);
w=w+wt[i];
t=t+bt[i];
}
p=(float)w/n;
q=(float)t/n;
printf("\n avg waiting time:%f",p);
printf("\n avg turnaround time:%f\n",q);
}
