// DesignModeProj.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

#define MY_COUT(X) cout<<X<<endl;

enum class ECharacterType
{
	Monk,
	Knight,
	Thief
};

class IWeapon;

class ICharacter
{
public:
	virtual ~ICharacter() = default;

	ECharacterType character_type() const
	{
		return CharacterType;
	}

	void set_character_type(ECharacterType character_type)
	{
		CharacterType = character_type;
	}

	int attack() const
	{
		return Attack;
	}

	void set_attack(int attack)
	{
		Attack = attack;
	}

protected:
	ECharacterType CharacterType;
	int Attack;
};

class IWeapon
{
public:
	virtual ~IWeapon() = default;
	virtual void EquipToCharacter(ICharacter* InCharacter) = 0;

	ICharacter* my_character() const
	{
		return MyCharacter;
	}

	void set_my_character(ICharacter* my_character)
	{
		MyCharacter = my_character;
	}

protected:
	ICharacter* MyCharacter = nullptr;
};

class Monk : public ICharacter
{
public:
	Monk()
	{
		CharacterType = ECharacterType::Monk;
		Attack = 0;
	}
};

class Thief : public ICharacter
{
public:
	Thief()
	{
		CharacterType = ECharacterType::Thief; Attack = 0;
	}
};

class Knight : public ICharacter
{
public:
	Knight()
	{
		CharacterType = ECharacterType::Knight; Attack = 0;
	}
};

class MagicBook : public IWeapon
{
public:
	void EquipToCharacter(ICharacter* InCharacter) override
	{
		switch (InCharacter->character_type())
		{
		case ECharacterType::Monk:InCharacter->set_attack(100); break;
		case ECharacterType::Knight:InCharacter->set_attack(0); break;
		case ECharacterType::Thief:InCharacter->set_attack(0); break;
		default:InCharacter->set_attack(0);
		}
	}
};

class Sword : public IWeapon
{
public:
	void EquipToCharacter(ICharacter* InCharacter) override
	{
		switch (InCharacter->character_type())
		{
		case ECharacterType::Monk:InCharacter->set_attack(10); break;
		case ECharacterType::Knight:InCharacter->set_attack(100); break;
		case ECharacterType::Thief:InCharacter->set_attack(10); break;
		default:InCharacter->set_attack(0);
		}
	}
};

class Gun : public IWeapon
{
public:
	void EquipToCharacter(ICharacter* InCharacter) override
	{
		MyCharacter = InCharacter;
		switch (InCharacter->character_type())
		{
		case ECharacterType::Monk:InCharacter->set_attack(0); break;
		case ECharacterType::Knight:InCharacter->set_attack(10); break;
		case ECharacterType::Thief:InCharacter->set_attack(100); break;
		default:InCharacter->set_attack(0);
		}
	}
};

class Stick : public IWeapon
{
public:
	void EquipToCharacter(ICharacter* InCharacter) override
	{
		MyCharacter = InCharacter;
		switch (InCharacter->character_type())
		{
		case ECharacterType::Monk:InCharacter->set_attack(10); break;
		case ECharacterType::Knight:InCharacter->set_attack(10); break;
		case ECharacterType::Thief:InCharacter->set_attack(10); break;
		default:InCharacter->set_attack(0);;
		}
	}
};

//int main()
//{
//	ICharacter* MyMonk = new Monk;
//	ICharacter* MyThief = new Thief;
//	ICharacter* MyKnight = new Knight;
//
//	IWeapon* MyGun = new Gun;
//
//	MyGun->EquipToCharacter(MyMonk);
//	MyGun->EquipToCharacter(MyThief);
//	MyGun->EquipToCharacter(MyKnight);
//
//	cout << "ºÍÉÐ¹¥»÷Á¦£º " << MyMonk->attack() << "  µÁÔô¹¥»÷Á¦£º " << MyThief->attack() << "  ÆïÊ¿¹¥»÷Á¦£º " << MyKnight->attack() << endl;
//}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
