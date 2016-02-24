#include "panelQueue.h"

using namespace UI;

PanelQueue::PanelQueue(void):
	/*
	queue_ = nullptr;
	*/

	updater_(gcnew PanelStructureUpdater())
{
	InitializeComponent();
}


void PanelQueue::initialize(DS::Structure * structure)
{
	/*
	queue_ = dynamic_cast<Queue*>(structure);

	Napln vizualne prvky strukturou

	enableControls(?);
	*/
}

void PanelQueue::finalize()
{
	/*
	queue_ = nullptr;
	vycisti vizualne prvky
	*/
}

void PanelQueue::enableControls(bool value)
{
	/*
	vsetky btn*->Enabled = value;
	*/
}

void PanelQueue::show()
{
	UserControl::Visible = true;
}

void PanelQueue::hide()
{
	UserControl::Visible = false;
}

void PanelQueue::dockFill()
{
	UserControl::Dock = DockStyle::Fill;
}

PanelQueue::~PanelQueue()
{
	if (components)
	{
		delete components;
	}

	/*
	queue_ = nullptr;
	*/
}
