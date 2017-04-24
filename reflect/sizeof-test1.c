/**
 * See comment in hc-table.c
 */

#include <stdio.h>

const struct {
	int id;
	char* name;
	char* role;
	int age;
} people[] = {
	{3, "Jake Smith", "Tester", 27},
	{5, "Michael Brown", "Designer", 34},
	{2, "Zack Bernhardt", "Manager", 36}
};

int main() {
	printf("sizeof(people): %d\n", sizeof(people));
	printf("sizeof(people[0]): %d\n", sizeof(people[0]));
	printf("sizeof(people) / sizeof(people[0]): %d\n", sizeof(people) / sizeof(people[0]));

	return 0;
}
