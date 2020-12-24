#include "LowState.h"
#include "MiddleState.h"
#include "HighState.h"
#include "ScoreContext.h"

LowState::LowState(ScoreContext* InContext)
{
	MyScoreContext = InContext;
	StateName = "不及格";
	Score = 0;
}
LowState::LowState(ScoreState* InScoreState)
{
	MyScoreContext = InScoreState->my_score_context();
	Score = InScoreState->score();
	StateName = "不及格";
}

void LowState::CheckState()
{
	if (Score >= 60 && Score < 90)
	{
		MyScoreContext->set_my_state(new MiddleState(this));
	}
	else if (Score >= 90)
	{
		MyScoreContext->set_my_state(new HighState(this));
	}
	else
	{
		MyScoreContext->set_my_state(this);
	}
}
