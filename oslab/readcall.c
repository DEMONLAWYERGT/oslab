#include<dirent.h>
#include<stdio.h>
main()
{
DIR *dir;
struct dirent *entry; 
if((dir=opendir("/"))==NULL)
perror("Error during Opendir() error");
else
{
puts("contents of the current directory"); 
while((entry=readdir(dir))!=NULL)
printf("%s\n",entry->d_name); 
closedir(dir);
}
}
