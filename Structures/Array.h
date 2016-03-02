#pragma once

#include "Structure.h"

namespace DS 
{
	
	template<typename T> 
	class Array	: 
		public Structure
	{
	public:
		Array(const size_t size);
		Array(const Array<T>& other);
		~Array() override;
		
		Structure* clone() const override;
		Structure& operator=(const Structure& other) override;
		Array<T>& operator=(const Array<T>& other);

		size_t size() const;
		T& operator[](const int index);
		const T operator[](const int index) const;

		static void copy(const Array<T>& src, const int srcStartIndex, Array<T>& dest, const int destStartIndex, const int length);

	private:
		// atributy

	private:
		int mapArrayIndexToVectorIndex(const int index) const;
	};

	template<typename T>
	Array<T>::Array(const size_t size) 
	{
    throw -1;
	}

	template<typename T>
	Array<T>::Array(const Array<T>& other) 
	{
    throw -1;
	}

	template<typename T>
	Array<T>::~Array()
	{
	}

	template<typename T>
	Structure* Array<T>::clone() const
	{
		throw -1;
	}

	template<typename T>
	Structure& Array<T>::operator=(const Structure& other)
	{
		throw -1;
	}

	template<typename T>
	Array<T>& Array<T>::operator=(const Array<T>& other)
	{
		throw -1;
	}
	
	template<typename T>
	size_t Array<T>::size() const
	{
		throw -1;
	}

	template<typename T>
	T& Array<T>::operator[](const int index)
	{
		throw -1;
	}

	template<typename T>
	const T Array<T>::operator[](const int index) const
	{
		throw -1;
	}

	template<typename T>
	void Array<T>::copy(const Array<T>& src, const int srcStartIndex, Array<T>& dest, const int destStartIndex, const int length)
	{
		throw -1;
	}

	template<typename T>
	inline int Array<T>::mapArrayIndexToVectorIndex(const int index) const
	{
		throw -1;
	}
}

