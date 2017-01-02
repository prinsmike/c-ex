#include <stdio.h>
#include <stdlib.h>

int n = 0;

void foo() {
	void* x;

	printf("%d\n", ++n);

	if (n >= 100) {
		exit(0);

	}

	*((char**) (&x + 4)) -= 5;

}

int main() {
	foo();
	return 1;
}
