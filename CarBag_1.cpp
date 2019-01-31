// Kishore Kumar Pechetti
// Bag implementation using linked list, A dynamic data container
// CSCI 520


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

// A struct to keep items
struct item
{
	unsigned short price;
	unsigned short year;
	string owner;
	string Vin;
	string carColor;
	item *next;
	item(unsigned short price,unsigned short year,string owner,string Vin,string carColor, item* t) { // constructor
		price =price; year =year; owner =owner; Vin= Vin;carColor =carColor; next = t;
	}

};

typedef item* link;

// A class to represent Bag, which can hold and strings in an linked list
// The items (strings) are not sorted in the list.
class Bag
{
public:
    Bag();							// Construction
    bool add ();			// Adds a new item to bag
    unsigned short getNumberofCars();
    void ListAll();				// displays all items of the bag
        
private:
    link first;						// A pointer to show the first node
    link last;						// A pointer to show the last node
    unsigned short numberOfCars;	// how many Cars Bag has
};

string generateVin();
string randowner();
string getColor();

Bag::Bag() // Initialize an instance of the class
{    
    first = last = NULL; // At the beginning both, first and last are null    
}

// How many items the Bag has
unsigned short Bag::getNumberofCars()
{
    return numberOfCars;
}



bool Bag::add()
{
    unsigned short price;
	unsigned short year;
	string color;	
	string sVIN;
	string owner;

if(first == NULL)
{
    for(int i =0 ; i < 1000; i++)
    {
	//Generate price,color,VIN,Year,OwnerName
	price =  rand()%9999;
	
	year = rand()% (2017 - 1950) + 1950; 
	color = getColor();
	owner = randowner();
	sVIN = generateVin();
	cout <<price <<", "<<year <<", "<<color <<", "<<owner <<", "<<sVIN <<endl;
    link AddItem = new item(price,year,owner,sVIN,color, NULL);//  dynamically create a new struct/item
    if ( AddItem == NULL) return false; 		// not enought memory
    if ( last == NULL ) first = AddItem;		// first item to be added
    else last->next = AddItem;					// add to the end of array
    last = AddItem;
	numberOfCars++;
    return true;	// added.
    }
}
else
{
    //Generate price,color,VIN,Year,OwnerName
	price = rand()% 9999 + 1;
	year = rand()% 2017 + 1950;
	color = getColor();
	owner = randowner();
	sVIN = generateVin();	
    link AddItem = new item(price,year,owner,sVIN,color, NULL);//  dynamically create a new struct/item
    if ( AddItem == NULL) return false; 		// not enought memory
    if ( last == NULL ) first = AddItem;		// first item to be added
    else last->next = AddItem;					// add to the end of array
    last = AddItem;
	numberOfCars++;
    return true;	// added.
}


}
int main()
{
	//BagDyn aBag;
	Bag A;
	A.add();
	A.ListAll();
	
}

string generateVin()
{
	string vin[5];
	string vin1;	
	vin[0] = rand() % 26 + 65;
	vin[1] = std::to_string(rand() % 10);
	vin[2] = rand() % 26 + 65;
	vin[3] = std::to_string(rand() % 10);
	vin[4] = std::to_string(rand() % 10);
	vin1 += vin[0] + vin[1]	+ vin[2] + vin[3] + vin[4];
	return vin1;
}
// displays all items of the bag
void Bag::ListAll()
{
	if (numberOfCars == 0) { cout << "Bag is empty" << endl; return; }
	link it = first;
	
	 cout<< "Price: Year: Owner: color: Vin:";

	for (int i = 0; i < numberOfCars; i++)    // i < size   or i <= (size-1)
	{
		cout << it -> price << ", " <<it -> year <<", " <<it -> owner <<", " <<it -> carColor <<", " <<it -> Vin <<endl;
		it = it -> next;
	}
	cout << endl;
}

string randowner()
{
	string s = "abcd";
	s[0]= rand() % 26 + 65;
	s[1]= rand() % 26 + 97;
	s[2]= rand() % 26 + 97;
	s[3]= rand() % 26 + 97;
	return s;
	cout<< s <<endl;
}


string getColor()
{
    enum  carColor {red, blue, white, black, gray, green, yellow };
	int r= rand()%7;
	if(r==red) return "red";                           // Checks value from enum and stores in string
	if(r==blue) return "blue";
	if(r==white) return "white";
	if(r==black) return "black";
	if(r==gray) return "gray";
	if(r==green) return "green";
	if(r==yellow) return "yellow";
    
}

