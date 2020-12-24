#pragma once
#include <iostream>
using namespace std;

class ScoreContext;

class ScoreState
{
public:
	virtual ~ScoreState() = default;;
	virtual void CheckState() = 0;
	virtual void AddScore(int InScore);


	string state_name() const
	{
		return StateName;
	}

	void set_state_name(const string& state_name)
	{
		StateName = state_name;
	}

	ScoreContext* my_score_context() const
	{
		return MyScoreContext;
	}

	int score() const
	{
		return Score;
	}

protected:
	ScoreContext* MyScoreContext;
	string StateName;
	int Score;
};

