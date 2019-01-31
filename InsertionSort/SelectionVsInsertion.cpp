// Comparison of Selectioin and Insertion Sort in Randomly genereated integer in dynamicall crated arrays

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <ctime>



using namespace std;

void swap(int A[], int i, int min);
bool small(int a, int b);
void print(int A[]);
void fillRandom(int A[], int size);
void InsSort(int A[], int size);
void SelSort(int A[], int size);


int main(int argc, const char * argv[])
{
    int* A;
	int* B;
	int size = 1000;
	clock_t start, stop; 
	double totalTime;
	
	cout << "N" << "\t" << "IS" << "\t" << "SS" << endl;
		
	while (size <= 128000)
	{
		A = new int[size];
		B = new int[size];
		fillRandom(A,size); 
		for (int i =0; i <size; i++) B[i]= A[i]; // deep copy
		
		cout << size << "\t";
		// Insertion sort
		start = clock();		
		InsSort(A, size);		
		stop = clock();			
		totalTime = (stop - start) / (double)CLOCKS_PER_SEC;
		cout << totalTime << "\t" ;
		
		// Selection sort
		start = clock();
		SelSort(B, size);
		stop = clock();			
		totalTime = (stop - start) / (double)CLOCKS_PER_SEC;
		cout << totalTime << endl;		
		
		delete []A;
		delete []B;
		size = 2 * size ;
	}   
}


void SelSort(int A[], int size)
{
	// Selection sort
	for (int i = 0; i < size; i++)
	{ 								// Swap a[i] with smallest entry in a[i+1...N).
		int min = i; 				// index of minimal entr.
		for (int j = i+1; j < size; j++)
		{
			if ( small(A[j], A[min]) == true) min = j;
		}
		swap(A, i, min);
	}
	
}

void InsSort(int A[], int size)
{
	 // Insertion sort
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j > 0; j--)
            if ( small(A[j], A[j-1]) == true) // compare
                swap(A, j, j-1); // exchange or swap
            else break;
    }	
	
}

bool small(int a, int b)
{
    if (a < b) return true;
    return false;

}

void swap(int A[], int i, int min)
{
    int tmp= A[i];
    A[i]=A[min];
    A[min]=tmp;
}


void fillRandom(int A[], int size)
{
    for (int i = 0; i < size; i++)
        A[i]=rand() % 5000;
}

