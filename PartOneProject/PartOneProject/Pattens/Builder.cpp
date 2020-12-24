
#include <iostream>
#include <string>
using namespace std;

class IDrink
{
public:
	string type_name() const
	{
		return TypeName;
	}

	void set_type_name(const string& type_name)
	{
		TypeName = type_name;
	}

protected:
	string TypeName;
};

class Cole : public IDrink
{
public:
	Cole() { TypeName = "Cole"; };	
};

class XueBi : public IDrink
{
public:
	XueBi() { TypeName = "XueBi"; };
};

class IMainFood
{
public:
	string type_name() const
	{
		return TypeName;
	}

	void set_type_name(const string& type_name)
	{
		TypeName = type_name;
	}

protected:
	string TypeName;
};

class Hamburger : public IMainFood
{
public:
	Hamburger() { TypeName = "Hamburger"; }
};

class Rice : public IMainFood
{
public:
	Rice() { TypeName = "Rice"; }
};


class TaoCan
{
public:
	TaoCan()
	{
		Food = new Hamburger;
		MyDrink = new Cole;
	};

	virtual ~TaoCan() {
		Food = nullptr;
		MyDrink	= nullptr;
	}

	void ShowContent() const
	{
		cout << Food->type_name() << " + " << MyDrink->type_name() << endl;
	}


	IMainFood* food() const
	{
		return Food;
	}

	void set_food(IMainFood* food)
	{
		Food = food;
	}

	IDrink* my_drink() const
	{
		return MyDrink;
	}

	void set_my_drink(IDrink* my_drink)
	{
		MyDrink = my_drink;
	}

protected:
	IMainFood* Food;
	IDrink* MyDrink;
};

class TaoCanBuilder
{
public:
	TaoCanBuilder(TaoCan* InTaoCan) :MyTaoCan(InTaoCan) {}
	~TaoCanBuilder() { MyTaoCan = nullptr; }
	
	virtual TaoCanBuilder* PickMainFood(IMainFood* InFood)
	{
		MyTaoCan->set_food(InFood);
		return this;
	}
	virtual TaoCanBuilder* PickDrink(IDrink* InDrink)
	{
		MyTaoCan->set_my_drink(InDrink);
		return this;
	}

private:
	TaoCan* MyTaoCan;
};

//void main()
//{
//	//默认套餐
//	TaoCan* A = new TaoCan;
//	A->ShowContent();
//
//	//自定义
//	TaoCan* B = new TaoCan;
//	TaoCanBuilder* Builder = new TaoCanBuilder(B);
//	Builder->PickDrink(new XueBi)->PickMainFood(new Rice);
//	B->ShowContent();
//}