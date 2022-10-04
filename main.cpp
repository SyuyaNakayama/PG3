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
	int n = 5;

	printf("%d", Wage(n));

	return 0;
}