//PIPE 
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(int argc,char const *argv[])
{
pid_t id;
char buff[20];
int fd[2];
pipe (fd);

//fd[0]=reading data
//fd[1]=writining data

id=fork();
if(0==id)
{
    printf("Child:Reading data\n");
    read(fd[0],buff,20);
    printf("Read data is:%s/n",buff);
}
else{
    printf("Parent:writng data\n");
    write(fd[1],"DESD/n",5);
    printf("Parent writing completed");

}
return 0;
}