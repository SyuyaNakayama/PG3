#include <stdio.h>
#include <array>

class Enemy
{
private:
	static bool isExist_;

public:
	void SetIsExist(bool isExist) { isExist_ = isExist; }
	void PrintState()
	{
		if (isExist_) { printf("生存\n"); }
		else { printf("消滅\n"); }
	}
};

bool Enemy::isExist_ = true;

int main()
{
	std::array<Enemy, 6> enemies{};
	// 敵状態を表示
	for (int i = 0; i < enemies.size(); i++)
	{
		printf("敵%dの状態:", i);
		enemies[i].PrintState();
	}
	// enemies[3]を倒した
	enemies[3].SetIsExist(false);
	printf("敵3を倒した！！\n");
	// 敵状態を再表示
	for (int i = 0; i < enemies.size(); i++)
	{
		printf("敵%dの状態:", i);
		enemies[i].PrintState();
	}

	return 0;
}