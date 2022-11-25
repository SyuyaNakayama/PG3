#pragma once

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
		Iterator& operator+(size_t incrementDis)
		{
			for (size_t i = 0; i < incrementDis; i++) { itr = itr->next; }
			return *this;
		}
		Iterator& operator-(size_t decrementDis)
		{
			for (size_t i = 0; i < decrementDis; i++) { itr = itr->prev; }
			return *this;
		}
		T operator*() { return itr->source; }
	};

	List(const int ARRAY_SIZE) { Create(ARRAY_SIZE); }
	~List()
	{
		delete list; list = nullptr;
	}
	Iterator Begin()
	{
		for (size_t i = 0; i < size; i++)
		{
			if (list[i].prev != nullptr) { continue; }
			Iterator itr{};
			itr.Set(&list[i]);
			return itr;
		}
	}
	Iterator End()
	{
		for (size_t i = 0; i < size; i++)
		{
			if (list[i].next != nullptr) { continue; }
			Iterator itr{};
			itr.Set(&list[i]);
			return itr;
		}
	}
	void Add(T source, size_t addPlace = -1);
	void Delete(size_t delPlace = -1);
	T operator[](size_t index)
	{
		Iterator itr = Begin();
		itr + index;
		return *itr;
	}
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

// �Ō���ւ̑}���̏ꍇ�AaddPlace��-1����
// �����addPlace��size�ȏ�̎��A�Ō���ɑ��
template<class T> void List<T>::Add(T source, size_t addPlace)
{
	list[size++] = source;
	Iterator itr{};
	if (size == 1) { return; }
	// �Ō�ɒǉ�
	if (size - 1 <= addPlace)
	{
		itr = End();
		itr.Get()->next = &list[size - 1];
		list[size - 1].prev = itr.Get();
		return;
	}
	// �ŏ��ɒǉ�
	if (addPlace == 0)
	{
		itr = Begin();
		list[size - 1].next = itr.Get();
		itr.Get()->prev = &list[size - 1];
		return;
	}
	// �r���ɒǉ�
	itr = Begin() + addPlace - 1;
	Iterator itr2 = Begin() + addPlace;
	itr.Get()->next = &list[size - 1];
	list[size - 1].prev = itr.Get();
	itr2.Get()->prev = &list[size - 1];
	list[size - 1].next = itr2.Get();
}

template<class T> void List<T>::Delete(size_t delPlace)
{
	Iterator itr{};
	if (size == 0) { return; }

	// �Ō���폜
	if (size <= delPlace)
	{
		itr = End() - 1;
		itr.Get()->next = nullptr;
	}
	// �ŏ����폜
	if (delPlace == 0)
	{

	}
}

/* �]���ۑ�̎���
https://docs.google.com/presentation/d/1OR8eWWDB1_yk0eZ-8JcLQ94dGbxrdbBVIjmaKK76-wA/edit#slide=id.g17aa345cd42_0_1184
*/