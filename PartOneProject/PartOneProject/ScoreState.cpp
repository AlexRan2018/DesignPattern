#include "ScoreState.h"
#include "ScoreContext.h"

void ScoreState::AddScore(int InScore)
{
	Score += InScore;
	cout << "���ϣ�" << InScore << "�֣�\t��ǰ������" << Score << endl;
	CheckState();
	cout << "��ǰ״̬��" << MyScoreContext->my_state()->state_name() << endl;
}
