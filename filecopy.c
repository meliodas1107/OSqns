#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include<unistd.h>
#include <stdlib.h>
#include<stdio.h>

int main()
{
	int p[2];
	if(pipe(p)<0)
		exit(1);
	ssize_t size=0;
	int fd_input,fd_out;
	size_t max=50;
	char inputFile[20],destFile[20],buff[50];
	printf("Enter the name of the input file and the destination file : \n");
	scanf("%s %s",&inputFile,&destFile);
	printf("\n%s %s are the values entered  \n",inputFile,destFile);



	pid_t pid=fork();
	if(pid<0)
	{
		printf("Fork unsuccessful\n");
		exit(1);
	}
	else if(pid==0)
	{
		
		//child process
		size=read(p[0],buff,max);
		fd_out=open(destFile,O_WRONLY | O_CREAT);
		write(fd_out,buff,size);
		printf("Exiting child process  with id %d and parent id %d\n",getpid(),getppid() );
		exit(0);

	}
	else
	{

		//parent process
		fd_input=open(inputFile,O_RDONLY);
		printf("Hi\n");
		size= read(fd_input,buff,max);
		write(p[1],buff,size);
		wait(NULL);
		printf("Successfully copied the file contents. process id is %d \n",getpid() );

	}
}	
