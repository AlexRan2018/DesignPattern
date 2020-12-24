
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

protected:
	string Name;
};

class Monster : public Character
{
public:
	Monster()
	{
		Name = "Monster";
	}

	int ai_level() const
	{
		return AiLevel;
	}

	void set_ai_level(int ai_level)
	{
		AiLevel = ai_level;
	}

private:
	int AiLevel = 0;
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
	virtual Character* CreateCharacter() = 0;
};

class HighLevelMonsterFactory : public IFactory
{
public:
	Character* CreateCharacter() override
	{
		auto MyMonster = new Monster;
		MyMonster->set_ai_level(50);
		return MyMonster;
	}
};

class PlayerFactory : public IFactory
{
public:
	Character* CreateCharacter() override
	{
		return new Player;
	}
};


//int main()
//{
//	ICharacterFactory* HMFactory = new HighLevelMonsterFactory;
//	auto Monster = HMFactory->CreateCharacter();
//	
//	ICharacterFactory* PFactory = new PlayerFactory;
//	auto Player = PFactory->CreateCharacter();
//	
//	cout << Monster->name() << "========"<< Player->name() << endl;
//}