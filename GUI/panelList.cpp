#include "panelList.h"
#include "formData.h"
#include "Routines.h"

using namespace UI;

PanelList::PanelList(void) :
	list_(nullptr),
	updater_(gcnew PanelStructureUpdater())
{
	InitializeComponent();
	lviewManager_ = gcnew ListViewManager(lviewList);
}

PanelList::~PanelList()
{
	if (components)
	{
		delete components;
	}
}

System::Void PanelList::btnAdd_Click(System::Object ^ sender, System::EventArgs ^ e) {
	UserData::DataType data = UserData::randomDataValue();
	if (FormData::tryGetData(data))
	{
		list_->add(data);
		ListViewItem^ item = lviewManager_->addData(&(*list_)[static_cast<int>(list_->size()) - 1], true);
		lviewList->Focus();
		refreshItem(item);
	}
}

inline System::Void PanelList::btnInsert_Click(System::Object ^ sender, System::EventArgs ^ e) {
	UserData::DataType data = UserData::randomDataValue();
	if (FormData::tryGetData(data))
	{
		list_->insert(data, lviewManager_->SelectedItem->Index);
		ListViewItem^ item = lviewManager_->insertData(lviewManager_->SelectedItem->Index, &(*list_)[lviewManager_->SelectedItem->Index], true);
		lviewList->Focus();
		refreshItem(item);
	}
}

System::Void UI::PanelList::btnEdit_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	ListViewItem^ item = lviewManager_->SelectedItem;
	if (item != nullptr)
	{
		editItem(item);
	}
}

System::Void PanelList::lviewList_DoubleClick(System::Object ^ sender, System::EventArgs ^ e) {
	ListViewItem^ item = lviewManager_->SelectedItem;
	if (item != nullptr)
	{
		editItem(item);
	}
}

System::Void PanelList::btnGetIndexOf_Click(System::Object ^ sender, System::EventArgs ^ e) {
	UserData::DataType data = UserData::defaultDataValue();
	if (FormData::tryGetData(data))
	{
		int index = list_->getIndexOf(data);
		if (index >= 0)
		{
			lviewManager_->deselect();
			lviewManager_->selectItemAtIndex(index);
			lviewList->Focus();
		}
		else
		{
			MessageBox::Show("Data " + UserData::convertDataToStr(data) + " does not exist in the list.");
		}
	}
}

System::Void PanelList::btnRemove_Click(System::Object ^ sender, System::EventArgs ^ e) {
	UserData::DataType data = UserData::defaultDataValue();
	
	if (FormData::tryGetData(data))
	{
		int index = list_->getIndexOf(data);
		if (index >= 0)
		{		
			list_->tryRemove(data);
			lviewManager_->deselect();
			lviewManager_->removeItemAtIndex(index);
			lviewList->Focus();
		}
		else
		{
			MessageBox::Show("Data " + UserData::convertDataToStr(data) + " does not exist in the list.");
		}
	}
}

System::Void PanelList::btnRemoveAt_Click(System::Object ^ sender, System::EventArgs ^ e) {
	int index = lviewManager_->SelectedItem->Index;
	list_->removeAt(index);
	lviewManager_->deselect();
	lviewManager_->removeItemAtIndex(index);
	lviewList->Focus();
}

System::Void PanelList::lviewList_SelectedIndexChanged(System::Object ^ sender, System::EventArgs ^ e) {
	setButtons();
}

void PanelList::initialize(DS::Structure * structure)
{
	list_ = dynamic_cast<DS::List<UserData::DataType>*>(structure);
	
	for (auto data : *list_)
	{
		ListViewItem^ item = lviewManager_->addData(&data, false);
		refreshItem(item);
	}
	
	setButtons();
}

void PanelList::finalize()
{
	list_ = nullptr;
	lviewList->Items->Clear();
}

void PanelList::enableControls(bool value)
{
	setButtons();
}

void PanelList::show()
{
	UserControl::Visible = true;
}

void PanelList::hide()
{
	UserControl::Visible = false;
}

void PanelList::dockFill()
{
	UserControl::Dock = DockStyle::Fill;
}

void PanelList::refreshItem(System::Windows::Forms::ListViewItem ^ item)
{
	if (item == nullptr)
		return;

	updater_->beginUpdate();
	if (item->SubItems->Count < 2)
		item->SubItems->Add("");
	item->SubItems[0]->Text = Routines::convertIntToString(item->Index);
	item->SubItems[1]->Text = UserData::convertDataToStr((*list_)[item->Index]);
	updater_->endUpdate();
}

void UI::PanelList::editItem(System::Windows::Forms::ListViewItem ^ item)
{
	UserData::DataType data = (*list_)[item->Index];
	if (FormData::tryGetData(data))
	{
		(*list_)[item->Index] = data;
	}
	refreshItem(item);	
}

void PanelList::setButtons()
{
	btnAdd->Enabled = true;
	btnGetIndexOf->Enabled = true;
	btnRemove->Enabled = true;

	if (lviewList->SelectedItems->Count > 0)
	{
		btnInsert->Enabled = true;
		btnEdit->Enabled = true;
		btnRemoveAt->Enabled = true;
	}
	else
	{
		btnInsert->Enabled = false;
		btnEdit->Enabled = false;
		btnRemoveAt->Enabled = false;
	}
}
