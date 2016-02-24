#include "panelArray.h"

UI::PanelArray::PanelArray(void) :
	/*
	array_(nullptr),
	*/

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

	/*
	array_ = nullptr;
	*/
}

void UI::PanelArray::initialize(DS::Structure * structure)
{
	/*
	array_ = dynamic_cast<Array*>(structure);

	Napln vizualne prvky strukturou

	enableControls(?);
	*/
}

void UI::PanelArray::finalize()
{
	/*
	array_ = nullptr;
	vycisti vizualne prvky
	*/
}

void UI::PanelArray::enableControls(bool value)
{
	/*
	vsetky btn*->Enabled = value;
	*/
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