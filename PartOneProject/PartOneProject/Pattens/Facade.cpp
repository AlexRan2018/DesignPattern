#include <iostream>

using namespace std;

class SubA
{
public:
	void DisplayA()
	{
		cout << "SubA : DisplayA" << endl;
	}
};

class SubB
{
public:
	void DisplayB()
	{
		cout << "SubB : DisplayB" << endl;
	}
};

class SubC
{
public:
	void DisplayC()
	{
		cout << "SubC : DisplayC" << endl;
	}
};

class Enter
{
public:
	Enter()
	{
		subA = new SubA;
		subB = new SubB;
		subC = new SubC;
	}

	void DisplayAll()
	{
		subA->DisplayA();
		subB->DisplayB();
		subC->DisplayC();
	}
	
protected:
	SubA* subA;
	SubB* subB;
	SubC* subC;
};

//int main()
//{
//	Enter* enter = new Enter;
//	enter->DisplayAll();
//	
//	return 0;
//}