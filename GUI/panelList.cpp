#include "panelList.h"

using namespace UI;

PanelList::PanelList(void) :
	/*
	list_ = nullptr;
	*/

	updater_(gcnew PanelStructureUpdater())
{
	InitializeComponent();
}

PanelList::~PanelList()
{
	if (components)
	{
		delete components;
	}

	/*
	list_ = nullptr;
	*/
}

void PanelList::initialize(DS::Structure * structure)
{
	/*
	list_ = dynamic_cast<List*>(structure);

	Napln vizualne prvky strukturou

	enableControls(?);
	*/
}

void PanelList::finalize()
{
	/*
	list_ = nullptr;
	vycisti vizualne prvky
	*/
}

void PanelList::enableControls(bool value)
{
	/*
	vsetky btn*->Enabled = value;
	*/
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
