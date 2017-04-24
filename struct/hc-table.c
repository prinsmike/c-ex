/**
 * Hard coded data table.
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

/**
 * Get the count of elements in the array.
 *
 * number of bytes in the array / number of bytes in one element = number of elements.
 */
const int people_length = sizeof(people) / sizeof(people[0]);

int main(int argc, char **argv) {
	int search_id = 5;
	int i;

	printf("Looking up person with ID = %d...", search_id);

	for (i = 0; i < people_length; i++) {
		if (people[i].id == search_id) {
			puts("found it!");
			printf("Name: %s\n", people[i].name);
			printf("Role: %s\n", people[i].role);
			printf("Age: %d\n", people[i].age);

			break;
		}
	}

	if (i == people_length) {
		puts("no such person.");
	}

	return 0;
}
