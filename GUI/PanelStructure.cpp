#include "PanelStructure.h"
#include "Routines.h"
#include "UserData.h"

using namespace System::Windows::Forms;
using namespace UI;
using namespace std;

ListViewManager::ListViewManager(System::Windows::Forms::ListView ^ lview):
	lview_(lview),
	itemDataMap_(new map<ListViewItem^*, UserData::DataType*>()),
	dataItemMap_(new map<UserData::DataType*, ListViewItem^*>())
{
}

ListViewManager::~ListViewManager()
{
	delete itemDataMap_;
	delete dataItemMap_;
}

ListViewItem ^ ListViewManager::addData(const UserData::DataType* data, bool selectAdded)
{
	return addItem(UserData::convertDataToStr(*data), selectAdded, data);
}

System::Void UI::ListViewManager::addStructure(DS::Iterable<UserData::DataType> * structure, bool selectLast)
{	
	if (structure != nullptr)
	{
		lview_->Items->Clear();
		for (UserData::DataType data : *structure)
			ListViewItem^ item = addData(&data, true);
	}
}

ListViewItem ^ ListViewManager::addItem(System::String^ text, bool selectAdded, const UserData::DataType * data)
{
	deselect();
	ListViewItem^ item = (gcnew ListViewItem(text));
	lview_->Items->Add(item);
	if (selectAdded)
		selectItem(item);
	return item;
}

ListViewItem ^ ListViewManager::addItem(std::string text, bool selectAdded, const UserData::DataType * data)
{
	return addItem(Routines::convertStrToString(text), selectAdded, data);
}

System::Windows::Forms::ListViewItem ^ ListViewManager::insertData(int index, const UserData::DataType * data, bool selectAdded)
{
	return insertItem(index, UserData::convertDataToStr(*data), selectAdded, data);
}

System::Windows::Forms::ListViewItem ^ ListViewManager::insertItem(int index, System::String^ text, bool selectAdded, const UserData::DataType * data)
{
	deselect();
	ListViewItem^ item = (gcnew ListViewItem(text));
	lview_->Items->Insert(index, item);
	if (selectAdded)
		selectItem(item);
	return item;
}

System::Void ListViewManager::removeData(const UserData::DataType* data)
{
	throw 0;
	///////////////////////////////////////////////////////
}

System::Void ListViewManager::removeItem(ListViewItem^ &item)
{
	item->ListView->Items->Remove(item);
	item = nullptr;
}

System::Void ListViewManager::removeSelected()
{
	processSelection(removeItem);
}

ListViewItem ^ ListViewManager::findItem(const UserData::DataType* data)
{
	throw 0;
	///////////////////////////////////////////////////////
}

UserData::DataType & ListViewManager::findData(ListViewItem^ item)
{
	throw 0;
	///////////////////////////////////////////////////////
}

System::Void UI::ListViewManager::setData(const UserData::DataType * data, System::Windows::Forms::ListViewItem ^ item)
{
	throw 0;
	///////////////////////////////////////////////////////
}

System::Void ListViewManager::selectItem(ListViewItem^ &item)
{
	item->Selected = true;
}

System::Void ListViewManager::selectData(const UserData::DataType* data)
{
	ListViewItem^ item = findItem(data);
	selectItem(item);
}

System::Void UI::ListViewManager::deselectItem(ListViewItem^ &item)
{
	item->Selected = false;
}

System::Void UI::ListViewManager::deselectData(const UserData::DataType* data)
{
	ListViewItem^ item = findItem(data);
	deselectItem(item);
}

System::Void UI::ListViewManager::selectItemAtIndex(int index)
{
	ListViewItem^ item = lview_->Items[index];
	if (item != nullptr)
		selectItem(item);
}

System::Void UI::ListViewManager::removeItemAtIndex(int index)
{
	ListViewItem^ item = lview_->Items[index];
	if (item != nullptr)
		removeItem(item);
}

System::Void ListViewManager::deselect()
{
	processSelection(deselectItem);
}

System::Void ListViewManager::processItems(eventListViewItem event)
{
	int i = 0;

	while (i < lview_->Items->Count)
	{
		ListViewItem^ item = lview_->Items[i];
		event(item);
		// item mohla byt vymazana
		if (item != nullptr)
			i++;
	}
}

System::Void ListViewManager::processSelection(eventListViewItem event)
{
	int i = 0;
	int count = lview_->Items->Count;
	while (i < count)
	{
		ListViewItem^ item = lview_->Items[i];
		event(item);
		// item mohla byt vymazana alebo deselectnuta
		if (item != nullptr && count == lview_->Items->Count)
			i++;
		else
			count = lview_->Items->Count;
	}
}
