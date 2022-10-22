#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int main(void)
{
	int fd[2], nbytes;
	pid_t pid;
	char string[] = "Hello, world!\n";
	char readbuffer[80];
	pipe(fd);
	if((pid = fork()) == -1) {
		perror("fork");
		exit(1);
	}
	if(pid>0) { //parent process
		close(fd[0]); // Close the input end of the pipe.
		// Write data to the pipe.
		write(fd[1], string, (strlen(string)+1));
		exit(0);
	}
	else { //child process
		close(fd[1]); // Close the output end of the pipe.
		// Read data from the pipe.
		nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		printf("Child process received string: %s", readbuffer);
	}
	return(0);
}
