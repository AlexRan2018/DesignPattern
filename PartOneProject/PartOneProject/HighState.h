#pragma once
#include "ScoreState.h"

class HighState : public ScoreState
{
public:
	HighState(ScoreState* InState);

	void CheckState() override;
};

