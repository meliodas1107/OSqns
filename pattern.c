#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<sys/wait.h>

int main()
{

	int num=1;
	printf("Enter a number which is of the form of the power of 2 :");
	scanf ("%d",&num);
	printf("\nThe entered number is : %d \nNow the process will start \n",num);
	pid_t pid=fork();
	if(pid<0)
	{
		printf("Process creation Unsuccessful  \n");
	}
	else if (pid==0)
	{
		sleep(1);
		printf("Child process  with process id %d is starting ....\nThe parent process of this child has id :%d\n",getpid(),getppid());
		while (num>=1)
		{
			printf("%d\n",num);
			num/=2;
		}
		printf("Child process is exiting now ...\n");
		exit(0);

	}
	else
	{
		printf("Parent waiting for the child ....\n");
		wait(NULL);
		printf("Parent process with process id %d \nParent process now exiting ...\n",getpid() );
	}


}
