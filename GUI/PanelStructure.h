#pragma once

#include "../Structures/Structure.h"
#include "../Structures/Iterator.h"
#include "UserData.h"
#include <map>

namespace UI {

	interface class PanelStructure
	{
		void initialize(DS::Structure* structure);
		void finalize();
		void enableControls(bool value);

		void show();
		void hide();
		void dockFill();
	};

	ref class PanelStructureUpdater {
	private:
		int counter_;
	public:
		PanelStructureUpdater():counter_(0){};

		void beginUpdate() { counter_++; };
		void endUpdate() { counter_--; };
		bool canEditData() { return counter_ == 0; };
	};

	ref class ListViewManager {
	private:
		System::Windows::Forms::ListView^  lview_;
		std::map<System::Windows::Forms::ListViewItem^*, UserData::DataType*>* itemDataMap_;
		std::map<UserData::DataType*, System::Windows::Forms::ListViewItem^*>* dataItemMap_;
	public:
		typedef System::Void(*eventListViewItem)(System::Windows::Forms::ListViewItem ^&);

		ListViewManager(System::Windows::Forms::ListView^  lview);
		~ListViewManager();

		System::Windows::Forms::ListViewItem^ addData(
			const UserData::DataType* data,
			bool selectAdded);
		System::Void addStructure(
			DS::Iterable<UserData::DataType>* structure,
			bool selectLast);
		System::Windows::Forms::ListViewItem^ addItem(
			System::String^ text,
			bool selectAdded,
			const UserData::DataType* data);
		System::Windows::Forms::ListViewItem^ addItem(
			std::string text,
			bool selectAdded,
			const UserData::DataType* data);
		System::Windows::Forms::ListViewItem^ insertData(
			int index,
			const UserData::DataType* data,
			bool selectAdded);
		System::Windows::Forms::ListViewItem^ insertItem(
			int index,
			System::String^ text,
			bool selectAdded,
			const UserData::DataType* data);
		
		System::Void removeData(const UserData::DataType* data);
		System::Void removeSelected();
		
		System::Windows::Forms::ListViewItem^ findItem(const UserData::DataType* data);
		UserData::DataType& findData(System::Windows::Forms::ListViewItem^ item);

		System::Void setData(
			const UserData::DataType* data,
			System::Windows::Forms::ListViewItem^ item);

		static System::Void removeItem(System::Windows::Forms::ListViewItem^ &item);
		static System::Void selectItem(System::Windows::Forms::ListViewItem^ &item);
		static System::Void deselectItem(System::Windows::Forms::ListViewItem^ &item);

		System::Void selectData(const UserData::DataType* data);
		System::Void deselectData(const UserData::DataType* data);
		System::Void selectItemAtIndex(int index);
		System::Void removeItemAtIndex(int index);
		System::Void deselect();

		System::Void processItems(eventListViewItem event);
		System::Void processSelection(eventListViewItem event);

		property System::Windows::Forms::ListViewItem^ SelectedItem {
			public: System::Windows::Forms::ListViewItem^ get() 
			{ 
				return lview_->SelectedItems->Count > 0 ? lview_->SelectedItems[0] : nullptr;
			}
		}
	};

}

