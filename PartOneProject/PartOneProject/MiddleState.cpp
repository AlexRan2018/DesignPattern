#include "LowState.h"
#include "MiddleState.h"
#include "HighState.h"
#include "ScoreContext.h"

MiddleState::MiddleState(ScoreState* InScoreState)
{
	MyScoreContext = InScoreState->my_score_context();
	Score = InScoreState->score();
	StateName = "ÖÐµÈ";
}

void MiddleState::CheckState()
{
	if (Score < 90)
	{
		MyScoreContext->set_my_state(new LowState(this));
	}
	else if (Score >= 90)
	{
		MyScoreContext->set_my_state(new HighState(this));
	}
}
