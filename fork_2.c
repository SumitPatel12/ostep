#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]) {
	int status;
	int x = 2;
	FILE *f = fopen("test.txt", "w");
	printf("hello world (pid: %d)\n", (int) getpid());

	int rc = fork();
	if (rc < 0) {
		// fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) {
		// child process
		x += 3;
		fprintf(f, "Hello, I'm the child process (pid: %d). x: %d\n", (int) getpid(), x);
	} else {
		// parent goes down this path (main)
		// Comment or uncomment the next line to udnetstand the wait call.
		x += 5;
		// waitpid(rc, &status, 0);
		fprintf(f, "Well, hello there, I'm sure you didn't forget about the parent process, (rc: %d) (pid: %d). x: %d\n", rc, getpid(), x);
		// fflush(f);
		fclose(f);
	}

	return 0;
}
