#include <iostream>

using namespace std;

class WeaponStrategy
{
public:
	virtual ~WeaponStrategy() = default;
	virtual void UseWeapon() = 0;
};

class SwordStrategy : public WeaponStrategy
{
public:
	void UseWeapon() override
	{
		cout << "Use Sword" << endl;
	}
};

class AxeStrategy : public WeaponStrategy
{
public:
	void UseWeapon() override
	{
		cout << "Use Axe" << endl;
	}
};

class Character
{
public:
	~Character()
	{
		delete MyWeaponStrategy;
	}
	void EquipmentWeapon(WeaponStrategy* InStrategy)
	{
		MyWeaponStrategy = InStrategy;
	}

	void Attack()
	{
		cout << "Character is attacking : " << endl;
		MyWeaponStrategy->UseWeapon();
	}
	
protected:
	WeaponStrategy* MyWeaponStrategy = nullptr;
};

//int main(int argc, char* argv[])
//{
//	Character* MyCharacter = new Character;
//	MyCharacter->EquipmentWeapon(new SwordStrategy);
//	MyCharacter->Attack();
//
//	MyCharacter->EquipmentWeapon(new AxeStrategy);
//	MyCharacter->Attack();
//
//	delete MyCharacter;
//	
//	return 0;
//}
