#include<stdio.h>

void hundred() {
	static int i=1;
	printf("%d\n", i++);
}

void twenty() {
	hundred(),hundred(),hundred(),hundred(),hundred();
}

void four() {
	twenty(),twenty(),twenty(),twenty(),twenty();
}

int main() {
	four(),four(),four(),four();
}
