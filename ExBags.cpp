// Bag implementation using a dynamically allocated mem space (NOT LINKED LIST)
//Kishore Kumar Pechetti
// To Be completed in the class

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

class BagDyn
{
public:
	BagDyn(); 					// construction
	bool Add(int n); 			// Add, true if successfully added
	bool Remove(int n);			// Removes an item from the bag
	unsigned int getCapacity();	// return the capacity, the max number of items to be held
	unsigned int getSize();		// current number of items in the bag
	bool Search(int s);			// search for an item
	bool isEmtpy();				// Checks if the bag is empty
	void ListAll();				// displays all items of the bag
	int AveOfItems();			// displays the Average of items in the bag
	int MinOfItems();			// displays the Minimum of numbers in the bag
	int MaxOfItems();			// displays the Maximum of numbers in the bag
	BagDyn Union(BagDyn X);		// It returns union of two bags
	BagDyn Intersect(BagDyn X); // It returns intersection of two bags
	BagDyn Difference(BagDyn X); //It returns difference of two bags
	int* data;

private:	
	unsigned int size;
	unsigned int capacity;
	
};

BagDyn::BagDyn()	// construction
{
	data = NULL;
	capacity = 10;
	//cout << "Enter the capacity of the bag:" ;
	//cin >> capacity;
	size = 0;
    data = new int[capacity];    
    
	if (data == NULL)
	{
		cout << "An error occured, bag cannot be allocated" << endl;
	}
	else
	{
		//cout << data;
	//	cout << "A bag to keep " << capacity << " items is created and ready to use" << endl;
	}
}

// returns the capacity, the max number of items to be held
unsigned int BagDyn::getCapacity()
{
	return capacity;
}

// number of items in the bag
unsigned int BagDyn::getSize()
{
	return size;
}

// search for an item
bool BagDyn::Search(int s)
{
	for (int i = 0; i < size; i++)    // i < size   or i <= (size-1)
	{
		if (data[i] == s) return true;
	}

	return false;
}


// Adds an items, true if successfully added
bool BagDyn::Add(int n)
{
	//if (size == capacity) return false; // no more space, it is full

	for (int i = 0; i < size; i++)    // i < size   or i <= (size-1) // check or duplicate entry
	{
		if (data[i] == n) return false;
	}
	// data[size] = n; size++;
	data[size++] = n;
	return true;
}

// Checks if the bag is empty
bool BagDyn::isEmtpy()
{
	if (size == 0) return true;
	return false;
}



// displays all items of the bag
void BagDyn::ListAll()
{
	if (size == 0) { cout << "Bag is empty" << endl; return; }

	for (int i = 0; i < size; i++)    // i < size   or i <= (size-1)
	{
		cout << data[i] << ", ";
	}
	cout << endl;
}

// Removes an item from the bag
bool BagDyn::Remove(int n)
{
	if (isEmtpy() == true) return false;

	for (int i = 0; i < size; i++)    //  search for the item
	{
		if (data[i] == n)
		{
			data[i] = data[--size];
			return true;
		}
	}
	return false;
}


// Returns Average of numbers in the bag
int BagDyn::AveOfItems()
{	
	int iSum =0;
	for (int i = 0; i < size; i++)   
	{
		iSum += data[i];
	}
	return (iSum/size);
}


int BagDyn::MinOfItems()
{	

	int smallest = data[0] ;
	for (int i = 1; i < size; i++)    
	{
		if ( data[i] < smallest ) 
             smallest = data[i] ; 
		
	}
	return (smallest);
}



int BagDyn::MaxOfItems()
{	

	int largest = data[0] ;
	for (int i = 1; i < size; i++)    
	{
		if ( data[i] > largest ) 
             largest = data[i] ; 
		
	}
	return (largest);
}

// Returns Union of numbers in two bags
BagDyn BagDyn::Union(BagDyn X)
{	
    BagDyn C;
    //C.size = size + X.size;
	for(int i=0;i<size;i++)
	  {
	  	C.Add(data[i]);
	  }
    
    
  for(int i=0;i<X.size;i++)
  {
  	C.Add(X.data[i]);
  }

return C;	
}

// Returns Intersection of numbers in two bags
BagDyn BagDyn::Intersect(BagDyn X)
{	
    BagDyn D;    
		for(int i=0;i<size;i++)
	  {
	  	for(int j=0;j<size;j++)
  		{
  		if(data[i] == X.data[j]) D.Add(data[i]);
		  
		}  	
	  	
	  }
return D;	
}


// Returns Intersection of numbers in two bags
BagDyn BagDyn::Difference(BagDyn X)
{	
    BagDyn D;
 int count;
		for(int i=0;i<size;i++)
	  {
	  	count=0;
	  	for(int j=0;j<size;j++)
  		{
  		if(data[i] == X.data[j]) 
		  count=1;
		  
		}  	
	  	if(count==0)
		  D.Add(data[i]);
	  }
return D;	
}



// Demonstrate the usage of the bag
int main()
{
	//BagDyn aBag;
	BagDyn A;
	BagDyn B;
	BagDyn C;
		

	// inserting 10 integers in a bag.
	for(int i =0 ; i < 10; i++)
	{		
		A.Add(rand()% 50 + 1); 
		
	}
	
	// inserting 10 integers in a bag.	
	for(int i =0 ; i < 10; i++)
	{		
		B.Add(rand()% 50 + 1); 
		
	}
	
	cout << "Items in bag A is " <<endl;
	A.ListAll();
	
	cout << "Items in bag B is " <<endl;
	B.ListAll();
	
	
	C = A.Union(B); 
		
	cout << "Union of Bag A and Bag B is:  " <<endl;
	C.ListAll();
	
	for(int i =0 ; i < 10; i++)
	{		
		C.data[i]=0;
		
	}
	
	cout << "Intersection of Bag A and Bag B is:  " <<endl;
	C = A.Intersect(B); 
	
	C.ListAll();
	
	for(int i =0 ; i < 10; i++)
	{		
		C.data[i]=0;
		
	}
	
	cout << "Difference of Bag A and Bag B is:  " <<endl;
	C = A.Difference(B); 
	
	C.ListAll();
	
	
	system("pause");


}







