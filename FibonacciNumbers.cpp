//inserting first 30  Fibonacci numbers into dynamic array Fib and then poping them to print out first 30 numbers in descending order. 
//Kishore Kumar Pechetti
//50226929

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

int size=30; // size of the array
int ind = 3; // Index to push and pop the fibonacci numbers
int main()
{
	void push(int n, unsigned int * Fib); //push/Add values in the array
	unsigned int pop(unsigned int * Fib ); //pop/Remove values from an array 
	unsigned int *Fib = new unsigned int[size]; //Declaration of array
	Fib[0] = 0; Fib[1] = 1; Fib[2] = 1; //Inserting first 3 values of fibonacci numbers in the array
	
	int num = 0;
	for(int i = 3; i < size; i++) //Loop to generate and add fibonacci series in to an array
	{
		num = Fib[i-2] + Fib[i-1]; //Geneartion of fibonacci number
		push(num, Fib);	//Adding fibonacci series number to the array
	}
	size--; //
	
	cout << "Fibonacci Series of first 30 numbers in descending order :"<<endl;
	for(int i = size; i >=0; i--) // Loop to remove values from an array
	{
		cout << pop(Fib) <<","; // Removing values from an array
	}
	
	system("pause");
}

void push(int n, unsigned int * Fib)  //push/Add values in the array
{	
		Fib[ind++] = n; //Inserting value in the array
}
	

unsigned int pop(unsigned int * Fib )  //pop/Remove values from an array 
{	
	return Fib[size--];	
}
