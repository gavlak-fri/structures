#include "panelArray.h"
#include "formData.h"
#include "Routines.h"

using namespace UI;
using namespace DS;

PanelArray::PanelArray(void) :
	array_(nullptr),
	updater_(gcnew PanelStructureUpdater())
{
	InitializeComponent();
	lviewManager_ = gcnew ListViewManager(lviewArray);
}

PanelArray::~PanelArray()
{
	if (components)
	{
		delete components;
	}
	array_ = nullptr;
}

void PanelArray::initialize(Structure * structure)
{
	array_ = dynamic_cast<DS::Array<UI::UserData::DataType>*>(structure);
	for (int i = 0; i < array_->size(); i++)
	{
		ListViewItem^ item = lviewManager_->addItem(Routines::convertIntToStr(i), false, nullptr);
		refreshItem(item);
	}

	enableControls(lviewArray->SelectedItems->Count > 0);
}

void PanelArray::finalize()
{
	array_ = nullptr;
	lviewArray->Items->Clear();
}

void PanelArray::enableControls(bool value)
{
	btnEdit->Enabled = value;
}

void PanelArray::show()
{
	UserControl::Visible = true;
}

void PanelArray::hide()
{
	UserControl::Visible = false;
}

void PanelArray::dockFill()
{
	UserControl::Dock = DockStyle::Fill;
}

void PanelArray::refreshItem(System::Windows::Forms::ListViewItem ^ item)
{
	if (item == nullptr)
		return;

	updater_->beginUpdate();
	if (item->SubItems->Count < 2)
		item->SubItems->Add("");
	item->SubItems[1]->Text = UserData::convertDataToStr((*array_)[item->Index]);
	if (item->SubItems->Count < 3)
		item->SubItems->Add("");
	item->SubItems[2]->Text = Routines::convertMemoryToString(&(*array_)[item->Index], sizeof(UserData::DataType));
	updater_->endUpdate();
}

void PanelArray::editItem(System::Windows::Forms::ListViewItem ^ item)
{
	UserData::DataType data = (*array_)[item->Index];
	if (FormData::tryGetData(data))
	{
		(*array_)[item->Index] = data;
	}
	refreshItem(item);
}

System::Void PanelArray::lviewArray_DoubleClick(System::Object ^ sender, System::EventArgs ^ e) 
{
	ListViewItem^ item = lviewManager_->SelectedItem;
	if (item != nullptr)
	{
		editItem(item);
	}
}

System::Void PanelArray::btnEdit_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	ListViewItem^ item = lviewManager_->SelectedItem;
	if (item != nullptr)
	{
		editItem(item);
	}
}

System::Void PanelArray::lviewArray_ItemSelectionChanged(System::Object ^ sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs ^ e)
{
	enableControls(e->IsSelected);
}
