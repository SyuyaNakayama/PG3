#include <stdio.h>

class Enemy
{
private:
	size_t statePattern_ = 0;
	void Approach() { printf("���݂̍s��:�ߐ�\n"); }
	void Shoot() { printf("���݂̍s��:�ˌ�\n"); }
	void Leave() { printf("���݂̍s��:���E\n"); }
	static void (Enemy::* ActionTable[])();

public:

	void Action()
	{
		(this->*ActionTable[statePattern_++])();
	}
};

void (Enemy::* Enemy::ActionTable[])() =
{
	&Enemy::Approach,&Enemy::Shoot,&Enemy::Leave
};

int main()
{
	Enemy enemy;
	enemy.Action(); // �ߐڂ̍s��
	enemy.Action(); // �ˌ��̍s��
	enemy.Action(); // ���E�̍s��

	return 0;
}