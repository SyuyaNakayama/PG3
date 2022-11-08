#pragma once
#include <memory>

template<class T> class List
{
private:
	struct ListStruct
	{
		T source{};
		ListStruct* prev = nullptr, * next = nullptr;

		void operator=(T source_) { source = source_; }
	};

	ListStruct* list = nullptr;
	size_t size = 0;
	void Create(const int ARRAY_NUM);
public:
	class Iterator
	{
		ListStruct* itr;

	public:
		ListStruct* Get() { return itr; }
		void Set(ListStruct* lststr) { itr = lststr; }
		T GetSource() { return itr->source; }
		void operator++(T) { itr = itr->next; }
		void operator--(T) { itr = itr->prev; }
		T operator*() { return itr->source; }
	};

	List(const int ARRAY_SIZE) { Create(ARRAY_SIZE); }
	~List() { delete list; list = nullptr; }
	Iterator Begin()
	{
		ListStruct* lst = list;
		size_t i;
		for (i = 0; lst != nullptr; i++) { lst = list[i].prev; }
		Iterator itr{};
		itr.Set(&list[i - 1]);
		return itr;
	}
	void Add(T source, size_t addPlace = -1);
};

template<class T> void List<T>::Create(const int ARRAY_NUM)
{
	if (!list) { list = new ListStruct[ARRAY_NUM]; }
	else
	{
		ListStruct* newList = new ListStruct[ARRAY_NUM];
		newList = list;
		delete list;
		list = newList;
	}
}

// ÅŒã”ö‚Ö‚Ì‘}“ü‚Ìê‡AaddPlace‚É-1‚ğ‘ã“ü
// ‚³‚ç‚ÉaddPlace‚ªsizeˆÈã‚ÌAÅŒã”ö‚É‘ã“ü
template<class T> void List<T>::Add(T source, size_t addPlace)
{
	list[size++] = source;
	if (addPlace == -1 || size <= addPlace)
	{
		if (size == 1) { return; }

		list[size - 2].next = &list[size - 1];
		list[size - 1].prev = &list[size - 2];
		list[size - 1].next = nullptr;
		return;
	}
	if (addPlace != 0)
	{
		list[addPlace - 1].next = &list[size - 1];
		list[addPlace].prev = &list[size - 1];
		list[size - 1].prev = &list[addPlace - 1];
		list[size - 1].next = &list[addPlace];
		return;
	}
	// addPlace == 0‚Ì‚Æ‚«
	list[size - 1].prev = nullptr;
	list[size - 1].next = &list[0];
	list[0].prev = &list[size - 1];
}

/* •]‰¿‰Û‘è‚Ì‘—¿
https://docs.google.com/presentation/d/1OR8eWWDB1_yk0eZ-8JcLQ94dGbxrdbBVIjmaKK76-wA/edit#slide=id.g17aa345cd42_0_1184
*/