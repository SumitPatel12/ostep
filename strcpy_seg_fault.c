#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char *src = "something";
	// Uncomment the below one for seg or bus fault.
	// char *dest; // Yeah no allocation.
	// You need the +1 for the null terminator.
	char *dest = (char *) malloc(strlen(src) + 1);
	// Yup, segfault for the win.
	// Or bus error
	strcpy(dest, src); 
	return 0;
}
