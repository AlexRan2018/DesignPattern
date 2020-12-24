
#include <iostream>
#include <string>
using namespace std;

class IWeapon
{
public:
	string name() const
	{
		return Name;
	}

	void set_name(const string& name)
	{
		Name = name;
	}

protected:
	string Name;
};

class Axe : public IWeapon
{
public:
	Axe() { Name = "Axe"; }	
};


class Monster
{
public:	
	Monster(IWeapon* weapon, float power)
		: Weapon(weapon),
		Power(power)
	{
	}


	IWeapon* weapon() const
	{
		return Weapon;
	}

	void set_weapon(IWeapon* weapon)
	{
		Weapon = weapon;
	}

	float power() const
	{
		return Power;
	}

	void set_power(float power)
	{
		Power = power;
	}

	virtual Monster* Clone()
	{
		Monster* MySelf = new Monster(*this);
		
		//deep copy
		MySelf->Weapon = new IWeapon(*Weapon);

		return MySelf;
	}
	
	virtual void Attack()
	{
		cout << "Monster use: " <<Weapon->name() <<"\n Power: " << Power << endl;
	}

protected:
	IWeapon* Weapon;
	float Power;
};
//
//void main()
//{
//	IWeapon* MyAxe = new Axe;	
//	Monster* MyMonster1 = new Monster(MyAxe, 50.f);
//	Monster* MyMonster2 = MyMonster1->Clone();
//	Monster* MyMonster3 = MyMonster1->Clone();
//	Monster* MyMonster4 = MyMonster1->Clone();
//
//	MyMonster1->Attack();
//	MyMonster2->Attack();
//	MyMonster3->Attack();
//	MyMonster4->Attack();
//	cout << "========================================" << endl;
//
//	//deep copy testing
//	MyAxe->set_name("Sword");
//	MyMonster1->set_power(10);
//
//	MyMonster1->Attack();
//	MyMonster2->Attack();
//	MyMonster3->Attack();
//	MyMonster4->Attack();
//}