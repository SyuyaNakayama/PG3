#include <stdio.h>

int Wage(unsigned int workTime)
{
	switch (workTime)
	{
	case 0:
		return 0;
	case 1:
		return 100;
	default:
		return Wage(workTime - 1) * 2 - 50;
	}
}

int main()
{
	for (size_t i = 1; i <= 10; i++)
	{
		printf("ˆê”Ê’À‹à:1072‰~@");
		printf("Ä‹A’À‹à:%5d‰~\n",Wage(i));
	}

	return 0;
}