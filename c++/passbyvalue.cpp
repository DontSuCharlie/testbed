#include <stdio.h>

// defining a class to see how classes get passed around
class MyClass
{
public:
	static int count;
	int id;
	MyClass()
	{
		this->id = count++;
	}
	void print()
	{
		printf("%d ", id);
	}
};

int MyClass::count = 0;

// checking pass by types for builtin types
void changeBuiltInTypes(int a, int& b, const int& c, int* d)
{
	a++; // changes to a doesn't stay, because we got a copy of it (pass by value)
	b++; // changes to b stays, because we passed a reference (pass by reference)
	// ++c; // you can't change c because it's a const
	*d = *d + 1; // changes to d stay, but you have to do it the pointer way (pass by pointer)
}

void changeUserDefinedTypes(MyClass a, MyClass& b, const MyClass& c, MyClass* d)
{
	a.id = 10;
	b.id = 11;
	// c.id = 12;
	d->id = 13;
}


int main(void)
{
	// first round
	int a, b, c, d;
	printf("%d %d %d %d\n", a, b, c, d);
	changeBuiltInTypes(a, b, c, &d);
	printf("%d %d %d %d\n", a, b, c, d);

	//secound round
	MyClass xa, xb, xc;
	MyClass* xd = new MyClass();
	xa.print();
	xb.print();
	xc.print();
	xd->print();
	printf("\n");
	changeUserDefinedTypes(xa, xb, xc, xd);
	xa.print();
	xb.print();
	xc.print();
	xd->print();

	return 0;	
}