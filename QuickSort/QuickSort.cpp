// Mutlu Mete, Oct 15, 2016
// Quick Sort in Randomly genereated integer array


#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#define N  7

using namespace std;


void swap(int A[], int i, int min);
bool small(int a, int b);
void print(int A[]);
void fillRandom(int A[], int size);

void sort(int A[], int lo, int hi);
int partition(int A[], int lo, int hi);

int main(int argc, const char * argv[]) 
{
	int  A[N]={0};
	fillRandom(A,N);
	print(A);
	//Shuffle(A); shuffle  the array. commentted out for now	
    sort(A, 0, N-1);   
	print(A);
}

void sort(int A[], int lo, int hi)
   {
      if (hi <= lo) return;
      int j = partition(A, lo, hi);
      sort(A, lo, j-1);
      sort(A, j+1, hi);
      print(A);
  }

int partition(int A[], int lo, int hi)
{
   int i = lo, j = hi+1;
   while (true)
   {
      while (small(A[++i], A[lo]))  // find item on left to swap
         if (i == hi) break;

      while (small(A[lo], A[--j]))  // find item on right to swap
         if (j == lo) break;
     
      if (i >= j) break;	//check if pointers cross
      swap(A, i, j);
   }
   swap(A, lo, j);
   return j;			// return index of item now known to be in place
} 

void swap(int A[], int i, int min)
{
	int tmp= A[i];
	A[i]=A[min];
	A[min]=tmp;	
	print(A);
}

void fillRandom(int A[], int size)
{	
	//for (int i = 0; i < N; i++)
		A[0]= 8; 
		A[1]= 4; 
		A[2]= 3; 
		A[3]= 7; 
		A[4]= 5; 
		A[5]= 1; 
		A[6]= 6; 
		
		//[8, 4, 3, 7, 5, 1, 6];
}

void print(int A[])
{	
	for (int i = 0; i < N; i++)
		cout << A[i] << ", ";
	cout << endl;
}

bool small(int a, int b)
{
  if (a <= b) return true;
  return false;
}





