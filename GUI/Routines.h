#pragma once

#include "../Structures/StructureID.h"
#include "../Structures/Structure.h"
#include "../Structures/Iterator.h"
#include "UserData.h"
#include "../GUI/Logger.h"

namespace UI {

	typedef void(*eventListViewItem)(System::Windows::Forms::ListViewItem ^&);

	ref class Routines
	{
	public:
		static void listViewItemSelect(System::Windows::Forms::ListViewItem^ &item);
		static void listViewItemDeselect(System::Windows::Forms::ListViewItem^ &item);
		static void listViewItemRemove(System::Windows::Forms::ListViewItem^ &item);

		static System::Windows::Forms::ListViewItem^ listViewAddItem(System::Windows::Forms::ListView^ lview,
			System::String^ text,
			bool selectAdded);
		static System::Windows::Forms::ListViewItem^ listViewAddItem(System::Windows::Forms::ListView^ lview,
			std::string text,
			bool selectAdded);
		static System::Windows::Forms::ListViewItem^ listViewInsertItem(System::Windows::Forms::ListView^ lview,
			int index,
			std::string text,
			bool selectAdded);
		static void listViewRemoveSelected(System::Windows::Forms::ListView^ lview);
		static void listViewDeselect(System::Windows::Forms::ListView^  lview);

		static void listViewProcessItems(System::Windows::Forms::ListView^  lview, eventListViewItem event);
		static void listViewProcessSelection(System::Windows::Forms::ListView^  lview, eventListViewItem event);

		static void listViewFill(System::Windows::Forms::ListView^ lview, DS::Iterable<UserData::DataType>* structure);

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