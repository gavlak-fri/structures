#include "panelTable.h"

UI::PanelTable::PanelTable(void) :
	/*
	table_ = nullptr;
	*/

	updater_(gcnew PanelStructureUpdater())
{
	InitializeComponent();
}

void UI::PanelTable::initialize(DS::Structure * structure)
{
	/*
	table_ = dynamic_cast<Table*>(structure);

	Napln vizualne prvky strukturou

	enableControls(?);
	*/
}

void UI::PanelTable::finalize()
{
	/*
	table_ = nullptr;
	vycisti vizualne prvky
	*/
}

void UI::PanelTable::enableControls(bool value)
{
	/*
	vsetky btn*->Enabled = value;
	*/
}

void UI::PanelTable::show()
{
	UserControl::Visible = true;
}

void UI::PanelTable::hide()
{
	UserControl::Visible = false;
}

void UI::PanelTable::dockFill()
{
	UserControl::Dock = DockStyle::Fill;
}

UI::PanelTable::~PanelTable()
{
	if (components)
	{
		delete components;
	}

	/*
	table_ = nullptr;
	*/
}
