// Kishore Kumar Pechetti
// Bag implementation using linked list, A dynamic data container
// CSCI 520

#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>

using namespace std;

struct item
{
  string data; 
  item *next;

  item(string x, item* t) { 

    data = x; next = t;

  } 
};

typedef item* link;

class Bag
{
public:
    Bag();							// Construction
    bool add (string str);			// Adds a new item to bag
    unsigned short getSize();		// How many items  the Bag has
    void ListBag();					// List all items of Bag.
private:
    link first;						// A pointer to show the first node    
    unsigned short size;			// how many items Bag has
};

Bag::Bag() // Initialize an instance of the class
{
    size = 0;
    first = NULL; // At the beginning both, first and last are null
    cout << "A new bag with  3000 was created...!" << endl ;
}

//Complete the following function to add an item to Linked Listed using only "first" pointer

bool Bag::add(string str)
{
	link front;
  link AddItem = new item(str,NULL);			//  dynamically create a new struct/item
    if ( AddItem == NULL) return false; 		// not enought memory
if(first == NULL)
{
	first = AddItem;
	size++;
	return true;
}
else
{
		front = first;
	while (front->next != NULL)
	{
		front= front->next;
	}
	front ->next = AddItem;
	size++;
    return true;
}
}

void Bag::ListBag()	// List, print out, all items in the arrays, // make 5 coloumns
{
	cout << size << ": " ;
    link it = first;   // it means iterator, visit all items one by one.
	int i=0;  			// i is used to format the outpur
    while (it != NULL) {
        cout << it->data << "   ";
        it = it->next;
		if ( (i+1)%5 == 0) cout << endl;
		i++;
    }
	cout << endl;
}


int main(int argc, const char * argv[]) {
    Bag bigBag;
	string tempStr;
	char sel = ' ';
	while (sel != 'e')
	{
		cout << "(i)nsert, (e)xit:   ";
		cin >> sel;
		switch(sel)
		{
			case 'i':
					cout << "\nString to be inserted:";
					cin >> tempStr;
					bigBag.add (tempStr);
					bigBag.ListBag();
					break;
			
			default:
					break;
		}
	}
}



