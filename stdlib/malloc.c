#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,n;
	char * buffer;

	printf("Length: ");
	scanf("%d", &i);

	buffer = (char*) malloc(i+1);
	if (buffer==NULL) exit(1);

	for (n=0; n < i; n++)
		buffer[n]=rand() % 26 + 'a';
	buffer[i]='\0';

	printf("%s\n", buffer);
	free(buffer);

	return 0;
}
