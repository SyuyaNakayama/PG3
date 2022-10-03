#include <stdio.h>

template <typename T>
T Min(T num1, T num2)
{
	if (num1 >= num2) { return num2; }
	return num1;
}

template <>
char Min<char>(char num1, char num2)
{
	printf("”šˆÈŠO‚Í“ü—Í‚Å‚«‚Ü‚¹‚ñ\n");
	return NULL;
}

int main()
{
	int iX = 3, iY = 5;
	float fX = 5.5f, fY = 2.4f;
	double dX = 10.13, dY = 7.77;
	char cX = 24, cY = 18;

	printf("%d\n", Min<int>(iX, iY));
	printf("%f\n", Min<float>(fX, fY));
	printf("%lf\n", Min<double>(dX, dY));
	Min<char>(cX, cY);

	return 0;
}