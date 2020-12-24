#include <iostream>

using namespace std;

class ITarget
{
public:
	virtual ~ITarget() = default;
	virtual void Request() = 0;
};

class Adaptee
{
public:
	virtual void SpecificRequest()
	{
		cout << "Adaptee : SpecificRequest" << endl;
	}
};

class Adapter : public ITarget
{
public:	
	void ObjectAdapter(Adaptee* InTee)
	{
		Tee = InTee;
	}
	
	void Request() override
	{
		Tee->SpecificRequest();
	}
protected:
	Adaptee* Tee = nullptr;
};

//int main()
//{
//	Adapter* adapter = new Adapter;
//
//	Adaptee* tee = new Adaptee;
//
//	adapter->ObjectAdapter(tee);
//	adapter->Request();
//	
//	return 0;
//}