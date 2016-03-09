#pragma once

namespace UI
{

	class UserData
	{
	public:
		typedef int DataType;
		typedef int PriorityType;
		typedef int KeyType;

		static void finalize();
		static DataType defaultDataValue();
		static DataType randomDataValue();
		static System::String^ convertDataToStr(const DataType& data);
		static bool areEqual(const DataType& a, const DataType& b);

		static PriorityType defaultPriorityValue();
		static System::String^ convertPriorityToStr(const PriorityType& priority);
		static int comparePriorities(const PriorityType& a, const PriorityType& b);

		static KeyType defaultKeyValue();
		static System::String^ convertKeyToStr(const KeyType& key);
		static int compareKeys(const KeyType& a, const KeyType& b);

	private:
		UserData();
	};

}
