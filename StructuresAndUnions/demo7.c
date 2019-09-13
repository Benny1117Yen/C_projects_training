/*
Just like pointers to variables, pointers to structures can also be defined.

struct myStruct *struct_ptr;
defines a pointer to the myStruct structure.

struct_ptr = &struct_var;
stores the address of the structure variables struct_var in the pointer struct_ptr.

struct_ptr -> struct_mem;
accesses the value of the structure member struct_mem.
*/

#include <stdio.h>

struct student {
	char name[50];
	int number;
	int age;
};

//struct pointer as a function parameter
void showStudentData(struct
student *st) {
	printf("\nStudent:\n");
	//The -> operator allows to access members of the struct though the pointer.
	printf("Name: %s\n", st -> name);
	printf("Number: %d\n", st -> number);
	printf("Age: %d\n", st -> age);
	//(*st).age is the same as st -> age.
	//Also, when a typedef has been used to name the struct, then a pointer is declared using only the typedef name along with * and the pointer name.
}

struct student st1 = {"Krishna", 5, 21};
showStudentData(&st1);
