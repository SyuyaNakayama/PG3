#include <stdio.h>
#include "List.h"

int main()
{
	List<int> list(10);
	for (size_t i = 0; i < 5; i++)
	{
		list.Add(i);
	}
	list.Add(5, 0);

	for (List<int>::Iterator itr = list.Begin(); itr.Get() != nullptr; itr++)
	{
		printf("%d\n", *itr);
	}

	return 0;
}
