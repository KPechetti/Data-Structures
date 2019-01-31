#include <iostream>
#include <cstdlib>

using namespace std;

const int Cap = 10;
int S[Cap];
int count=0;

bool has(int f);
void add(unsigned int x);
void list();
bool del(int f); // successful deletion returns true, or else false

int main()
{  for (int i=0; i < 15 ; i++)
   add(rand() % 50);
   cout << "has bag 4:"<< has(4) << endl;
  list();	 del(5);   list();
}

bool del(int f)
{
   for (int i=0; i < count; i++)
   	if (S[i]==f)
   	{
	   S[i]=S[--count];
	   return true;
	}
	return false;
}

void list() //  prints all items of the bag
{
   for (int i=0; i < count; i++)
   cout << S[i] << ", " ;
   
   cout << endl;	
}

bool has(int f)
{
	for (int i=0; i < count; i++)
	if (S[i]==f) return true;
	return false;	
}
void add(unsigned int x)
{
	cout << x << " is being added to bag" << endl;
	if (has(x))
	{
		cout << " Duplicate entry is not allowed" << endl; return;
	}
	
	if (count < Cap ) S[count++]=x;
	else cout << "full";
    
}

