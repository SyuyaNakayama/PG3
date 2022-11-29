#pragma once

template<class T> class List
{
private:
	struct ListStruct
	{
		T source{};
		ListStruct* prev = nullptr, * next = nullptr;

		void operator=(T source_) { source = source_; }
		ListStruct(T source_ = NULL) { source = source_; }
	};

	ListStruct* start = nullptr, * end = nullptr;
	size_t size = 0, arraySize = 0, sumSize = 0;
public:
	class Iterator
	{
		ListStruct* itr;

	public:
		ListStruct* Get() { return itr; }
		void Set(ListStruct* lststr) { itr = lststr; }
		void operator++(int) { itr = itr->next; }
		void operator--(int) { itr = itr->prev; }
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

	List() { start = new ListStruct(), end = new ListStruct(); }
	~List();
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
	ListStruct* operator[](size_t index)
	{
		Iterator itr = Begin();
		itr + index;
		return itr.Get();
	}
	bool IsEnd(Iterator itr) { return itr.Get() == end; }
	size_t Size() { return size; }
};

template<class T> List<T>::~List()
{
	for (Iterator itr = Begin(); !IsEnd(itr); itr++)
	{
		delete itr.Get()->prev;
		itr.Get()->prev = nullptr;
	}
	delete end; end = nullptr;
}

// ÅŒã”ö‚Ö‚Ì‘}“ü‚Ìê‡AaddPlace‚É-1‚ğ‘ã“ü
// ‚³‚ç‚ÉaddPlace‚ªsizeˆÈã‚ÌAÅŒã”ö‚É‘ã“ü
template<class T> void List<T>::Add(T source, size_t addPlace)
{
	Iterator itr{};
	ListStruct* newList = new ListStruct(source);

	if (++size == 1)
	{
		start->next = newList;
		newList->prev = start;
		newList->next = end;
		end->prev = newList;
		return;
	}
	// ÅŒã‚É’Ç‰Á
	if (size - 1 <= addPlace)
	{
		itr = End();
		itr.Get()->next = newList;
		newList->prev = itr.Get();
		newList->next = end;
		end->prev = newList;
		return;
	}
	// Å‰‚É’Ç‰Á
	if (addPlace == 0)
	{
		itr = Begin();
		start->next = newList;
		newList->prev = start;
		newList->next = itr.Get();
		itr.Get()->prev = newList;
		return;
	}
	// “r’†‚É’Ç‰Á
	itr = Begin() + addPlace - 1;
	Iterator itr2 = Begin() + addPlace;
	itr.Get()->next = newList;
	newList->prev = itr.Get();
	itr2.Get()->prev = newList;
	newList->next = itr2.Get();
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
		delete end->prev;
		end->prev = itr.Get();
		return;
	}
	// Å‰‚ğíœ
	if (delPlace == 0)
	{
		itr = Begin() + 1;
		delete start->next;
		start->next = itr.Get();
		itr.Get()->prev = start;
		return;
	}
	// “r’†‚ğíœ
	delete Iterator(Begin() + delPlace).Get();
	itr = Begin() + delPlace - 1;
	Iterator itr2 = Begin() + delPlace + 1;
	itr.Get()->next = itr2.Get();
	itr2.Get()->prev = itr.Get();
}

/* •]‰¿‰Û‘è‚Ì‘—¿
https://docs.google.com/presentation/d/1OR8eWWDB1_yk0eZ-8JcLQ94dGbxrdbBVIjmaKK76-wA/edit#slide=id.g17aa345cd42_0_1184
*/