#include "UserData.h"
#include <sstream>

using namespace UI;

void UserData::finalize()
{
}

UserData::DataType UserData::defaultDataValue()
{
	return 0;
}

UserData::DataType UI::UserData::randomDataValue()
{
	return rand() % 1000;
}

System::String ^ UserData::convertDataToStr(const DataType& data)
{
	std::stringstream ss;
	/*if (data == nullptr)
	{
		ss << "null";
	}
	else
	{*/
		ss << data;
	//}
	return gcnew System::String(ss.str().c_str());
}

bool UserData::areEqual(const DataType & a, const DataType & b)
{
	return a == b;
}

UserData::PriorityType UserData::defaultPriorityValue()
{
	return rand() % 1000;
}

System::String ^ UserData::convertPriorityToStr(const PriorityType& priority)
{
	std::stringstream ss;
	ss << priority;
	return gcnew System::String(ss.str().c_str());
}

int UserData::comparePriorities(const PriorityType& a, const PriorityType& b)
{
	return b - a;
}

UserData::KeyType UserData::defaultKeyValue()
{
	return rand() % 1000;
}

System::String ^ UserData::convertKeyToStr(const KeyType& key)
{
	std::stringstream ss;
	ss << key;
	return gcnew System::String(ss.str().c_str());
}

int UserData::compareKeys(const KeyType& a, const KeyType& b)
{
	return a - b;
}

UI::UserData::UserData()
{
}
