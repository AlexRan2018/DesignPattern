#include <iostream>
#include <list>
#include <string>

using namespace std;

//场景：挂机游戏自动打BOSS——BOSS活着，英雄开始攻击；BOSS死亡，英雄停止攻击。

class Character
{
public:


	Character(float hp, float att, const string& name)
		: Hp(hp),
		  Att(att),
		  Name(name)
	{
	}

	bool IsAlive()
	{
		return Hp > 0 ? true : false;
	}


	float hp() const
	{
		return Hp;
	}

	void set_hp(float hp)
	{
		Hp = hp;
	}

	float att() const
	{
		return Att;
	}

	void set_att(float att)
	{
		Att = att;
	}

	string name() const
	{
		return Name;
	}

	void set_name(const string& name)
	{
		Name = name;
	}

protected:
	float Hp;
	float Att;
	string Name;
};

class Hero : public Character
{
public:
	Hero(float hp, float att, const string& name)
		: Character(hp, att, name)
	{
	}

	void Attack(Character* InBoss)
	{
		cout << "Hero " << Name << " is attacking" << endl
			<< " Deal " << Att << " damage." << endl;
		InBoss->set_hp(InBoss->hp() - Att);

		cout << InBoss->name() << " Hp >>>>>>>>>>>>>> " << std::to_string(InBoss->hp()) << " <<<<<<<<<<<<<<<" << endl;
	}

	void StopAttack()
	{
		cout << "Hero " << Name << " stop attacking." << endl;
	}

};

class Boss : public Character
{
public:

	Boss(float hp, float att, const string& name)
		: Character(hp, att, name)
	{
	}

	void AddHero(Hero* InHero)
	{
		Heroes.push_back(InHero);
	}
	void RemoveHero(Hero* InHero)
	{
		Heroes.remove(InHero);
	}

	void BroadCastBossAppear()
	{
		for (list<Hero*>::iterator it = Heroes.begin(); it != Heroes.end(); ++it)
		{
			if (Hp > 0)
			{
				(*it)->Attack(this);
			}
		}
	}

	void BroadCastBossDead()
	{
		for (list<Hero*>::iterator it = Heroes.begin(); it != Heroes.end(); ++it)
		{
			(*it)->StopAttack();
		}
	}

protected:
	list<Hero*> Heroes;
};


//int main(int argc, char* argv[])
//{
//	Hero* Tom = new Hero(100, 10, "Tom");
//	Hero* June = new Hero(100, 8, "June");
//	Hero* Will = new Hero(100, 12, "Will");
//	
//	Boss* BossA = new Boss(100, 50,"BossAAAA");
//	
//	BossA->AddHero(Tom);
//	BossA->AddHero(June);
//	BossA->AddHero(Will);
//	
//	while (BossA->IsAlive())
//	{
//		BossA->BroadCastBossAppear();
//	}
//	BossA->BroadCastBossDead();
//	
//	cout << endl << endl << "New Boss is coming!" << endl << endl << endl;
//	Boss* BossB = new Boss(200, 50,"BossBBBB");
//	BossB->AddHero(Tom);
//	BossB->AddHero(June);
//	BossB->AddHero(Will);
//	
//	//Will下线
//	BossB->RemoveHero(Will);
//	
//	while (BossB->IsAlive())
//	{
//		BossB->BroadCastBossAppear();
//	}
//	BossB->BroadCastBossDead();
//
//	delete Tom;
//	delete June;
//	delete Will;
//	delete BossA;
//	delete BossB;
//}
