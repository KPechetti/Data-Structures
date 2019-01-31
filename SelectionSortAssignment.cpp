// Kishore Kumar Pechetti
// CWID: 50226929
// Selection Sort of Incvoices
// CSCI 520
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
#define size 20


struct invoice 
{
	unsigned int custNo;
	unsigned short amount;
	string owner;
};

void swap(invoice A[], int i, int min);
bool smallCust(invoice A[],int a, int b);
bool smallAmount(invoice A[],int a, int b);
bool smallOwner(invoice A[],int a, int b);
void swap(invoice A[], int i, int min);
//Generates random word with 3 characters
string randowner()
{
	string s = "abc";
	s[0]= rand() % 26 + 65;
	s[1]= rand() % 26 + 65;
	s[2]= rand() % 26 + 65;
	return s;
	cout<< s <<endl;
}

int Menu()
{
	int option;
	cout << endl;
	cout<<"------------------------------------------\n";	
	cout << "1) Sort invoices over custNo" << endl;
	cout << "2) Sort invoices over amount" << endl;
	cout << "3) Sort invoices over owner" << endl;
	cout << "4) exit" << endl;
	cout<<"-------------------------------------------\n"<<endl;
	cout << "Please select an option from above: " << endl;
	
	cin >> option;
	return option;
}
void selectionSortInteger(invoice *A, string iSortItem){


	// Selection sort	
	for (int i = 0; i < size; i++)
	{ 								// Swap a[i] with smallest entry in a[i+1...N).
		int min = i; 				// index of minimal entr.		
		
		if(iSortItem == "Customer Number")
		{
			for (int j = i+1; j < size; j++)
			{			
				if ( smallCust(A,j, min) == true) min = j;			
					
			}
		}
		else if(iSortItem == "Amount")
		{
			for (int j = i+1; j < size; j++)
			{			
				if ( smallAmount(A,j,min) == true) min = j;			
					
			}
		}
		else
		{
			for (int j = i+1; j < size; j++)
			{			
				if ( smallOwner(A,j,min) == true) min = j;	
					
			}
		}
		
		swap(A, i, min);
	}

}

void swap(invoice A[], int i, int min)
{
	//Customer Number
    int tmp= A[i].custNo;
    A[i].custNo=A[min].custNo;
    A[min].custNo=tmp;
    
    //Amount
    tmp= A[i].amount;
    A[i].amount=A[min].amount;
    A[min].amount=tmp;
    
    //Owner
    string own = A[i].owner;
    A[i].owner=A[min].owner;
    A[min].owner=own;
}

bool smallCust(invoice A[], int a, int b)
{
    if (A[a].custNo < A[b].custNo) return true;
    return false;

}
bool smallAmount(invoice A[], int a, int b)
{
    if (A[a].amount < A[b].amount) return true;
    return false;

}
bool smallOwner(invoice A[], int a, int b)
{
    if (A[a].owner < A[b].owner) return true;
    return false;

}

void print(invoice A[])
{	
	for (int i = 0; i < size; i++)
	{
		cout << "  "<< A[i].custNo << "        " << A[i].amount << "        " << A[i].owner;
	    cout << endl;
    }
}


int main()
{
	invoice inv [size];
	
	for(int i =0 ; i< size; i++)
	{
		inv[i].custNo = 1000 + rand() % 5000;		
		inv[i].amount = 1 + rand() % 1000;		
		inv[i].owner = randowner();		
		cout << inv[i].custNo << " ," <<inv[i].amount << " ," <<inv[i].owner <<endl;
	}
	
	int option = Menu();
	
	while(option != 4)
	{			
		if (option == 1)
		{		
			selectionSortInteger(inv, "Customer Number");
		}
		else if (option == 2)
		{			
			selectionSortInteger(inv, "Amount");			
		}
		else if (option == 3)
		{			
			selectionSortInteger(inv, "Owner");			
		}
		else
		{
			cout<< "Please enter the valid option!!";	
		}
			print(inv);
			option = Menu();
	}	
	
}
