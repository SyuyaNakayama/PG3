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
		printf("[要素の操作]\n");
		printf("1.要素の表示\n");
		printf("2.要素の挿入\n");
		if (list.Size() != 0)
		{
			printf("3.要素の編集\n");
			printf("4.要素の削除\n");
		}
		printf("9.要素操作の終了\n");
		printf("\n-----------------------\n");
		printf("操作を選択してください\n");
		scanf_s("%d", &operateNum);
		printf("\n");
		if (operateNum == 9) { printf("要素操作を終了します\n"); break; }
		FuncTable<const char*>[operateNum - 1](list);
	}

	return 0;
}

template<class T> void Print(List<T>& list)
{
	while (true)
	{
		int select = 0;
		printf("[要素の表示]\n");
		printf("1.要素の一覧表示\n");
		printf("9.要素操作に戻る\n");
		printf("\n操作を選択してください\n");
		scanf_s("%d", &select);
		printf("\n");
		size_t i = 0;
		switch (select)
		{
		case 1:
			printf("[要素の一覧表示]\n");
			printf("要素数:%zd\n", list.Size());
			printf("要素一覧:{\n");
			for (List<const char*>::Iterator itr = list.Begin(); !list.IsEnd(itr); itr++)
			{
				printf("  %zd:%s\n", i++, *itr);
			}
			printf("}\n\n-----------------------\n");
			printf("1.要素の表示に戻る\n");
			printf("2.要素の操作に戻る\n");
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
	printf("[要素の挿入]\n");
	printf("要素を追加する場所を指定してください。最後尾に追加する場合は-1を入力してください。\n");
	scanf_s("%zd", &index);
	printf("\n");
	printf("追加する要素の値を入力してください\n");
	char* str = new char;
	scanf_s("%s", str, 16);
	printf("\n");
	list.Add(str, index);
	if (index == -1) { index = list.Size() - 1; }
	printf("要素%sが%zd番目に挿入されました\n", str, index);
}

template<class T> void Edit(List<T>& list)
{
	if (list.Size() == 0) { return; }
	size_t index = 0;
	printf("[要素の編集]\n");
	printf("編集したい要素の番号を指定してください\n");
	scanf_s("%zd", &index);
	printf("\n");
	if (index < list.Size())
	{
		char* str = new char;
		printf("%zd番目の要素の変更する値を入力してください\n", index);
		scanf_s("%s", str, 16);
		printf("\n");
		*list[index] = (const char*)str;
		printf("%zd番目の要素の値が%sに変更されました\n", index, str);
		return;
	}
	printf("%zd番目の要素が見つかりませんでした\n", index);
}

template<class T> void Erase(List<T>& list)
{
	if (list.Size() == 0) { return; }
	size_t index = 0;
	printf("[要素の削除]\n");
	printf("削除したい要素の番号を指定してください\n");
	scanf_s("%zd", &index);
	printf("\n");
	if (index < list.Size())
	{
		printf("%zd番目の要素%sを削除しました\n", index, list[index]->source);
		list.Delete(index);
		return;
	}
	printf("%zd番目の要素が見つかりませんでした\n", index);
}
