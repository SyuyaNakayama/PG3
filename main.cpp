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
	// �\�z
	while (1)
	{
		printf("�o�ڂ�\�z���ĉ������B\n");
		printf("1:�(��)\n2:����(��)\n");
		scanf_s("%d", &select);
		if (select == 1 || select == 2) { break; }
		else { printf("������������͂��ĉ������B\n\n"); }
	}

	std::function<int(int)> dice = [](int waitTime)
	{
		printf("���蒆�ł��A������Ƒ҂��Ă� >o<\n");
		Sleep(waitTime * 1000);
		int num = rand() % 6 + 1;
		printf("�o��:%d\n", num);
		return num;
	};
	
	// ����
	if (JUDGE_TABLE[select - 1][dice(3) % 2]) { printf("�哖����I�I\n"); }
	else { printf("�c�O���O�ė��N...\n"); }

	return 0;
}