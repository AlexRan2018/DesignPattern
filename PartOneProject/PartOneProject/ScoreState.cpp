#include "ScoreState.h"
#include "ScoreContext.h"

void ScoreState::AddScore(int InScore)
{
	Score += InScore;
	cout << "加上：" << InScore << "分，\t当前分数：" << Score << endl;
	CheckState();
	cout << "当前状态：" << MyScoreContext->my_state()->state_name() << endl;
}
