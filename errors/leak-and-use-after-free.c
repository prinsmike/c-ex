#include<stdio.h>
#include<stdlib.h>

int main() {
	int* p = (int*) malloc(sizeof(int));	// Allocate memory for p pointer.
	int* q = (int*) malloc(sizeof(int));	// Allocate memory for q pointer.

	*p = 10; // Set p value to 10.
	*q = 20; // Set q value to 20.

	p = q; // p now points to value of q. Memory p pointed to is now leaked.

	printf("%d %d", *p, *q);

	free(p);	// Free memory p points to.
	free(q);	// Use after free error. Memory was already freed on previous line.
}
