#include "Vector.h"
#include "stdlib.h"

using namespace DS;

Vector::Vector(size_t size)
{
	sp = malloc(size);
}

Vector::Vector(const Vector& other) 
{
	other.clone()
}

Vector::~Vector()
{
	free(sp);
}

Structure* Vector::clone() const
{
	throw -1;
}

Structure & Vector::operator=(const Structure & other)
{
	throw -1;
}

Vector& Vector::operator=(const Vector& other)
{
	throw -1;
}

bool Vector::operator==(const Vector& other) const
{
	throw -1;
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
