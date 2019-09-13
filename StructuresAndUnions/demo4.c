#include <stdio.h>
#include <string.h>

struct course {
	int id;
	char title[40];
	float hours;
};

int main() {
	struct course cs1 = {341279,
"intro to C++", 12.5};
	struct course cs2;

	/*initialize cs2*/
	cs2.id = 341281;
	strcpy(cs2.title, "Advanced C++");// String assignment requires strcpy() from the string.h library.
	cs2.hours = 14.25;

	/*display course info*/
	printf("%d\t%s\t%4.2f\n", cs1.id, cs1.title, cs1.hours);// Also note the format specifiers %4.2f include width and precision options.
	printf("%d\t%s\t%4.2f\n", cs2.id, cs2.title, cs2.hours);

	return 0;
}
