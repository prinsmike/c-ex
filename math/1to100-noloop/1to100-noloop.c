#include<stdio.h>

void one() {
	static int i=1;
	printf("%d\n", i++);
}

void five() {
	one(),one(),one(),one(),one();
}

void twentyfive() {
	five(),five(),five(),five(),five();
}

int main() {
	twentyfive(),twentyfive(),twentyfive(),twentyfive();
}
