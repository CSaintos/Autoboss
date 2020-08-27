// Lab 2 Project.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

using namespace std;

// assignment 1. Add function declaration
void Funk(int);
int roundToNearest(double);

int main()
{
    // call Funck #49
	Funk(49);
	cout << roundToNearest(6.15) << endl;
	cout << roundToNearest(6.78) << endl;
}

void Funk(int f) {
	f = f * 2;
}

// assignment 2
int roundToNearest(double num) {
	return (num + 0.5);
}

/*
	assignment 3
		a. Compiler loos for the file iostream within the C++ system library located somewhere in Microsoft Visual Studio C++
		b. C:\AdaProjects\Question6
		c. doors.h is not local to main.cpp, in other words, its not in C:\AdaProjects\Question3
		d. Don't reference. Copy.
*/

/*
	assignment 4
		first thing in the stack is last to be removed.
		last thing in the stack is first to be removed.
		Stack:
		x added: line 10. removed: line 13
		x added: line 1. removed: line 7
		a added: line 2. removed: line 7
		b added: line 4. removed: line 6
		y added: line 12. removed: line 13
*/

/*
	assignment 5
		0x00 [9]    : int a = 9;
		0x04 [9]    : int b = a;
		0x0C [0x00] : int *c = &a;
		0x14 [0x00] : int *d = c;
		0x18 [9]    : int e = *c;

		int numOfIntInstances = 3;
*/



//Did my changes work










// Extra stuff:

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
