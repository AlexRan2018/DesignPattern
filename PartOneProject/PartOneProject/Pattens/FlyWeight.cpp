#include <iostream>
#include <map>
using namespace std;

class FlyWeight
{
public:
	FlyWeight(const string& name, int age)
		: Name(name),
		  Age(age)
	{
	}

	string name() const
	{
		return Name;
	}

	void set_name(const string& name)
	{
		Name = name;
	}

	int age() const
	{
		return Age;
	}

	void set_age(int age)
	{
		Age = age;
	}

	void Display()
	{
		cout << "My name is :" << Name << endl
			<< "My age is :" << Age << endl;
	}

private:
	string Name;
	int Age;
};

class FlyWeightFactory
{
public:
	FlyWeightFactory()
	{
		FlyWeightMap.clear();
	}

	~FlyWeightFactory()
	{
		while (!FlyWeightMap.empty())
		{
			FlyWeight* Temp = nullptr;
			map<int, FlyWeight*>::iterator it = FlyWeightMap.begin();
			Temp = it->second;
			FlyWeightMap.erase(it);
			delete Temp;
		}
	}
	
	FlyWeight* GetFlyWeight(const int InId)
	{
		map<int, FlyWeight*>::iterator it =  FlyWeightMap.find(InId);
		
		FlyWeight* fly = nullptr;
		
		if (it == FlyWeightMap.end())
		{
			cout << "Id : " << InId << " is not exist. The system will create a new operator with this id£º" << endl;
			cout << "Enter name£º" << endl;
			string InName;
			cin >> InName;
			cout << "Enter age£º" << endl;
			int InAge;
			cin >> InAge;
			fly = new FlyWeight(InName, InAge);
			FlyWeightMap.insert(pair<int, FlyWeight*>(InId, fly));
			return fly;
		}
		
		return it->second;
	}


protected:
	map<int, FlyWeight*> FlyWeightMap;
};

//int main()
//{
//	FlyWeightFactory* factory = new FlyWeightFactory;
//
//	FlyWeight* fly1 = factory->GetFlyWeight(1);
//	FlyWeight* fly2 = factory->GetFlyWeight(2);
//	FlyWeight* fly3 = factory->GetFlyWeight(2);
//	FlyWeight* fly4 = factory->GetFlyWeight(1);
//
//	fly1->Display();
//	fly2->Display();
//	fly3->Display();
//	fly4->Display();
//
//	delete factory;
//	factory = nullptr;
//	return 0;
//}