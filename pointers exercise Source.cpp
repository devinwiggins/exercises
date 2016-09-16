#include <iostream>
using namespace std;
	      // #1-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+|
//(1) p3 = &d
// cout << *p3 will print out to be S
// p3 = p1
//(2) cout << *p3; will print out to be S
//(3)cout << p3; will print out to be T
// *p1 = *p2
//(4) cout *p1; will print out to be 9772
//(5) cout << p1 will print out to be S
	     // #2 -+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+|
//int *p; //declaring pointer variable p
//int i; // declaring variable i
//int k; // declaring variable k
//
//i = 42; // assigns variable i to the number 42
// k = i;  /*assigns vatiable k to the variable i 
//which makes the variable k also 42 */
//p = &i 
/* assigns pointer variable p to the address of i
// which is assigned to the number 42*/
	     // #3-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+|
// D. *p = 75 will change the value of i to 75
		 // #4-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+|
/* the data type of the pointer must be the exact
same as the variable its pointing to */
		// #5-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+|
//int main()
//{
//	char blocks[3] = { 'A', 'B','C' };
//	char *ptr = &blocks[0];
//	char temp;
//
//	temp = blocks[0]; // temp is A
//	temp = *(blocks + 2); // temp is c
//	temp = *(ptr + 1);	// resets temp back to A then increments the space by 1. temp is B
//	temp = *ptr;		//resets temp back to A. temp is a.
//
//	ptr = blocks + 1; // ptr is 4435
//	temp = *ptr;   // temp is B. because the address was incremented
//	temp = *(ptr + 1); // temp is C.
//
//	ptr = blocks; // ptr would be the address of the blocks variable
//	temp = *++ptr; // basically increments the variable backwards. temp is B.
//	temp = ++*ptr; // would increment the variable blocks. temp is C
//	temp = *ptr++; // increments blocks. temp is C
//	temp = *ptr; // temp is C
//
//}
		// #6-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-|
// void RevString(char* array) 