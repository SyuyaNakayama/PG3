#pragma once
#include <stdlib.h>

template<class T> class List
{
private:
	struct ListStruct
	{
		T source{};
		ListStruct* prev = nullptr, * next = nullptr;

		void operator=(T source_) { source = source_; }
	};

	ListStruct* list = nullptr, * start = nullptr, * end = nullptr;
	size_t size = 0, arraySize = 0, sumSize = 0;
public:
	void Create(const size_t ARRAY_NUM);
	class Iterator
	{
		ListStruct* itr;

	public:
		ListStruct* Get() { return itr; }
		void Set(ListStruct* lststr) { itr = lststr; }
		void operator++(T) { itr = itr->next; }
		void operator--(T) { itr = itr->prev; }
		Iterator& operator+(size_t incrementDis)
		{
			for (size_t i = 0; i < incrementDis; i++)
			{
				itr = itr->next;
			}
			return *this;
		}
		Iterator& operator-(size_t decrementDis)
		{
			for (size_t i = 0; i < decrementDis; i++) { itr = itr->prev; }
			return *this;
		}
		T operator*() { return itr->source; }
		bool operator==(Iterator itr) { return this->itr == itr.Get(); }
		bool operator!=(Iterator itr) { return this->itr != itr.Get(); }
	};

	List(const size_t ARRAY_SIZE) { Create(ARRAY_SIZE); }
	List() { Create(0); }
	~List()
	{
		delete[] list; list = nullptr;
	}
	Iterator Begin()
	{
		Iterator itr{};
		itr.Set(start->next);
		return itr;
	}
	Iterator End()
	{
		Iterator itr{};
		itr.Set(end->prev);
		return itr;
	}
	void Add(T source, size_t addPlace = -1);
	void Delete(size_t delPlace = -1);
	T operator[](size_t index)
	{
		Iterator itr = Begin();
		itr + index;
		return *itr;
	}
	bool IsEnd(Iterator itr) { return itr.Get() == end; }
};

template<class T> void List<T>::Create(const size_t ARRAY_NUM)
{
	if (!list)
	{
		list = new ListStruct[ARRAY_NUM];
		start = new ListStruct;
		end = new ListStruct;
	}
	else
	{
		ListStruct* newList = new ListStruct[ARRAY_NUM];
		int i = 0;
		for (Iterator itr = Begin(); !IsEnd(itr); itr++)
		{
			ListStruct* lst = itr.Get();
			newList[i] = *lst;
			if (i == 0) { newList[0].prev = start; }
			else { newList[i].prev = &newList[i - 1]; }
			if (i == size - 1) { newList[i].next = end; }
			else { newList[i].next = &newList[i + 1]; }
			i++;
		}
		sumSize = i;
		start->next = newList;
		end->prev = (newList + i - 1);
		delete[] list;
		list = newList;
	}
	arraySize = ARRAY_NUM;
}

// ÅŒã”ö‚Ö‚Ì‘}“ü‚Ìê‡AaddPlace‚É-1‚ğ‘ã“ü
// ‚³‚ç‚ÉaddPlace‚ªsizeˆÈã‚ÌAÅŒã”ö‚É‘ã“ü
template<class T> void List<T>::Add(T source, size_t addPlace)
{
	if (++sumSize > arraySize) { Create(arraySize + 10); }
	list[size++] = source;
	ListStruct* nowAdd = &list[size - 1];
	Iterator itr{};
	if (size == 1)
	{
		start->next = nowAdd;
		nowAdd->prev = start;
		nowAdd->next = end;
		end->prev = nowAdd;
		return;
	}
	// ÅŒã‚É’Ç‰Á
	if (size - 1 <= addPlace)
	{
		itr = End();
		itr.Get()->next = nowAdd;
		nowAdd->prev = itr.Get();
		nowAdd->next = end;
		end->prev = nowAdd;
		return;
	}
	// Å‰‚É’Ç‰Á
	if (addPlace == 0)
	{
		itr = Begin();
		start->next = nowAdd;
		nowAdd->prev = start;
		nowAdd->next = itr.Get();
		itr.Get()->prev = nowAdd;
		return;
	}
	// “r’†‚É’Ç‰Á
	itr = Begin() + addPlace - 1;
	Iterator itr2 = Begin() + addPlace;
	itr.Get()->next = nowAdd;
	list[size - 1].prev = itr.Get();
	itr2.Get()->prev = nowAdd;
	list[size - 1].next = itr2.Get();
}

template<class T> void List<T>::Delete(size_t delPlace)
{
	Iterator itr{};
	if (size == 0) { return; }

	// ÅŒã‚ğíœ
	if (--size <= delPlace)
	{
		itr = End() - 1;
		itr.Get()->next = end;
		end->prev = itr.Get();
		return;
	}
	// Å‰‚ğíœ
	if (delPlace == 0)
	{
		itr = Begin() + 1;
		start->next = itr.Get();
		itr.Get()->prev = start;
		return;
	}
	// “r’†‚ğíœ
	itr = Begin() + delPlace - 1;
	Iterator itr2 = Begin() + delPlace + 1;
	itr.Get()->next = itr2.Get();
	itr2.Get()->prev = itr.Get();
}

/* •]‰¿‰Û‘è‚Ì‘—¿
https://docs.google.com/presentation/d/1OR8eWWDB1_yk0eZ-8JcLQ94dGbxrdbBVIjmaKK76-wA/edit#slide=id.g17aa345cd42_0_1184
*/