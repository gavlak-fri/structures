#include "panelGraph.h"

using namespace UI;

PanelGraph::PanelGraph(void) :
	/*
	graph_ = nullptr;
	*/

	updater_(gcnew PanelStructureUpdater())
{
	InitializeComponent();
}

void PanelGraph::initialize(DS::Structure * structure)
{
	/*
	graph_ = dynamic_cast<Graph*>(structure);

	Napln vizualne prvky strukturou

	enableControls(?);
	*/
}

void PanelGraph::finalize()
{
	/*
	graph_ = nullptr;
	vycisti vizualne prvky
	*/
}

void PanelGraph::enableControls(bool value)
{
	/*
	vsetky btn*->Enabled = value;
	*/
}

void PanelGraph::show()
{
	UserControl::Visible = true;
}

void PanelGraph::hide()
{
	UserControl::Visible = false;
}

void PanelGraph::dockFill()
{
	UserControl::Dock = DockStyle::Fill;
}

PanelGraph::~PanelGraph()
{
	if (components)
	{
		delete components;
	}

	/*
	graph_ = nullptr;
	*/
}
