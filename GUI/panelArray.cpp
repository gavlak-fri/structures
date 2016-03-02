#include "panelArray.h"
#include "formData.h"
#include "Routines.h"

UI::PanelArray::PanelArray(void) :
	array_(nullptr),
	updater_(gcnew PanelStructureUpdater())
{
	InitializeComponent();
}

UI::PanelArray::~PanelArray()
{
	if (components)
	{
		delete components;
	}
	array_ = nullptr;
}

void UI::PanelArray::initialize(DS::Structure * structure)
{
	array_ = dynamic_cast<DS::Array<UI::UserData::DataType>*>(structure);
	for (int i = 0; (size_t)i < array_->size(); i++)
	{
		ListViewItem^ item = UI::Routines::listViewAddItem(lviewArray, UI::Routines::convertIntToStr(i), false);
		refreshItem(item);
	}

	enableControls(lviewArray->SelectedItems->Count > 0);
}

void UI::PanelArray::finalize()
{
	array_ = nullptr;
	lviewArray->Items->Clear();
}

void UI::PanelArray::enableControls(bool value)
{
	btnEdit->Enabled = value;
}

void UI::PanelArray::show()
{
	UserControl::Visible = true;
}

void UI::PanelArray::hide()
{
	UserControl::Visible = false;
}

void UI::PanelArray::dockFill()
{
	UserControl::Dock = DockStyle::Fill;
}

void UI::PanelArray::refreshItem(System::Windows::Forms::ListViewItem ^ item)
{
	if (item == nullptr)
		return;

	updater_->beginUpdate();
	if (item->SubItems->Count < 2)
		item->SubItems->Add("");
	item->SubItems[1]->Text = UserData::convertDataToStr((*array_)[item->Index]);
	if (item->SubItems->Count < 3)
		item->SubItems->Add("");
	item->SubItems[2]->Text = Routines::convertMemoryToString(&(*array_)[item->Index], sizeof(UI::UserData::DataType));
	updater_->endUpdate();
}

void UI::PanelArray::editItem(System::Windows::Forms::ListViewItem ^ item)
{
	UI::UserData::DataType data = (*array_)[item->Index];
	if (UI::FormData::tryGetData(data))
	{
		(*array_)[item->Index] = data;
	}
	refreshItem(item);
}

System::Void UI::PanelArray::lviewArray_DoubleClick(System::Object ^ sender, System::EventArgs ^ e) 
{
	if (lviewArray->SelectedItems->Count > 0)
	{
		ListViewItem^ selectedItem = lviewArray->SelectedItems[0];
		editItem(selectedItem);
	}
}

System::Void UI::PanelArray::btnEdit_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (lviewArray->SelectedItems->Count > 0)
	{
		ListViewItem^ selectedItem = lviewArray->SelectedItems[0];
		editItem(selectedItem);
	}
}

System::Void UI::PanelArray::lviewArray_ItemSelectionChanged(System::Object ^ sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs ^ e)
{
	enableControls(e->IsSelected);
}
