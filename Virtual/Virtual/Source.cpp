#include <iostream>
using namespace std;

class Base
{
public:
	virtual void print()
	{
		cout << "I am Base" << endl;
	}
	virtual void printMe()
	{
		cout << "I am Base too" << endl;
	}

};

class Derive: public Base
{
public:
	void print()
	{
		cout << "I am Derive" << endl;
	}
};

int* GetVirtualTablePointer(Base* b)
{
	return *(int**)b;
}

int main()
{
	Base *b = new Base();

	cout << "********* Base *************" << endl;
    //get the virtual table pointer of Base object 
	int *vptr_b = GetVirtualTablePointer(b);

	((void(*)()) vptr_b[0])();// print 
	((void(*)()) vptr_b[1])();// printMe 


	cout << "********* Derive *************" << endl;
	b = new Derive();

	//get the virtual table pointer of Derive object 
	int *vptr_d = GetVirtualTablePointer(b);

	((void(*)()) vptr_d[0])();// print
	((void(*)()) vptr_d[1])();// printMe 

	return 1;
}