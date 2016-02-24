#include "panelVector.h"
#include "Routines.h"

using namespace DS;
using namespace UI;

PanelVector::PanelVector(void):
	vector_(nullptr),
	selectedItem_(nullptr),
	updater_(gcnew PanelStructureUpdater())
{
	InitializeComponent();

	this->checkboxes_ = (gcnew array<System::Windows::Forms::CheckBox^>(8));	
	this->checkboxes_[0] = this->chbBit0;
	this->checkboxes_[1] = this->chbBit1;
	this->checkboxes_[2] = this->chbBit2;
	this->checkboxes_[3] = this->chbBit3;
	this->checkboxes_[4] = this->chbBit4;
	this->checkboxes_[5] = this->chbBit5;
	this->checkboxes_[6] = this->chbBit6;
	this->checkboxes_[7] = this->chbBit7;
}

void PanelVector::initialize(Structure * structure)
{
	vector_ = dynamic_cast<Vector*>(structure);
	for (int i = 0; (size_t)i < vector_->size(); i++)
	{
		ListViewItem^ item = Routines::listViewAddItem(lviewVector,Routines::convertIntToStr((*vector_)[i]),false);
		refreshItem(item);
	}

	enableControls(lviewVector->SelectedItems->Count > 0);
}

void PanelVector::finalize()
{
	vector_ = nullptr;
	lviewVector->Items->Clear();
}

void PanelVector::enableControls(bool value)
{
	btnByteSet->Enabled = value;
	btnByteReset->Enabled = value;
	btnByteXOR->Enabled = value;
	btnByteSHL->Enabled = value;
	btnByteSHR->Enabled = value;
}

void PanelVector::show()
{
	UserControl::Visible = true;
}

void PanelVector::hide()
{
	UserControl::Visible = false;
}

PanelVector::~PanelVector()
{
	if (components)
	{
		delete components;
	}
	vector_ = nullptr;
}

void PanelVector::checkBoxesToItem(System::Windows::Forms::ListViewItem ^ item)
{
	updater_->beginUpdate();
	item->Text = Routines::convertIntToString((*vector_)[item->Index]);
	for (int bit = 0; bit < 8; bit++)
	{
		System::Windows::Forms::ListViewItem::ListViewSubItem^ subitem = item->SubItems[8 - bit];
		System::Drawing::Rectangle rect = subitem->Bounds;
		subitem->Text = "";

		Routines::layoutControlToCenter(checkboxes_[bit], rect, lviewVector->Left, lviewVector->Top);
		checkboxes_[bit]->Visible = true;
		checkboxes_[bit]->Checked = vector_->byteNthBitGet(item->Index, bit);
	}
	updater_->endUpdate();
}

void PanelVector::bitsToItem(System::Windows::Forms::ListViewItem ^ item)
{		
	updater_->beginUpdate();
	item->Text = Routines::convertStrToString(Routines::convertIntToStr((*vector_)[item->Index]));
	for (int bit = 0; bit < 8; bit++)
	{
		if (item->SubItems->Count < 9)
			item->SubItems->Add("");
		checkboxes_[bit]->Visible = false;
		item->SubItems[bit + 1]->Text = Routines::convertIntToString(vector_->byteNthBitGet(item->Index, 7 - bit));
	}
	updater_->endUpdate();
}

void PanelVector::refreshItem(System::Windows::Forms::ListViewItem ^ item)
{
	if (item == nullptr)
		return;

	updater_->beginUpdate();
	if (selectedItem_ == item)
		checkBoxesToItem(item);
	else
		bitsToItem(item);
	updater_->endUpdate();
}

void PanelVector::dockFill()
{
	UserControl::Dock = DockStyle::Fill;
}

System::Void PanelVector::btnByteSet_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	(*vector_)[selectedItem_->Index] = 255;
	refreshItem(selectedItem_);
}

System::Void PanelVector::btnByteReset_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	(*vector_)[selectedItem_->Index] = 0;
	refreshItem(selectedItem_);
}

System::Void PanelVector::btnByteXOR_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	(*vector_)[selectedItem_->Index] ^= 255;
	refreshItem(selectedItem_);
}

System::Void PanelVector::btnByteSHL_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	(*vector_)[selectedItem_->Index] <<= 1;
	refreshItem(selectedItem_);
}

System::Void PanelVector::btnByteSHR_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	(*vector_)[selectedItem_->Index] >>= 1;
	refreshItem(selectedItem_);
}

System::Void PanelVector::lviewVector_ColumnWidthChanged(System::Object ^ sender, System::Windows::Forms::ColumnWidthChangedEventArgs ^ e)
{
	refreshItem(selectedItem_);
}

System::Void PanelVector::lviewVector_ItemSelectionChanged(System::Object ^ sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs ^ e)
{
	if (e->IsSelected)
	{
		checkBoxesToItem(e->Item);
		selectedItem_ = e->Item;
	}
	else
	{
		bitsToItem(e->Item);
		selectedItem_ = nullptr;
	}

	enableControls(e->IsSelected);
}

System::Void PanelVector::chbBit0_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (updater_->canEditData())
		selectedItem_->Text = Routines::convertIntToString(vector_->byteNthBitToggle(selectedItem_->Index, 0));
}

System::Void PanelVector::chbBit1_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (updater_->canEditData())
		selectedItem_->Text = Routines::convertIntToString(vector_->byteNthBitToggle(selectedItem_->Index, 1));
}

System::Void PanelVector::chbBit2_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (updater_->canEditData())
		selectedItem_->Text = Routines::convertIntToString(vector_->byteNthBitToggle(selectedItem_->Index, 2));
}

System::Void PanelVector::chbBit3_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (updater_->canEditData())
		selectedItem_->Text = Routines::convertIntToString(vector_->byteNthBitToggle(selectedItem_->Index, 3));
}

System::Void PanelVector::chbBit4_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (updater_->canEditData())
		selectedItem_->Text = Routines::convertIntToString(vector_->byteNthBitToggle(selectedItem_->Index, 4));
}

System::Void PanelVector::chbBit5_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (updater_->canEditData())
		selectedItem_->Text = Routines::convertIntToString(vector_->byteNthBitToggle(selectedItem_->Index, 5));
}

System::Void PanelVector::chbBit6_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (updater_->canEditData())
		selectedItem_->Text = Routines::convertIntToString(vector_->byteNthBitToggle(selectedItem_->Index, 6));
}

System::Void PanelVector::chbBit7_CheckedChanged(System::Object ^ sender, System::EventArgs ^ e)
{
	if (updater_->canEditData())
		selectedItem_->Text = Routines::convertIntToString(vector_->byteNthBitToggle(selectedItem_->Index, 7));
}
