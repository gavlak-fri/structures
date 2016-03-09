#include "formMain.h"

#include "GUI/Routines.h"
#include "Structures/StructuresFactory.h"
#include "Structures/Vector.h"
#include "Structures/Array.h"
#include "GUI/UserData.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace DS;
using namespace UI;

void registerStructures(StructuresFactory* factory)
{
	factory->registerPrototype(StructureADS::adsVECTOR, new Vector(10));
	factory->registerPrototype(StructureADS::adsARRAY, new DS::Array<UserData::DataType>(200));
}

[STAThread]
void Main(array<String^>^ args)
{
	registerStructures(StructuresFactory::getFactory());

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	FormMain form;

	Application::Run(%form);
}

FormMain::FormMain(void):
	panels_(gcnew array<PanelStructures^>(StructureADT::adtCount)),
	lviewManager(gcnew ListViewManager(lviewLog))
{
	InitializeComponent();

	Logger::initialize(this);

	for (int i = 0; i < StructureADT::adtCount; i++) 
		initializePanel(static_cast<StructureADT>(i));
}

void FormMain::Log(LogType lt, System::String ^ message)
{
	System::Windows::Forms::ListViewItem ^ item = lviewManager->addItem(Routines::convertLogTypeToStr(lt), false, nullptr);
	item->SubItems->Add(message);
}

FormMain::~FormMain()
{
	if (components)
	{
		delete components;
	}

	//StructuresFactory::finalize();
	UI::UserData::finalize();
}

void FormMain::initializePanel(const StructureADT adt)
{
	panels_[adt] = gcnew PanelStructures();
	System::Windows::Forms::TabPage ^ tab = getTabFromStructureADT(static_cast<StructureADT>(adt));
	if (tab != nullptr)
	{
		tab->Controls->Add(panels_[adt]);
		panels_[adt]->Dock = System::Windows::Forms::DockStyle::Fill;
		panels_[adt]->initialize(static_cast<StructureADT>(adt));
	}
}

System::Windows::Forms::TabPage ^ FormMain::getTabFromStructureADT(const StructureADT adt)
{
	switch (adt)
	{
	case adtVECTOR:
		return tabVector;
	case adtARRAY:
		return tabArray;
	case adtLIST:
		return tabList;
	case adtQUEUE:
		return tabQueue;
	case adtSTACK:
		return tabStack;
	case adtPRIORITY_QUEUE:
		return tabPriorityQueue;
	case adtGRAPH:
		return tabGraph;
	case adtTREE:
		return tabTree;
	case adtTABLE:
		return tabTable;
	default:
		return nullptr;
	}
}
