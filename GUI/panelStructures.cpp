#include "panelStructures.h"
#include "panelVector.h"
#include "panelArray.h"
#include "panelList.h"
#include "panelQueue.h"
#include "panelStack.h"
#include "panelPriorityQueue.h"
#include "panelGraph.h"
#include "panelTree.h"
#include "panelTable.h"
#include "panelSort.h"
#include "Routines.h"

using namespace std;
using namespace DS;
using namespace UI;

PanelStructures::PanelStructures(void) :
	pnlCustomStructure_(nullptr),
	initialized_(false)
{
	InitializeComponent();
	lviewManager_ = gcnew ListViewManager(lviewStructures);
}

void PanelStructures::initialize(const StructureADT adt)
{
	if (initialized_)
		return;

	adt_ = StructuresFactory::getFactory()->getADTContainer(adt);

	pnlCustomStructure_ = PanelStructures::createPanelFromStructureID(adt);
	if (pnlCustomStructure_ != nullptr)
	{
		pnlStructure->Controls->Add(dynamic_cast<UserControl^>(pnlCustomStructure_));
		pnlCustomStructure_->dockFill();
		pnlCustomStructure_->hide();
	}

	for (int i = 0; i < adt_->ADSContainerSize(); i++)
	{
		cbxADS->Items->Add(Routines::convertStrToString(Routines::convertStructureADSToStr(adt_->getADSContainerByIndex(i)->getADSType())));
	}

	if (cbxADS->Items->Count == 0)
	{
		btnNew->Enabled = false;
		pnlStructures->BackColor = System::Drawing::Color::Firebrick;
	}
	else
		cbxADS->SelectedIndex = 0;
	
	initialized_ = true;
}

PanelStructures::~PanelStructures()
{
	if (components)
	{
		delete components;
	}
}

PanelStructure ^ PanelStructures::createPanelFromStructureID(const StructureADT adt)
{
	switch (adt)
	{
	case adtVECTOR:
		return gcnew PanelVector();
	case adtARRAY:
		return gcnew PanelArray();
	case adtLIST:
		return gcnew PanelList();
	case adtQUEUE:
		return gcnew PanelQueue();
	case adtSTACK:
		return gcnew PanelStack();
	case adtPRIORITY_QUEUE:
		return gcnew PanelPriorityQueue();
	case adtGRAPH:
		return gcnew PanelGraph();
	case adtTREE:
		return gcnew PanelTree();
	case adtTABLE:
		return gcnew PanelTable();
	default:
		return nullptr;
	}
}

void PanelStructures::updateControls()
{
	bool selected = lviewStructures->SelectedItems->Count > 0;
	
	btnDelete->Enabled = selected;
	btnClone->Enabled = selected;

	if (selected)
		pnlCustomStructure_->show();
	else
		pnlCustomStructure_->hide();
}

System::Void PanelStructures::btnNew_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Structure* structure = StructuresFactory::getFactory()->createStructure(adt_->getADSContainerByIndex(cbxADS->SelectedIndex)->getADSType());

	System::Windows::Forms::ListViewItem^ item = lviewManager_->addItem(
		Routines::convertStructureADSToStr(adt_->getADSContainerByIndex(cbxADS->SelectedIndex)->getADSType()) +
			Routines::convertIntToStr(adt_->getADSContainerByIndex(cbxADS->SelectedIndex)->totalCreated()),
		true,
		nullptr);

	updateControls();
}

System::Void PanelStructures::btnDelete_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	ListView::SelectedListViewItemCollection^ selected = lviewStructures->SelectedItems;
	while (selected->Count > 0) 
	{
		System::Windows::Forms::ListViewItem^ item = selected[selected->Count - 1];
		StructuresFactory::getFactory()->removeStructure(adt_->getADTType(), item->Index);
		lviewStructures->Items->Remove(item);
	}

	pnlCustomStructure_->finalize();
	updateControls();
}

System::Void PanelStructures::btnClone_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Structure* selected = SelectedStructure;
	Structure* structure = StructuresFactory::getFactory()->createStructure(adt_->getADSContainerByIndex(cbxADS->SelectedIndex)->getADSType());
	(*structure) = (*selected);

	System::Windows::Forms::ListViewItem^ item = lviewManager_->addItem(
		Routines::convertStructureADSToStr(adt_->getADSContainerByIndex(cbxADS->SelectedIndex)->getADSType()) +
			Routines::convertIntToStr(adt_->getADSContainerByIndex(cbxADS->SelectedIndex)->totalCreated()),
		true,
		nullptr);

	updateControls();
}

System::Void PanelStructures::lviewStructures_ItemSelectionChanged(System::Object ^ sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs ^ e)
{
	pnlCustomStructure_->finalize();

	if (SelectedStructure != nullptr)
	{
		pnlCustomStructure_->show();
		pnlCustomStructure_->initialize(SelectedStructure);
	}
	else
	{
		pnlCustomStructure_->hide();
	}


	updateControls();
}
