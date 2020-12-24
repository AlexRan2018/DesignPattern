
#include <iostream>
#include <string>
using namespace std;

enum class ECharacterType
{
	Monster,
	Player
};

class Character
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

	int level() const
	{
		return Level;
	}

	void set_level(int level)
	{
		Level = level;
	}

protected:
	string Name;
	int Level = 0;
};

class Monster : public Character
{
public:
	Monster()
	{
		Name = "Monster";
	}
};

class Player : public Character
{
public:
	Player()
	{
		Name = "Player";
	}
};

class IFactory
{
public:
	virtual ~IFactory() = default;
	virtual Character* CreateHighLevelMonster() = 0;
	virtual Character* CreateLowLevelMonster() = 0;
	virtual Character* CreateHighLevelPlayer() = 0;
	virtual Character* CreateLowLevelPlayer() = 0;
};

class HighLevelCharacterFactory : public IFactory
{
public:
	Character* CreateHighLevelMonster() override
	{
		auto Character = new Monster;
		Character->set_level(50);
		return Character;
	}
	Character* CreateLowLevelMonster() override{return nullptr;}
	Character* CreateHighLevelPlayer() override
	{
		auto Character = new Player;
		Character->set_level(50);
		return Character;
	}
	Character* CreateLowLevelPlayer() override{return nullptr;}
};

class LowLevelCharacterFactory : public IFactory
{
public:
	Character* CreateHighLevelMonster() override{return nullptr;}
	Character* CreateLowLevelMonster() override
	{
		auto Character = new Monster;
		Character->set_level(1);
		return Character;
	}
	Character* CreateHighLevelPlayer() override{return nullptr;}
	Character* CreateLowLevelPlayer() override
	{
		auto Character = new Player;
		Character->set_level(1);
		return Character;
	}
};



//int main()
//{
//	IFactory* MyHighFactory = new HighLevelCharacterFactory;
//	IFactory* MyLowFactory = new LowLevelCharacterFactory;
//	
//	auto HighPlayer = MyHighFactory->CreateHighLevelPlayer();
//	auto LowPlayer = MyLowFactory->CreateLowLevelPlayer();
//	auto HighMonster = MyHighFactory->CreateHighLevelMonster();
//	auto LowMonster = MyLowFactory->CreateLowLevelMonster();
//
//	cout << HighPlayer->name() << ":" << HighPlayer->level() <<endl
//		<< LowMonster->name() << ":" << LowMonster->level() << endl
//		<< LowPlayer->name() << ":" << LowPlayer->level() << endl
//		<< HighMonster->name() << ":" << HighMonster->level() << endl;
//}