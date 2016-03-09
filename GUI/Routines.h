#pragma once

#include "../Structures/StructureID.h"
#include "../Structures/Structure.h"
#include "../Structures/Iterator.h"
#include "UserData.h"
#include "../GUI/Logger.h"

namespace UI {

	ref class Routines
	{
	public:
		static void layoutControlToCenter(System::Windows::Forms::Control^ control,
			System::Drawing::Rectangle^ rect,
			int offsetLeft,
			int offsetTop);
		static void layoutControlFillRect(System::Windows::Forms::Control^ control,
			System::Drawing::Rectangle^ rect,
			int offsetLeft,
			int offsetTop);

		static std::string convertStructureADTToStr(const DS::StructureADT adt);
		static std::string convertStructureADSToStr(const DS::StructureADS ads);
		static std::string convertLogTypeToStr(const DS::LogType lt);
		static std::string convertIntToStr(int i);
		static System::String^ convertMemoryToString(const void* ptr, const int bytes);
		static System::String^ convertIntToString(int i);
		static System::String^ convertStrToString(std::string s);		

	private:
		Routines();
	};

}