#pragma once

#include "Structure.h"

namespace DS {
	template<typename T> class Array;

	class Vector : public Structure
	{
		template<typename T> friend class DS::Array;
	public:
		void *sp;
		Vector(size_t size);
		Vector(const Vector& other);
		~Vector();

		Structure* clone() const override;

		Structure& operator=(const Structure& other) override;
		Vector& operator=(const Vector& other);
		bool operator==(const Vector& other) const;

		size_t size() const;

		byte& operator[](const int index);
		byte  operator[](const int index) const;

		bool byteNthBitGet(int B, int n);
		byte byteNthBitTo0(int B, int n);
		byte byteNthBitTo1(int B, int n);
		byte byteNthBitToggle(int B, int n);
		
		byte& readBytes(const int index, const int count, byte& dest);

		static void copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length);
	protected:
		byte* getByteAddress(const int index);

	private:
		// atributy
	};

}