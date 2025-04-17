#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <assert.h>

double get_time() {
    struct timeval t;
    int rc = gettimeofday(&t, NULL);
    assert(rc == 0);
    return (double) t.tv_sec + (double) t.tv_usec/1e6;
}

void spin(int howlong) {
    double t = get_time();
    while ((get_time() - t) < (double) howlong);
}

int main(int argc, char **argv)
{
    printf("PID: %d", (int) getpid());
    int size = atoi(argv[1]);
    int mb = 1 << 20; 
    int arr_size = mb * size;
    unsigned char* arr = (unsigned char*) malloc(arr_size);
    printf("Starting address of arr: %p\n", (void*)arr);
    printf("Running with %d bytes\n", arr_size);

    int cur;
    while (1)
        for (cur = 0; cur < arr_size; cur++)
	{
	    if (cur == arr_size) {
		spin(5);
	    }
            arr[cur] += 1;
	}

    return 0;
}
