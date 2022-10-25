#include <stdio.h>
#include <list>
#include <string.h>

using namespace std;

int main()
{
	const char STATION_NAME[28][17] =
	{
		"Tokyo",
		"Kanda",
		"Akihabara",
		"Okachimachi",
		"Ueno",
		"Uguisudani",
		"Nippori",
		"Tabata",
		"Komagome",
		"Sugamo",
		"Otsuka",
		"Ikebukuro",
		"Mejiro",
		"Takadanobaba",
		"Shin-Okubo",
		"Shinjuku",
		"Yoyogi",
		"Harajuku",
		"Shibuya",
		"Ebisu",
		"Meguro",
		"Gotanda",
		"Osaki",
		"Shinagawa",
		"Tamachi",
		"Hamamatsucho",
		"Shimbashi",
		"Yurakucho"
	};

	list<char*> yamanote1970, yamanote2019, yamanote2022;
	list<char*>::iterator it;

	for (const char* str : STATION_NAME)
	{
		yamanote1970.push_back((char*)str);
	}

	yamanote2019 = yamanote1970;
	for (it = yamanote2019.begin(); it != yamanote2019.end(); it++)
	{
		if (*it == STATION_NAME[7])
		{
			yamanote2019.insert(it, (char*)"Nishi-Nippori");
		}
	}

	yamanote2022 = yamanote2019;
	for (it = yamanote2022.begin(); it != yamanote2022.end(); it++)
	{
		if (*it == STATION_NAME[24])
		{
			yamanote2022.insert(it, (char*)"Takanawa-Gateway");
		}
	}

	printf("1970”N‚Ì‰w\n");
	for (char* str : yamanote1970) { printf("%s,", str); }

	printf("\n\n2019”N‚Ì‰w\n");
	for (char* str : yamanote2019) { printf("%s,", str); }

	printf("\n\n2022”N‚Ì‰w\n");
	for (char* str : yamanote2022) { printf("%s,", str); }

	return 0;
}