// Kishore Kumar Pechetti  - Sep 6, 2018
// CWID: 50226929
// Compiler: Visual Studio, DEV C++
// Assignment: Random number


/* This program generates N random numbers between Lower Bound and the Upper bound.
It takes 3 integer inputs from the user (Lower bound, Upper bound & Count)
Limt for the lower bound is -10000 and the limt for upper bound is 10000
It accepts only intergers for Lower bound, Upper bound & Count.
*/

#include<iostream>
#include <stdlib.h>
using namespace std;
int main() {
	
	int iLowerBound, iUpperBound, iCount, iResult;
	
	//Get Lower Bound number from the user
	cout << "Please enter the Lower Bound number: ";
	cin >> iLowerBound;

	//Lower Bound integer validation
LBCheck: if(cin.fail())
	{
		cout << "Please enter a valid number: ";
		cin.clear();
		cin.ignore(256,'\n');
		cin >> iLowerBound;
		goto LBCheck;
	}
	
	//Lower Bound Limit Validation
Label1:	if(iLowerBound < -10000)
		{
		cout << "Please enter the Lower Bound number above -10000: ";	
		cin >> iLowerBound;
		goto Label1;	
		}
	
	//Get Upper Bound number from the user
	cout << "Please enter the Upper Bound number: ";
	cin >> iUpperBound;
	
//	Upper Bound integer validation
UBCheck: if(cin.fail())
	{
		cout << "Please enter a valid number: ";
		cin.clear();
		cin.ignore(256,'\n');
		cin >> iUpperBound;
		goto UBCheck;
	}
	
	//Upper Bound Limit Validation
Label2:	if(iUpperBound > 10000 || iUpperBound < iLowerBound)
		{
		cout << "Please enter the Upper Bound number below 10000 and greater than Lower Bound: ";	
		cin >> iUpperBound;
		goto Label2;	
		}
	
	//Get Count from the user
	cout << "Please enter the Count: ";
	cin >> iCount;
	CountCheck: if(cin.fail())
	{
		cout << "Please enter a valid number: ";
		cin.clear();
		cin.ignore(256,'\n');
		cin >> iCount;
		goto CountCheck;
	}
	
	//Generating Random Numbers between the range
	cout << "Your Random Number(s) are:" <<"\n";
	for(int i =0; i < iCount; i++)
	{	
	//Generates Random number between Upper bound and lower bound (Excluding Upper bound and lower bound)
	iResult = rand() % (iUpperBound - iLowerBound-1) + iLowerBound+1;	
	cout << "Random Number "<<(i+1) <<": " <<iResult <<"\n";	
	}
	
	return 0;
}
