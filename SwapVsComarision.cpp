//Kishore Kumar Pechetti
//50226929
//Number of Swaps and Comparisions required to Selection Sort and Insertion Sort for 8K and 16K

#include <stdio.h>
#include <iostream>
using namespace std;
const int N = 8000;
int swaps =0;
int comp =0;
int A8K [N];
int A16K [N*2];

void randNums(int num, int arr[]); //Generates Random Numbers and fills the array with items
void selectionSort(int arr[], int N); 
void swap(int A[], int i, int min);
bool small(int a, int b);
void insertionSort(int arr[], int N);

void randNums(int num, int arr[])
{
	for(int i =0; i <num; i++)
	{
		arr[i] =  rand() %249 -124; 
	}
}


//Selection sort
void selectionSort(int arr[], int N)
{
	for (int i = 0; i < N; i++)
	{ 
	   int min = i; 
	   for (int j = i+1; j < N; j++)
	    {
	         if ( small(arr[j], arr[min]) == true) min = j; // compare
	    }
	   swap(arr, i, min); // swap
	}	
}

bool small(int a, int b)
{
	comp++;
  if (a < b) return true;
  return false;
}

void swap(int A[], int i, int min)
{
	swaps++;
	int tmp= A[i];
	A[i]=A[min];
	A[min]=tmp;
}



// Insertion sort
void insertionSort(int arr[], int N)
{
	for (int i = 0; i < N; i++)
	{
	    for (int j = i; j > 0; j--)
	        if ( small(arr[j], arr[j-1]) == true) // compare
	            swap(arr, j, j-1); // swap
	        else break;
	}
}
int main()
{
	//Selectiion Sort
	randNums(N,A8K);  //Filling array with random values
	randNums(N*2,A16K);	//Filling array with random values
	selectionSort(A8K,N); //Selection sort for 8K items
	selectionSort(A16K,N*2); //Selection sort for 16K items
	
	cout<<"Selection Sort: "<<endl;
	cout<<"Number of Swaps: " <<swaps<<endl;
	cout<< "Number of Comparisions: "<<comp<<endl;
	cout<<"--------------------"<<endl;
	
	
	swaps = comp = 0; //Making counts to zero
	//Insertion Sort
	randNums(N,A8K); //Filling array with random values
	randNums(N*2,A16K); //Filling array with random values
	insertionSort(A8K,N); //Insertion sort for 8K items
	insertionSort(A16K,N*2); //Insertion sort for 16K items
	
	cout<<"Insertion Sort: "<<endl;
	cout<<"Number of Swaps: " <<swaps<<endl;
	cout<< "Number of Comparisions: "<<comp<<endl;
	
	
 } 
