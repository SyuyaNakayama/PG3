#include <stdio.h>
#include "List.h"
#include <cassert>

template<class T> void Print(List<T>& list);
template<class T> void Insert(List<T>& list);
template<class T> void Edit(List<T>& list);
template<class T> void Erase(List<T>& list);

template<class T>
void (*FuncTable[4])(List<T>& list) = { Print<T>,Insert<T>,Edit<T>,Erase<T> };

int main()
{
	List<const char*> list(3);
	list.Add("banana");
	list.Add("apple");
	list.Add("orange");

	while (true)
	{
		int operateNum = 0;
		printf("[�v�f�̑���]\n");
		printf("1.�v�f�̕\��\n");
		printf("2.�v�f�̑}��\n");
		if (list.Size() != 0)
		{
			printf("3.�v�f�̕ҏW\n");
			printf("4.�v�f�̍폜\n");
		}
		printf("9.�v�f����̏I��\n");
		printf("\n-----------------------\n");
		printf("�����I�����Ă�������\n");
		scanf_s("%d", &operateNum);
		printf("\n");
		if (operateNum == 9) { printf("�v�f������I�����܂�\n"); break; }
		FuncTable<const char*>[operateNum - 1](list);
	}

	return 0;
}

template<class T> void Print(List<T>& list)
{
	while (true)
	{
		int select = 0;
		printf("[�v�f�̕\��]\n");
		printf("1.�v�f�̈ꗗ�\��\n");
		printf("9.�v�f����ɖ߂�\n");
		printf("\n�����I�����Ă�������\n");
		scanf_s("%d", &select);
		printf("\n");
		size_t i = 0;
		switch (select)
		{
		case 1:
			printf("[�v�f�̈ꗗ�\��]\n");
			printf("�v�f��:%zd\n", list.Size());
			printf("�v�f�ꗗ:{\n");
			for (List<const char*>::Iterator itr = list.Begin(); !list.IsEnd(itr); itr++)
			{
				printf("  %zd:%s\n", i++, *itr);
			}
			printf("}\n\n-----------------------\n");
			printf("1.�v�f�̕\���ɖ߂�\n");
			printf("2.�v�f�̑���ɖ߂�\n");
			scanf_s("%d", &select);
			printf("\n");
			if (select == 2) { return; }
			assert(select == 1);
			break;
		default:	assert(0);
		case 9:		return;
		}
	}
}

template<class T> void Insert(List<T>& list)
{
	size_t index = 0;
	printf("[�v�f�̑}��]\n");
	printf("�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ��-1����͂��Ă��������B\n");
	scanf_s("%zd", &index);
	printf("\n");
	printf("�ǉ�����v�f�̒l����͂��Ă�������\n");
	char* str = new char;
	scanf_s("%s", str, 16);
	printf("\n");
	list.Add(str, index);
	if (index == -1) { index = list.Size() - 1; }
	printf("�v�f%s��%zd�Ԗڂɑ}������܂���\n", str, index);
}

template<class T> void Edit(List<T>& list)
{
	if (list.Size() == 0) { return; }
	size_t index = 0;
	printf("[�v�f�̕ҏW]\n");
	printf("�ҏW�������v�f�̔ԍ����w�肵�Ă�������\n");
	scanf_s("%zd", &index);
	printf("\n");
	if (index < list.Size())
	{
		char* str = new char;
		printf("%zd�Ԗڂ̗v�f�̕ύX����l����͂��Ă�������\n", index);
		scanf_s("%s", str, 16);
		printf("\n");
		*list[index] = (const char*)str;
		printf("%zd�Ԗڂ̗v�f�̒l��%s�ɕύX����܂���\n", index, str);
		return;
	}
	printf("%zd�Ԗڂ̗v�f��������܂���ł���\n", index);
}

template<class T> void Erase(List<T>& list)
{
	if (list.Size() == 0) { return; }
	size_t index = 0;
	printf("[�v�f�̍폜]\n");
	printf("�폜�������v�f�̔ԍ����w�肵�Ă�������\n");
	scanf_s("%zd", &index);
	printf("\n");
	if (index < list.Size())
	{
		printf("%zd�Ԗڂ̗v�f%s���폜���܂���\n", index, list[index]->source);
		list.Delete(index);
		return;
	}
	printf("%zd�Ԗڂ̗v�f��������܂���ł���\n", index);
}
