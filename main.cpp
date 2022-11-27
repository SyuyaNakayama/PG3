#include <stdio.h>
#include "List.h"

int main()
{
	List<int> list(7);
	for (size_t i = 0; i < 5; i++)
	{
		list.Add(i);
	}
	list.Add(6, 3);
	list.Add(7, 1);
	list.Add(8, 7);
	list.Add(5, 7);

	for (List<int>::Iterator itr = list.Begin(); !list.IsEnd(itr); itr++)
	{
		static int i = 0;
		printf("%d:%d\n", i++, *itr);
	}

	return 0;
}
