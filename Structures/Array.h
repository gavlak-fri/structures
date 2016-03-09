#pragma once

#include "Structure.h"
#include "DSRoutines.h"
#include "Vector.h"
#include "stdexcept"

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
		size_t size_;
		Vector* vector_;


	private:
		int mapArrayIndexToVectorIndex(const int index) const;
	};

	template<typename T>
	Array<T>::Array(const size_t size) :
		size_(size),
		vector_(new Vector(size * sizeof(T)))
	{
	}

	template<typename T>
	Array<T>::Array(const Array<T>& other) :
		size_(other.size_),
		vector_(new Vector(*other.vector_))
	{
	}

	template<typename T>
	Array<T>::~Array()
	{
		delete vector_;
	}

	template<typename T>
	Structure* Array<T>::clone() const
	{
		return new Array<T>(*this);
	}

	template<typename T>
	Structure& Array<T>::operator=(const Structure& other)
	{
		const Array<T>& temp = dynamic_cast<const Array<T>&>(other);
		*this = temp;
		return *this;
	}

	template<typename T>
	Array<T>& Array<T>::operator=(const Array<T>& other)
	{
		if (this != &other) {
			if (this.size_ == other.size) 
			{
				*vector_ = *other.vector_;
			}
			else
			{
				throw std::invalid_argument("Size of arrays must be equal!");
			}
		}

		return *this;
	}
	
	template<typename T>
	size_t Array<T>::size() const
	{
		return size_;
	}

	template<typename T>
	T& Array<T>::operator[](const int index)
	{
		DSRoutines::rangeCheck(index, size_, true);
		
		int indexVector = mapArrayIndexToVectorIndex(index);
		return *(reinterpret_cast<T*>(vector_->getByteAddress(indexVector)));
	}

	template<typename T>
	const T Array<T>::operator[](const int index) const
	{
		DSRoutines::rangeCheck(index, size_, true);

		int indexVector = mapArrayIndexToVectorIndex(index);
		return *(reinterpret_cast<T*>(vector_->getByteAddress(indexVector)));
	}

	template<typename T>
	void Array<T>::copy(const Array<T>& src, const int srcStartIndex, Array<T>& dest, const int destStartIndex, const int length)
	{
		Vector::copy(src.vector_, 
					 mapArrayIndexToVectorIndex(srcStartIndex), 
					 dest.vector_, 
					 mapArrayIndexToVectorIndex(destStartIndex),
					 length * sizeof(T));
	}

	template<typename T>
	inline int Array<T>::mapArrayIndexToVectorIndex(const int index) const
	{
		return index * sizeof(T);
	}
}

