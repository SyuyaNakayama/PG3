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
		if (isExist_) { printf("����\n"); }
		else { printf("����\n"); }
	}
};

bool Enemy::isExist_ = true;

int main()
{
	std::array<Enemy, 6> enemies{};
	// �G��Ԃ�\��
	for (int i = 0; i < enemies.size(); i++)
	{
		printf("�G%d�̏��:", i);
		enemies[i].PrintState();
	}
	// enemies[3]��|����
	enemies[3].SetIsExist(false);
	printf("�G3��|�����I�I\n");
	// �G��Ԃ��ĕ\��
	for (int i = 0; i < enemies.size(); i++)
	{
		printf("�G%d�̏��:", i);
		enemies[i].PrintState();
	}

	return 0;
}