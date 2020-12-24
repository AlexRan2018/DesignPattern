#include <iostream>
#include <list>
#include <string>
#include <typeinfo>

using namespace std;

class IGoods
{
public:
	virtual ~IGoods() = default;
	virtual float GetPrice() = 0;
	virtual string Display() = 0;
	virtual void AddGoods(IGoods* InGoods) = 0;
	virtual void RemoveGoods(IGoods* InGoods) = 0;
	virtual list<IGoods*> GetChildren() = 0;	
};

class Sells : public IGoods
{
public:

	Sells(const string& name, float price)
		: Name(name),
		  Price(price)
	{
	}

	float GetPrice() override
	{
		return Price;
	}
	string Display() override
	{
		return Name +" : " + std::to_string(Price) +"\n" ;
	}
	list<IGoods*> GetChildren() override
	{
		return list<IGoods*>();
	}

	void AddGoods(IGoods* InGoods) override{}
	void RemoveGoods(IGoods* InGoods) override{}
protected:
	string Name;
	float Price;
};

class Package : public IGoods
{
public:	
	float GetPrice() override
	{
		float Result = 0;
		for (list<IGoods*>::iterator it = ChildrenGoods.begin(); it != ChildrenGoods.end(); ++it)
		{
			Result += (*it)->GetPrice();
		}
		
		return Result;
	}
	string Display() override
	{
		string Result = "";
		for (list<IGoods*>::iterator it = ChildrenGoods.begin(); it != ChildrenGoods.end(); ++it)
		{
			Result += (*it)->Display();
		}
		return Result;
	}	

	void AddGoods(IGoods* InGoods) override
	{
		ChildrenGoods.push_back(InGoods);
	}
	void RemoveGoods(IGoods* InGoods) override
	{
		ChildrenGoods.remove(InGoods);
	}
	list<IGoods*> GetChildren() override
	{
		return ChildrenGoods;
	}
protected:
	list<IGoods*> ChildrenGoods;
};

//int main()
//{
//	IGoods* Candy = new Sells("Candy", 5.5);
//	IGoods* Salt = new Sells("Salt", 1.5);
//	IGoods* Water = new Sells("Water", 2.5);
//	IGoods* Bear = new Sells("Bear", 10);
//
//	IGoods* Bag1 = new Package;
//	Bag1->AddGoods(Candy);
//	Bag1->AddGoods(Salt);
//
//	IGoods* Bag2 = new Package;
//	Bag2->AddGoods(Water);
//
//	IGoods* Bag3 = new Package;
//	Bag3->AddGoods(Bear);
//	Bag3->AddGoods(Bag1);
//	Bag3->AddGoods(Bag2);
//
//	cout << "Bag1 : \n" << Bag1->Display() << "共计: " << Bag1->GetPrice() << " (元)" << endl;
//	cout << "Bag2 : \n" << Bag2->Display() << "共计: " << Bag2->GetPrice() << " (元)" << endl;
//	cout << "Bag3 : \n" << Bag3->Display() << "共计: " << Bag3->GetPrice() << " (元)" << endl;
//	
//	return 0;
//}