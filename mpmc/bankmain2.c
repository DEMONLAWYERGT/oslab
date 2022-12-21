#include<stdio.h>
int pno,res;
int allocation[20][10],max[10][10],need[20][10],available[10],work[10],i,j;
int check()
{
 int flag=0;
 for(i=0;i<pno;i++)
 {
 for(j=0;j<res;j++)
 if(need[i][j]!=0)
 {
 flag=1;
 break;
 }
 }
return flag;
}
int main()
{
 printf("\nEnter number of process and resources respectively:- \n");
 scanf("%d%d",&pno,&res);
 printf("\nEnter allocation matrix :- \n");
 for(i=0;i<pno;i++)
 {
 printf("Enter row %d:- \n",i+1);
 for(j=0;j<res;j++)
 scanf("%d",&allocation[i][j]);
 }
 printf("\nEnter max matrix :- \n");
 for(i=0;i<pno;i++)
 {
 printf("Enter row %d\n",i+1);
 for(j=0;j<res;j++)
 scanf("%d",&max[i][j]);
 }
 printf("\nAllocation matrix is :-\n");
 for(i=0;i<pno;i++)
 {
 for(j=0;j<res;j++)
 printf("%d\t",allocation[i][j]);
 printf("\n");
 }
 printf("\nMax matrix is :- \n");
 for(i=0;i<pno;i++)
 {
 for(j=0;j<res;j++)
 printf("%d\t",max[i][j]);
 printf("\n");
 }
 printf("\nEnter available resource :- \n");
 for(i=0;i<res;i++)
 scanf("%d",&available[i]);
 for(i=0;i<pno;i++)
 for(j=0;j<res;j++)
 need[i][j]= max[i][j]-allocation[i][j];
 for(i=0;i<res;i++)
 work[i]=available[i];
printf("Max Matrix:-\n");
for(i=0;i<pno;i++)
 {
 for(j=0;j<res;j++)
 printf("%d\t",need[i][j]);
 printf("\n");
 }
 int flag=0,flag1=0;
 do
 {
 for(i=0;i<pno;i++)
 {flag=0;
 for(j=0;j<res;j++)
 {
 if(need[i][j]!=0)
 flag=1;
 }
 if(flag==1)
 {
 for(j=0;j<res;j++)
 {
 if(need[i][j]>work[j])
 flag=0;
 }
 if(flag==1)
 {
 for(j=0;j<res;j++)
 {
 work[j]+=need[i][j];
 need[i][j]=0;
 }
 printf("P%d -> ",i+1);
 }}}}
while(check()==1);
printf(" is the safe state.\n");
while(check()==0);
printf(" is the unsafe state.\n");
return 0;
 }
