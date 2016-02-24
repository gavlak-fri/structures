#include "Vector.h"
#include "stdlib.h"
#include "string.h"

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

Structure & Vector::operator=(const Structure & other)
{
	throw -1;
}

Vector& Vector::operator=(const Vector& other)
{
	if (this != &other) {
		size_ = other.size_;
		memory_ = realloc(memory_, size_);
		memcpy(memory_, other.memory_, size_);
	}
}

bool Vector::operator==(const Vector& other) const
{
	return size_ == other.size_ && memcmp(memory_, other.memory_, size_) == 0;
}

size_t Vector::size() const
{
	throw -1;
}

byte& Vector::operator[](const int index)
{
	throw -1;
}

byte Vector::operator[](const int index) const
{
	throw -1;
}

bool Vector::byteNthBitGet(int B, int n)
{
	throw -1;
}

byte Vector::byteNthBitTo0(int B, int n)
{
	throw -1;
}

byte Vector::byteNthBitTo1(int B, int n)
{
	throw -1;
}

byte Vector::byteNthBitToggle(int B, int n)
{
	throw -1;
}

byte& Vector::readBytes(const int index, const int count, byte& dest)
{
	throw -1;
}

void DS::Vector::copy(const Vector& src, const int srcStartIndex, Vector& dest, const int destStartIndex, const int length)
{
	throw -1;
}

byte* DS::Vector::getByteAddress(const int index)
{
	throw -1;
}
