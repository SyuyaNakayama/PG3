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
		if (isExist_) { printf("¶‘¶\n"); }
		else { printf("Á–Å\n"); }
	}
};

bool Enemy::isExist_ = true;

int main()
{
	std::array<Enemy, 6> enemies{};
	// “Gó‘Ô‚ğ•\¦
	for (int i = 0; i < enemies.size(); i++)
	{
		printf("“G%d‚Ìó‘Ô:", i);
		enemies[i].PrintState();
	}
	// enemies[3]‚ğ“|‚µ‚½
	enemies[3].SetIsExist(false);
	printf("“G3‚ğ“|‚µ‚½II\n");
	// “Gó‘Ô‚ğÄ•\¦
	for (int i = 0; i < enemies.size(); i++)
	{
		printf("“G%d‚Ìó‘Ô:", i);
		enemies[i].PrintState();
	}

	return 0;
}