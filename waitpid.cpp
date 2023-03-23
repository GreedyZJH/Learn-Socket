#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
	int status;
	pid_t pid = fork();
	printf("pid %d \n",pid);
	if(pid == 0)
	{
		sleep(12);
		return 24;
	}
	else
	{
		printf("pid %d\n",pid);
		while(!waitpid(-1,&status,WNOHANG))
		{
			sleep(3);
			puts("sleep 3 sec.");
		}
		if(WIFEXITED(status))
		{
			printf("Child send %d \n",WEXITSTATUS(status));
		}
	}
}
