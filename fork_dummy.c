#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	int status;
	printf("hello world (pid: %d)\n", (int) getpid());

	int rc = fork();
	if (rc < 0) {
		// fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		// child process
		printf("Hello, I'm the child process (pid: %d)\n", (int) getpid());
	} else {
		// parent goes down this path (main)
		// Comment or uncomment the next line to udnetstand the wait call.
		waitpid(rc, &status, 0);
		printf("Well, hello there, I'm sure you didn't forget about the parent process, (rc: %d) (pid: %d)\n", rc, getpid());
	}
}
