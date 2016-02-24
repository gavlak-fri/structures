#include "UserData.h"
#include <sstream>


void UI::UserData::finalize()
{
}

UI::UserData::DataType UI::UserData::defaultDataValue()
{
	/*int* pom = new int;
	*pom = rand() % 1000;*/
	return rand() % 1000;
}

System::String ^ UI::UserData::convertDataToStr(const DataType& data)
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

bool UI::UserData::areEqual(const DataType & a, const DataType & b)
{
	return a == b;
}

UI::UserData::PriorityType UI::UserData::defaultPriorityValue()
{
	return rand() % 1000;
}

System::String ^ UI::UserData::convertPriorityToStr(const PriorityType& priority)
{
	std::stringstream ss;
	ss << priority;
	return gcnew System::String(ss.str().c_str());
}

int UI::UserData::comparePriorities(const PriorityType& a, const PriorityType& b)
{
	return b - a;
}

UI::UserData::KeyType UI::UserData::defaultKeyValue()
{
	return rand() % 1000;
}

System::String ^ UI::UserData::convertKeyToStr(const KeyType& key)
{
	std::stringstream ss;
	ss << key;
	return gcnew System::String(ss.str().c_str());
}

int UI::UserData::compareKeys(const KeyType& a, const KeyType& b)
{
	return a - b;
}

UI::UserData::UserData()
{
}
