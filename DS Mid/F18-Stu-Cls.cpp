#include <iostream>
#include <cstdlib>

using namespace std;

struct cls
{
	string name;
	string inst;
};
struct stu
{
	char name;
	int cwid;
	cls *c1; cls *c2;cls *c3;
	// cls *c[3]
};

stu Dept[5];
cls Sch[5];

int main()
{
	for (int i=0; i<5; i++)
	{
		Dept[i].name = char(( rand() % 25 ) + 65);
	    Dept[i].cwid = 5001+i;
		Dept[i].c1 = Dept[i].c2= Dept[i].c3 = NULL;
	}
	
	for (int i=0; i<5; i++)
	{
		cout << Dept[i].name << ", " << Dept[i].cwid << ", " << Dept[i].c1 << endl;
	}
	
	Sch[0].name="CSCI515"; Sch[0].inst = "Dr.Amy";
	Sch[1].name="CSCI525"; Sch[1].inst = "Dr.Karen";
	Sch[2].name="CSCI535"; Sch[2].inst = "Dr.Yen";
	Sch[3].name="CSCI545"; Sch[3].inst = "Dr.John";
	Sch[4].name="CSCI555"; Sch[4].inst = "Dr.Tom";
	
	Dept[0].c1 = &Sch[1];  Dept[0].c2 = &Sch[3]; Dept[0].c3 = &Sch[4];
	Dept[3].c1 = Dept[0].c1;
	
	cout << Dept[0].name << " has these instructors:" ;
	cout << Dept[0].c1->inst << ", " << Dept[0].c2->inst << ", " << Dept[0].c3->inst ;
	
	cout << endl;
	
	cout << Dept[3].name << " has this instructor:" ;
	cout << Dept[3].c1->inst ;
	
}
