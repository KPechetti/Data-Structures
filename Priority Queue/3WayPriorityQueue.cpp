//	Kishore Kumar Pechetti
//	50226929
//  3 Way Priority Queue
//	

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iomanip>      // std::setw
// #define N  10


using namespace std;

class BinaryHeap
{
public:
    BinaryHeap(); 					// Construction
    bool less(int i, int j);
    void exch(int i, int j);
    void swim(int k);
    void sink(int k);
    bool isEmpty();
    int size();
    void insert(int v);
    int delMax();
    void ListArray();
	void printT(int x, int id);

private:
    int N = 0;
    int *pq;
    int capacity = 100;
    
};


// Initialize the class
BinaryHeap::BinaryHeap()
{
    
    pq = new int[capacity];
    cout << "A new priority queue with " <<  capacity << " capacity was created...!" << endl ;
}

void BinaryHeap::ListArray()
{
    for (int i=1; i <= N; i++) // Remember we have "size" items
    {
        cout << pq[i] << ", ";
    }
    cout<<endl;
}

void BinaryHeap::swim(int k)
{
    while (k > 1 && less((k+1)/3, k))
    {
        exch((k+1)/3, k);
        k =(k+1)/3;
    }
}

bool BinaryHeap::isEmpty()
{  return N == 0;  }

int BinaryHeap::size()
{  return N;  }

 void BinaryHeap::insert(int v)
{
    pq[++N] = v;
    swim(N);
}

int BinaryHeap::delMax()
{
    int max = pq[1];
    exch(1, N--);
    pq[N+1] = NULL;
    sink(1);
    return max;
}

void BinaryHeap::sink(int k)
{
    while (3*k <= N)
    {
        int j = 3*k;
        if (j < N && less(j-1, j))
		{		
			j++;
			if (j < N && less(j-1, j))
			{			
				if (!less(k, j)) break;
		        exch(k, j);
		        k = j;
	    	}
	    	else
	    	{
			
		    	if (!less(k, j-1)) break;
			        exch(k, j-1);
			        k = j-1;
		    }
	    	
		 } 
		else
		{
			if (j < N && less(j-1, j+1))
			{			
				if (!less(k, j+1)) break;
		        exch(k, j+1);
		        k = j+1;
	    	}
	    	else
	    	{
	    		if (!less(k, j-1)) break;
		        exch(k, j-1);
		        k = j-1;
			}
	    	
		}
		
		
       
    }
}

bool BinaryHeap::less(int i, int j)
{
    if (pq[i] < pq[j])
        return true;
    return false;
}

void BinaryHeap::exch(int i, int j)
{
    int t = pq[i]; pq[i] = pq[j]; pq[j] = t;
}
//1-> 2, 3
//2-> 4, 5
//3-> 6, 7
void BinaryHeap::printT(int x, int id)
{
    if (x>N) 
	{
		cout<<endl;
		return;
	}

    printT(3*x+1,id+20);
    
    cout << setw(id) << ' ' << pq[x] <<' ';// <<endl;

    printT(3*x,id+20);
    
    printT(3*x-1,id+20);
    
}
// The program lunches here
int main( )
{
    BinaryHeap BH;
	for (int i=0; i < 20; i++)
		BH.insert( rand()%50 +1);
		
    BH.ListArray();       
    
	cout<< " -----------------------------------------------------------------------------------------------------------\n ";
	BH.printT(1,10);    
	
	for(int i =0; i<4;i++)
	BH.delMax();
	
	cout<< " -------------------------------------------------------------------------------------------------------------\n ";
	cout<<"After Deleting Max 4 elements: ";
	BH.ListArray(); 
	
	BH.printT(1,10);  
	
	
}
