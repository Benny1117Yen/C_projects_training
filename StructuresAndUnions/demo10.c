/*
A union allows to store different data types in the same memory location.
It is like a structure because it has members. However, a union variable
uses the same memory location for all its member's and only one member at a time can occupy the memory location.
*/

//Union members can be of any data type, including basic types, strings, arrays, pointers, and structures.
union val {
	int int_num;
	float fl_num;
	char str[20];
};
//After declaring a union, you can declare union variables. You can even
//assign one union to another of the same type
union val u1;
union val u2;
u2 = u1;
/*
Unions are used for memory management. The largest member data type is used to share and then all
members use this one location. This process also helps limit memory fragmemtation. Memory management is
discussed in a later lesson.
*/
