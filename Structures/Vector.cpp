#include "Vector.h"
#include "stdlib.h"
#include "string.h"
#include "DSRoutines.h"

using namespace DS;

Vector::Vector(size_t size)
{
	size_ = size;
	memory_ = calloc(size, 1);
}

// Vector::Vector(size_t size) :
//	 size_(size),
//	 memory_(calloc(size, 1))
// {
// }

Vector::Vector(const Vector& other) 
{
	size_ = other.size_;
	memory_ = calloc(size_, 1);

	memcpy(memory_, other.memory_, size_);
}

// Vector::Vector(const Vector& other) :
//	 Vector(other.size_)
// {
//	 memcpy(memory_, other.memory_, size_);
// }

Vector::~Vector()
{
	free(memory_);
}

Structure* Vector::clone() const
{
	Vector* clone = new Vector(*this);
	return clone;
}

Structure& Vector::operator=(const Structure & other)
{
	const Vector& temp = dynamic_cast<const Vector&>(other);
	*this = temp;
	return *this;
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other) {
		size_ = other.size_;
		memory_ = realloc(memory_, size_);
		memcpy(memory_, other.memory_, size_);
	}

	return *this;
}

bool Vector::operator==(const Vector& other) const
{
	return size_ == other.size_ && memcmp(memory_, other.memory_, size_) == 0;
}

size_t Vector::size() const
{
	return size_;
}

byte& Vector::operator[](const int index)
{
	DSRoutines::rangeCheck(index, size_, true);

	byte& temp = *(reinterpret_cast<byte*>(memory_) + index);

	return temp;
}

byte Vector::operator[](const int index) const
{
	DSRoutines::rangeCheck(index, size_, true);

	byte temp = *(reinterpret_cast<byte*>(memory_) + index);

	return temp;
}

bool Vector::byteNthBitGet(int B, int n)
{
	DSRoutines::rangeCheck(B, size_, true);
	DSRoutines::rangeCheck(n, 8, true);

	return ((*this)[B] >> n) & 1;
}

byte Vector::byteNthBitTo0(int B, int n)
{
	DSRoutines::rangeCheck(B, size_, true);
	DSRoutines::rangeCheck(n, 8, true);

	return (*this)[B] &= ~(1 << n);
}

byte Vector::byteNthBitTo1(int B, int n)
{
	DSRoutines::rangeCheck(B, size_, true);
	DSRoutines::rangeCheck(n, 8, true);

	return (*this)[B] |= (1 << n);
}

byte Vector::byteNthBitToggle(int B, int n)
{
	DSRoutines::rangeCheck(B, size_, true);
	DSRoutines::rangeCheck(n, 8, true);

	return (*this)[B] ^= (1 << n);
}

byte& Vector::readBytes(const int index, const int count, byte& dest)
{
	DSRoutines::rangeCheck(index, size_, true);
	DSRoutines::rangeCheck(index + count, size_ + 1, true);
	DSRoutines::rangeCheck(count, size_ + 1, true);

	memcpy(&dest, reinterpret_cast<byte*>(memory_) + index, count);
	return dest;
}

void DS::Vector::copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length)
{
	DSRoutines::rangeCheck(srcStartIndex, src.size_, true);
	DSRoutines::rangeCheck(srcStartIndex + length, src.size_, true);

	DSRoutines::rangeCheck(destStartIndex, dest.size_, true);
	DSRoutines::rangeCheck(destStartIndex + length, dest.size_, true);

	DSRoutines::rangeCheck(length, src.size_ + 1, true);

	if (&src != &dest) 
	{
		memcpy(reinterpret_cast<byte*>(dest.memory_) + destStartIndex,
			   reinterpret_cast<byte*>(src.memory_) + srcStartIndex,
			   length);
	}
	else 
	{
		memmove(reinterpret_cast<byte*>(dest.memory_) + destStartIndex,
			    reinterpret_cast<byte*>(src.memory_) + srcStartIndex,
		 	    length);
	}
}

byte* DS::Vector::getByteAddress(const int index)
{
	DSRoutines::rangeCheck(index, size_, true);

	// return &(*this)[index];
	return reinterpret_cast<byte*>(memory_) + index;
}