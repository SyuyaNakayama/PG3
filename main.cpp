#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <functional>

int main()
{
	srand(time(NULL));

	const bool JUDGE_TABLE[2][2] =
	{
		{false,true},{true,false}
	};

	int select;
	// 予想
	while (1)
	{
		printf("出目を予想して下さい。\n");
		printf("1:奇数(半)\n2:偶数(丁)\n");
		scanf_s("%d", &select);
		if (select == 1 || select == 2) { break; }
		else { printf("正しい数を入力して下さい。\n\n"); }
	}

	std::function<int(int)> dice = [](int waitTime)
	{
		printf("判定中です、ちょっと待ってね >o<\n");
		Sleep(waitTime * 1000);
		int num = rand() % 6 + 1;
		printf("出目:%d\n", num);
		return num;
	};
	
	// 判定
	if (JUDGE_TABLE[select - 1][dice(3) % 2]) { printf("大当たり！！\n"); }
	else { printf("残念無念再来年...\n"); }

	return 0;
}