#include<stdio.h>
#include<unistd.h>
int main()
{
int pid,status;
pid=fork();
if(pid==-1)
{
perror("Error fork()");
}
else if (pid==0)
{
printf("I am the child process\n");
printf("Process id of child is= %d\n",getpid());
execlp("pwd","pwd",NULL);
}
else
{
printf("I am the parent process\n");
}
return 0;
}

