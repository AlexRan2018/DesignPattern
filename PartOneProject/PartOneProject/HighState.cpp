#include "HighState.h"
#include "ScoreContext.h"
#include "LowState.h"
#include "MiddleState.h"

HighState::HighState(ScoreState* InState)
{
	MyScoreContext = InState->my_score_context();
	Score = InState->score();
	StateName = "ÓÅÐã";	
}

void HighState::CheckState()
{
	if (Score < 60)
	{
		MyScoreContext->set_my_state(new LowState(this));
	}
	else if (Score < 90)
	{
		MyScoreContext->set_my_state(new MiddleState(this));
	}
}
