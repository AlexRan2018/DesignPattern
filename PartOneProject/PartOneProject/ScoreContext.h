#pragma once

class ScoreState;
class ScoreContext
{
public:
	ScoreContext():MyState(nullptr){}

	ScoreState* my_state() const
	{
		return MyState;
	}

	void set_my_state(ScoreState* my_state)
	{
		MyState = my_state;
	}

private:
	ScoreState* MyState;
};