struct student {
	int age;
	int grade;
	char name[40];
};

/* declare two variables */
struct student s1;
s1 = (struct student) {19, 9, "John"};// Initialize a structure using curly braces after declaration.
struct student s2 = {.grade = 9, .age = 19, .name = "John"};// .grade refers to the grade member of the structure. So do .age and .name.

