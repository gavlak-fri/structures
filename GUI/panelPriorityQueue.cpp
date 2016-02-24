#include "panelPriorityQueue.h"

using namespace UI;

PanelPriorityQueue::PanelPriorityQueue(void):
	/*
	priorityQueue_ = nullptr;
	*/

	updater_(gcnew PanelStructureUpdater())
{
	InitializeComponent();
}

void PanelPriorityQueue::initialize(DS::Structure * structure)
{
	/*
	priorityQueue_ = dynamic_cast<PriorityQueue*>(structure);

	Napln vizualne prvky strukturou

	enableControls(?);
	*/
}

void PanelPriorityQueue::finalize()
{
	/*
	priorityQueue_ = nullptr;
	vycisti vizualne prvky
	*/
}

void PanelPriorityQueue::enableControls(bool value)
{
	/*
	vsetky btn*->Enabled = value;
	*/
}

void UI::PanelPriorityQueue::show()
{
	UserControl::Visible = true;
}

void UI::PanelPriorityQueue::hide()
{
	UserControl::Visible = false;
}

void UI::PanelPriorityQueue::dockFill()
{
	UserControl::Dock = DockStyle::Fill;
}

UI::PanelPriorityQueue::~PanelPriorityQueue()
{
	if (components)
	{
		delete components;
	}

	/*
	priorityQueue_ = nullptr;
	*/
}