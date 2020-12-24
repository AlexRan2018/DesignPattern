#include <iostream>

using namespace std;

class Player
{
public:	
	virtual ~Player() = default;
	virtual void Attack() = 0;

protected:
	string Name;
};

class DefaultMode : public Player 
{
public:
	DefaultMode() { Name = "Default Mode"; }

	void Attack() override
	{
		cout <<"Attack" << endl;
	}
};

class Decorator : public Player
{
public:
	explicit Decorator(Player* my_player)
		: MyPlayer(my_player)
	{
	}
	void Attack() override
	{
		cout << Name + "Attack" << endl;
	}
	
protected:
	Player* MyPlayer;
};

class ModeHero : public Decorator
{
public:
	explicit ModeHero(Player* my_player)
		: Decorator(my_player)
	{
		Name = "Hero Mode";
	}
	
	void Attack() override
	{
		Decorator::Attack();
		HeroAttack(3);
	}

	void HeroAttack(const int AttTimes)
	{
		for (int i = 0; i < AttTimes; ++i)
		{
			MyPlayer->Attack();
		}
	}	
};

class GodMode : public Decorator
{
public:
	explicit GodMode(Player* my_player)
		: Decorator(my_player)
	{
	}

	void Attack() override
	{
		Decorator::Attack();
		GodAttack();
	}

	void GodAttack()
	{
		cout << "GG!!!" << endl;
	}
};

//int main()
//{
//	Player* MyDefPlayer = new DefaultMode;
//	MyDefPlayer->Attack();
//
//	Player* MyHeroPlayer = new ModeHero(MyDefPlayer);
//	MyHeroPlayer->Attack();
//	cout << "==========================" << endl;
//	
//	Player* MyGodPlayer = new GodMode(MyDefPlayer);
//	MyGodPlayer->Attack();
//	cout << "==========================" << endl;
//
//	Player* MyGod2Player = new GodMode(MyHeroPlayer);
//	MyGod2Player->Attack();
//}
