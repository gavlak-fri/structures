#pragma once

#include "List.h"
#include "Iterator.h"

namespace DS
{
	template<typename T>
	class ArrayList :
		public List<T>
	{
	protected:
		class ArrayListIterator :
			public StructureIterator<T>
		{		
		public:
			bool operator!=(const StructureIterator<T>& other) const override;
			const T& operator*() const override;
			StructureIterator<T>& operator++() override;

			StructureIterator* clone() const override;
		private:
			// atributy
		};
	public:
		ArrayList(const size_t initialCapacity = 2, const EqualityFunction<T>& equalityFunction = functionEqual);
		ArrayList(const ArrayList<T>& other);
		~ArrayList() override;

		Structure* clone() const override;
		Structure& operator=(const Structure& other) override;
		List<T>& operator=(const List<T>& other) override;
		ArrayList<T>& operator=(const ArrayList<T>& other);

		size_t size() const override;
		T& operator[](const int index) override;
		const T& operator[](const int index) const override;

		void add(const T& data) override;
		void insert(const T& data, const int index) override;
		bool tryRemove(const T& data) override;
		T& removeAt(const int index) override;
		int getIndexOf(const T& data) override;
		void clear() override;

		void shrinkToFit();

		Iterator<T> begin() const override;
		Iterator<T> end() const override;
	private:
		// atributy

		void ensureCapacity();
		void changeCapacity(size_t newCapacity);
	};

	template<typename T>
	ArrayList<T>::ArrayList(const size_t initialCapacity, const EqualityFunction<T>& equalityFunction) 
	{
    throw -1;
	}

	template<typename T>
	ArrayList<T>::ArrayList(const ArrayList<T>& other) 
	{
    throw -1;
	}

	template<typename T>
	ArrayList<T>::~ArrayList()
	{
	}

	template<typename T>
	Structure* ArrayList<T>::clone() const
	{
		throw -1;
	}

	template<typename T>
	Structure& ArrayList<T>::operator=(const Structure & other)
	{
		throw -1;		
	}

	template<typename T>
	List<T>& ArrayList<T>::operator=(const List<T>& other)
	{
		throw -1;
	}

	template<typename T>
	ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other)
	{
		throw -1;
	}

	template<typename T>
	size_t ArrayList<T>::size() const
	{
		throw -1;
	}

	template<typename T>
	T& ArrayList<T>::operator[](const int index)
	{
		throw -1;
	}

	template<typename T>
	const T& ArrayList<T>::operator[](const int index) const
	{
		throw -1;
	}

	template<typename T>
	void ArrayList<T>::add(const T& data)
	{
		throw -1;	
	}

	template<typename T>
	void ArrayList<T>::insert(const T& data, const int index)
	{
		throw -1;
	}

	template<typename T>
	bool ArrayList<T>::tryRemove(const T& data)
	{
		throw -1;
	}

	template<typename T>
	T& ArrayList<T>::removeAt(const int index)
	{
		throw -1;
	}

	template<typename T>
	int ArrayList<T>::getIndexOf(const T& data)
	{
		throw -1;
	}

	template<typename T>
	void ArrayList<T>::clear()
	{
		throw -1;
	}

	template<typename T>
	void ArrayList<T>::shrinkToFit()
	{
		throw -1;
	}

	template<typename T>
	Iterator<T> ArrayList<T>::begin() const
	{
		throw -1;
	}

	template<typename T>
	Iterator<T> ArrayList<T>::end() const
	{
		throw -1;
	}

	template<typename T>
	inline void ArrayList<T>::ensureCapacity()
	{
		throw -1;
	}

	template<typename T>
	void ArrayList<T>::changeCapacity(size_t newCapacity)
	{
		throw -1;
	}

	template<typename T>
	ArrayList<T>::ArrayListIterator::ArrayListIterator(const ArrayList<T>* arrayList, int pos)
	{
    throw -1;
	}

	template<typename T>
	bool ArrayList<T>::ArrayListIterator::operator!=(const StructureIterator<T>& other) const
	{
		throw -1;
	}

	template<typename T>
	const T& ArrayList<T>::ArrayListIterator::operator*() const
	{
		throw -1;
	}

	template<typename T>
	StructureIterator<T>& ArrayList<T>::ArrayListIterator::operator++()
	{
		throw -1;
	}

	template<typename T>
	StructureIterator<T> * ArrayList<T>::ArrayListIterator::clone() const
	{
		throw -1;
	}

}