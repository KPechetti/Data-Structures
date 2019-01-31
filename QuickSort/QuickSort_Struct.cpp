// Kishore Kumar Pechetti
// Quick Sort in Randomly genereated integer Structure array

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#define N  50

using namespace std;

struct point { 
double x; 
double y; 
};

void swap(point A[], int i, int min);
bool small(double a, double b);
void print(point A[]);
void fillRandom(point A[], int size);
void sort(point A[], int lo, int hi);
int partition(point A[], int lo, int hi);

int main(int argc, const char * argv[]) 
{
	point  *SArr = new point[50];
	fillRandom(SArr,N);
	cout<< "Point Struct Array Before Quick Sort:"<<endl;
	print(SArr);		
    sort(SArr, 0, N-1);  
	cout<<endl << "Point Struct Array After Quick Sort:" <<endl;
	print(SArr);
}

void sort(point A[], int lo, int hi)
{
      if (hi <= lo) return;
      int j = partition(A, lo, hi);
      sort(A, lo, j-1);
      sort(A, j+1, hi);
}

int partition(point A[], int lo, int hi)
{
   int i = lo, j = hi+1;
   while (true)
   {
   	 i++;
      while (small(A[i].x, A[lo].x))  // find item on left to swap
      {
      	if(A[i].x == A[lo].x && !small(A[i].y, A[lo].y) ) break;
      	if (i == hi) break;
      	i++;
	  }
	  
	  while (small(A[lo].x, A[--j].x))  // find item on right to swap
      {
      	if(A[j].x == A[lo].x && small(A[j].y, A[lo].y)) break;
      	if (j == lo) break;
	  }        
     
      if (i >= j) break;	//check if pointers cross
      swap(A, i, j);
   }
   swap(A, lo, j);
   return j;			// return index of item now known to be in place
} 

bool small(double a, double b)
{
  if (a <= b) return true;
  return false;
}

void swap(point A[], int i, int min)
{	
	double tmpx= A[i].x;
	double tmpy = A[i].y;
	
	A[i].x = A[min].x;
	A[i].y = A[min].y;
	
	A[min].x = tmpx;
	A[min].y = tmpy;
	
}

void fillRandom(point A[], int size)
{	
	for (int i = 0; i < N; i++)
	{
		A[i].x= 30 * ( (double)rand() / (double)RAND_MAX );
		A[i].y= 20 * ( (double)rand() / (double)RAND_MAX );
	}
		 
}

void print(point A[])
{	
	for (int i = 0; i < N; i++)
		cout <<"["<< A[i].x << ", "<<A[i].y <<"] ";
	cout << endl;
}


