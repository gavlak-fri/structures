#include "panelStack.h"

using namespace UI;

PanelStack::PanelStack(void) :
	/*
	stack_ = nullptr;
	*/

	updater_(gcnew PanelStructureUpdater())
{
	InitializeComponent();
}

void PanelStack::initialize(DS::Structure * structure)
{
	/*
	stack_ = dynamic_cast<Graph*>(structure);

	Napln vizualne prvky strukturou

	enableControls(?);
	*/
}

void PanelStack::finalize()
{
	/*
	stack_ = nullptr;
	vycisti vizualne prvky
	*/
}

void PanelStack::enableControls(bool value)
{
	/*
	vsetky btn*->Enabled = value;
	*/
}

void PanelStack::show()
{
	UserControl::Visible = true;
}

void PanelStack::hide()
{
	UserControl::Visible = false;
}

void PanelStack::dockFill()
{
	UserControl::Dock = DockStyle::Fill;
}

PanelStack::~PanelStack()
{
	if (components)
	{
		delete components;
	}
	
	/*
	stack_ = nullptr;
	*/
}