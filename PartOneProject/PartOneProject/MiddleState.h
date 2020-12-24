#pragma once
#include "ScoreState.h"

class MiddleState : public ScoreState
{
public:
	MiddleState(ScoreState* InScoreState);
	
	
	void CheckState() override;
};

