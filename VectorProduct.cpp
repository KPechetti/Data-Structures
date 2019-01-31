//Name: Kishore Kumar Pechetti
//CWID: 50226929
//  Sparse VectorProduct


#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <stdlib.h>
//#include <unistd.h> // From http://cs.dvc.edu/HowTo_CSleep.html

using namespace std;

// A struct to keep items
struct item
{
    unsigned int index;
    int data;
    item *next;
	item(unsigned int x, int d, item* t) { // constructor
		index = x;
		data = d;
		next = t;
	}
};

typedef item* link;

// Maintains index, data association for the vector. Indexes are kept ordered.
class Vector
{
public:
    Vector();                                   // Construction
    bool add(unsigned int index, int data);		// Adds a new item to vector
    void ListAll();                             // List all items of vector, starting with the first ITEM
	unsigned short getSize();					// returns the size of the vector	
	Vector operator * (Vector&);				//Multiplies two vectors
	link  getFirst(); 							// returns the pointer, "first"
	void ListNonZero();   						// prints non-zero indexes with data
	Vector sum(Vector &);
	
private:
    link first;									// A pointer to show the first node
    link last;                     				// A pointer to show the last node
    unsigned short size;						// how many items vector has    
   
};

// Initialize the class
Vector::Vector()
{
    first = last = NULL;
    size = 0 ;
}
unsigned short Vector::getSize()
{
	return size;
}


link  Vector::getFirst()
{
	return first;
}


void Vector::ListAll()                             // List all items of vector, starting with the first ITEM
{
    link it = first;

    while (it != NULL ) {
        cout  <<  it->index << ":" <<  it->data << " ";
        it = it ->next;
    }
    cout << endl;
}

void Vector::ListNonZero()                             // List all items of vector, starting with the first ITEM
{
    link it = first;

    while (it != NULL ) {
    	if(it->data != 0)
        	cout  <<  it->index << ":" <<  it->data << " ";
        it = it ->next;
    }
    cout << endl;
}

Vector Vector::operator * (Vector &param) {   // C = A * B; https://en.wikibooks.org/wiki/C%2B%2B_Programming/Operators/Operator_Overloading
  Vector mulVector;
  if (size != param.size) cout << " Something is wrong ..." << endl;
  cout << " Same size vectors found, multiplying vectors items now..." << endl;
  link itA = first;
  link itB = param.getFirst();

	while (itA != NULL && itB != NULL )
	  {
		  if (itA->index < itB->index)
		  {
			  itA = itA->next;
		  }
		  else if (itA->index > itB->index)
			  {
					itB= itB->next;
		      }
		  else
		  {		
			  if(itB->data * itA->data != 0)  
			  {
			  	mulVector.add(itA->index, itB->data * itA->data );			  	
			  }
			else
			  mulVector.add(itA->index, 0 );
			
			  itA = itA->next;
			  itB= itB->next;
		  }
	  }
  return mulVector;
}

bool Vector::add(unsigned int index, int data)		// Adds a new item to Vector, to the end
{
    link Ptr = new item (index, data, NULL);			//  dynamically create a new struct/item
    if (Ptr == NULL) return false;  // not enought memory

    //compSize++;  // non-zero items
	//size=index+1;	// last index
	size++;

    if (last == NULL) 					// first item to be added
    {
        first = last = Ptr;
    }
    else
    {
        last->next = Ptr;
        last = Ptr;
    }
    return true;	// added.
}

int main(int argc, const char * argv[])
{
    Vector A, B, MulVector;
    int locA = 0, locB = 0 ;
    int data = 0, count=0, it=0;
    
    for (int i=0; i< 10; i++) // adding 4 non zero and 6 zero value items in vector A in random locations.
        {
        	count=rand()%10;
        	
        	if(count<6 && it<4)
        	{
            locA = locA + rand() % 3 + 1;
            data = rand() % 50 + 30;
            A.add(locA, data);
            it++;
        	}
        	else
        	{
            locA = locA + rand() % 3 + 1;
            A.add(locA, 0);
        	}
        	
		}
			it=0;
		for (int i=0; i< 10; i++) // adding 7 non zero and 3 zero value items in vector B in random locations.
		{
			count=rand()%10;
			if(count<7 && it<7)
        	{
			locB = locB + rand() % 3 + 1;
            data = rand() % 50 + 30;
            B.add(locB, data);
            it++;
        }
        else
        	{
			locB = locB + rand() % 3 + 1;
            B.add(locB, 0);
        }
    }

    A.ListAll(); //cout << A.getSize() << " items found..." << endl;
	B.ListAll(); //cout << B.getSize() << " items found..." << endl;
	MulVector = A * B; //Multiplying Vector A and Vector B and storing it in MulVector
	cout<<endl;
	cout << MulVector.getSize() << " items found..."<<endl ; MulVector.ListAll(); cout<< endl;
	cout << "Non Zero Items are: " << endl;
	MulVector.ListNonZero();
}


// Practice Work: Define "*" operator to multiple two vectors.






