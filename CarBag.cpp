// Kishore Kumar Pechetti
// CWID: 50226929
// Bag implementation using linked list, A dynamic data container
// CSCI 520s
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
	item(unsigned short a,unsigned short b,string c,string d,string e, item* t) { // constructor
		price =a; year =b; owner =c; Vin= d;carColor =e; next = t;
	}
};

typedef item* link;

// A class to represent Bag, which can hold and strings in an linked list
// The items (strings) are not sorted in the list.
class Bag
{
public:
    Bag();								// Construction
    link addCar();						// Adds a new item to bag
    unsigned short getNumberofCars();	// Gets the number of cars in the bag
    bool hadcar(string vin);			//Checks if the car is in the bag by using VIN number
    bool searchCarWithVIN(string VIN);	//Searches if the car is available in the bag
	void ListVINWithColor(string color); //Lists all the VIN numbers in the bag having the specified by color
	void ListVINwithOwner(string ownerName); //Lists all the VIN numbers in the bag having the specified by Owner
	void remove(string VIN);				//Removes a car fram the bag with the given VIN number
	void removelast();						//Removes the last car fram the bag
	void emptyBag();						//Removes all the cars fram the bag
    void ListAll();							// displays all items of the bag
    
        
private:  
	link first;						// A pointer to show the first node  
    link last;						// A pointer to show the last node
    unsigned short numberOfCars = 0;	// how many Cars Bag has
};

int Menu();
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

//Checks if the car is available in the bag
bool Bag::hadcar(string vin)
{
	item *it = first;
	while (it != NULL)
	{
		if (it->Vin == vin)return true;
		it = it->next;
	}
	return false;
}

//Adds new car with all the attributes auto generated
link Bag::addCar()
{
    unsigned short price;
	unsigned short year;
	string color;	
	string sVIN;
	string owner;    
	
	//Generate price,color,VIN,Year,OwnerName
	sVIN = generateVin(); //Generates VIN number and assign the value to the VIN variable
	
	while(hadcar(sVIN)) //Check if the generated VIN number is already exists
	{
		sVIN = generateVin(); //Assigns new VIN number if the VIN is already exists
	}
	
	price = rand()% 9998 + 1;  //Genearates random positive integer between 0 - 9999	
	
	year = rand()% (2017 - 1950) + 1950; //Generates random positive integer between 1950 - 2017
	color = getColor(); // Generates random color and assigns it to the color varaible
	owner = randowner(); // Generates random word and assigns it to the owner varaible
	
	//cout <<price <<", "<<year <<", "<<color <<", "<<owner <<", "<<sVIN <<endl;
    link AddItem = new item(price,year,owner,sVIN,color, NULL);//  dynamically create a new struct/item
    if ( AddItem == NULL) return NULL; 		// not enought memory
    if ( last == NULL ) first = AddItem;		// first item to be added
    else last->next = AddItem;					// add to the end of array
    last = AddItem;
	numberOfCars++;    
	return AddItem;	// added.
}

//Searches the car with provide VIN number
bool Bag::searchCarWithVIN(string VIN)
{
	link it = first;
	while (it != NULL)
	{
		if (it->Vin == VIN)
		{
			cout << endl;
			cout << "Vin :" << it->Vin<<endl;
			cout << "Owner :" << it->owner << endl;
			cout << "Price :" << it->price << endl;
			cout << "Year :" << it->year << endl;
			cout << "Color :" << it->carColor << endl;
			return true;
		}
		it = it->next;
	}
	cout << "There is no car with Vin: " << VIN << endl;
	return false;
}

//Lists all the VINs of cars with provided color
void Bag::ListVINWithColor(string color)
{
	link it = first;
	int count  =0;
	cout << "Vin numbers of the cars having " <<color <<" color:" <<endl;
	while (it != NULL)
	{
		if (it->carColor == color)
		{				
			cout << it->Vin<<endl;
			count++;
		}		
		it = it->next;
	}
	if(count == 0)
		cout << "There is no car with Color: " << color << endl;
}

//Lists all the VINs of cars with provided Owner Name
void Bag::ListVINwithOwner(string ownerName)
{
	link it = first;
	int count  =0;
	cout << "Vin numbers of the cars with Owner Name: " <<ownerName  <<endl;
	while (it != NULL)
	{
		if (it->owner == ownerName)
		{				
			cout << it->Vin<<endl;
			count++;
		}		
		it = it->next;
	}
	if(count == 0)
		cout << "There is no car with Owner Name: " <<ownerName << endl;
}

//Removes a car from the bag with provided VIN number
void Bag::remove(string VIN)
{
	if(first == NULL)
	{
		cout << "The bag is empty";
		return;
	}
		item *it = NULL, *tbd = NULL;
	if (first->Vin == VIN)
	{

		tbd = first;
		first = tbd->next;
		cout << endl << "removed : " << tbd->Vin<<" from the bag" << endl;
		numberOfCars--;
		delete tbd;
		return;
	}
	it = first;
	tbd = first->next;

	while (tbd != NULL)
	{
		if (tbd->Vin == VIN)
		{
			it->next = tbd->next;
			if (tbd == last)
			{
				last = it;
			}
			cout << endl << "removed : " << tbd->Vin<<" from the bag" << endl;
			delete tbd;
			numberOfCars--;
			break;
		}
		it = tbd;
		tbd = tbd->next;
	}
	
}

//Removes last car in the bag
void Bag::removelast()
{
	
	if (first == NULL)
	{
		cout << "The bag is empty" << endl;
		return;
	}
		

	if (first->next == NULL)
	{
		cout << "removed : " << first->Vin << endl;
		delete first;
		numberOfCars=0;
		first = NULL;
		last = NULL;
		return;
	}

	item *currNode = first;
	while (currNode->next->next != NULL)
	{
		currNode = currNode->next;
	}
	cout << "removed : " << currNode->next->Vin << endl;
	numberOfCars--;
	delete currNode->next;
	currNode->next = NULL;
}
void Bag::emptyBag()
{
link Del = first;

	while (Del != NULL) {
		
		first = first->next;
		delete Del;		
		Del = first;
	}
	
	last = first = NULL;
	numberOfCars = 0;
	cout << "removed all the cars from bag" << endl;
}

int main()
{	
	Bag carBag;
	
	for(int i =0; i <1000; i++) //Adds 1000 cars in the bag
	 carBag.addCar();
	 	
	carBag.ListAll(); //Lists all the cars in the bag with all details
	cout<<endl;
	
	cout << "A bag with 1000 cars is created" <<endl ;	
	cout<<endl;
	
	int option = Menu();	
	
	while(option != 9)
	{			
		if (option == 1)
		{		
			link newcar;	
			newcar	= carBag.addCar();
			cout << "A car is added in the bag" <<endl;
			carBag.searchCarWithVIN(newcar->Vin);
		}
		else if (option == 2)
		{			
				string st;
				cout << "enter the vin number to search" << endl;
				cout << "Vin :";
				cin >> st;
				carBag.searchCarWithVIN(st);						
		}
		else if (option == 3)
		{			
				string st;
				cout << "enter the color to get all the car VINs" << endl;
				cout << "Color :";
				cin >> st;
				carBag.ListVINWithColor(st);
		}
		else if (option == 4)
		{		
				string st;
				cout << "enter the owner name to get all the car VINs" << endl;
				cout << "Owner Name :";
				cin >> st;
				carBag.ListVINwithOwner(st);
		}
		
		else if (option == 5)
		{			
				string	vin;
				string st;
				cout << "enter the vin number to remove" << endl;
				cout << "Vin :";
				cin >> st;
				
				cout << endl;
				carBag.remove(st);
		}
		else if (option == 6)
		{			
				carBag.removelast();
		}
		else if (option == 7)
		{			
				carBag.emptyBag();
		}
		else if (option == 8)
		{			
				cout <<"Number of cars in the bag : " <<carBag.getNumberofCars() << endl;
		}		
		else
		{
			cout<< "Please enter the valid option!!";	
		}
		option = Menu();
	}
}

int Menu()
{
	int option;
	cout << endl;
	cout<<"------------------------------------------\n";	
	cout << "1) Add a new car" << endl;
	cout << "2) search a car" << endl;
	cout << "3) List of car VINs specified by a color" << endl;
	cout << "4) List of car VINs specified by owner name" << endl;
	cout << "5) remove a car" << endl;
	cout << "6) remove the last car" << endl;
	cout << "7) remove all cars from the bag" << endl;
	cout << "8) get the number of cars added" << endl;	
	cout << "9) exit" << endl;
	cout<<"-------------------------------------------\n"<<endl;
	cout << "Please select an option from above: " << endl;
	
	cin >> option;
	return option;
}

//Generates rondom VIN number with 5 characters
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
	
	 cout<< "Price: Year: Owner: color: Vin:" <<endl;
	while(it != NULL)
	{
		cout << it -> price<< ", " <<it -> year <<", " <<it -> owner <<", " <<it -> carColor <<", " <<it -> Vin;
		cout<<endl;
		it = it -> next;
	}		
	
}

//Generates random word with 4 characters
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

//Gets random color and returns a color
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

