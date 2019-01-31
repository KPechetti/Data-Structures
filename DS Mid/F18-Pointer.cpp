#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	unsigned short N = 10;
	int *A= NULL;
	int *B= NULL;	
	A = new int[N];	
	
	
	for (int i=0; i<N; i++)
	{
		A[i]= i *5 + 4;
		cout << A[i] << ", " ;
	}
     cout << endl;
     
     B = &A[0]; // shallow copy     B = A;     
     int *C=B;
     int *G=A;
	for (int i=0; i<N; i++)
	{
		cout << B[i] << ", " ;
		cout << C[i] << ", " ;
		cout << G[i] << ", " ;
	}	
	
	
}
