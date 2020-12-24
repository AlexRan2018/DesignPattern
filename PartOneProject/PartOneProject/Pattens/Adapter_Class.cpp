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
	virtual ~Adaptee() = default;
	virtual void SpecificRequest()
	{
		cout << "Adaptee : SpecificRequest" << endl;
	}
};

class ClassAdapter : public ITarget, public Adaptee
{
public:
	ClassAdapter() = default;
	void Request() override
	{
		SpecificRequest();
	}
};

//int main()
//{
//	ITarget* target = new ClassAdapter;
//	target->Request();
//	
//	return 0;
//}