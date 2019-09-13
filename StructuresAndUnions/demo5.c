/*
The typedef keyword creates a type definition that simplifies code and makes a program easier to read.
typedef is commonly used with structures because it eliminates the need to use the keyword struct when declaring variables.
*/
typedef struct {
	int id;
	char title[40];
	float hours;
}course;

course cs1;
course cs2;
