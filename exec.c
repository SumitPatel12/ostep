#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc, char *argv[]) {
	printf("Hello World (pid: %d)\n", (int) getpid());
	int rc = fork();

	if (rc < 0) {
		// fork failed
		fprintf(stderr, "fork failed\n");
	} else if (rc == 0) {
		printf("Child: (pid: %d)\n", (int) getpid());
		char *myargs[3];
		myargs[0] = strdup("wc");		// Program: "wc" word count.
		myargs[1] = strdup("exec.c");	// Argument: file to count.
		myargs[2] = NULL;				// Marks end of the array.
		execvp(myargs[0], myargs);		// Runs word count.
		printf("This should not print out if it does better call your exorcoist.\n");
	} else {
		int rc_wait = wait(NULL);
		printf("Parent of %d (rc_wait: %d) (pid: %d)", rc, rc_wait, (int) getpid());
	}

	return 0;
}
