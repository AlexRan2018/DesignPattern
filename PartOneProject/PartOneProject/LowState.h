#pragma once
#include "ScoreState.h"

class LowState : public ScoreState
{
public:
	LowState(ScoreContext* InContext);


	LowState(ScoreState* InScoreState);
	

	void CheckState() override;
};

