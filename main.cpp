#include <stdio.h>

class Enemy
{
private:
	size_t statePattern_ = 0;
	void Approach() { printf("現在の行動:近接\n"); }
	void Shoot() { printf("現在の行動:射撃\n"); }
	void Leave() { printf("現在の行動:離脱\n"); }
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
	enemy.Action(); // 近接の行動
	enemy.Action(); // 射撃の行動
	enemy.Action(); // 離脱の行動

	return 0;
}