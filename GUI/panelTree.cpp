#include "panelTree.h"

using namespace UI;

PanelTree::PanelTree(void):
	/*
	tree_ = nullptr;
	*/

	updater_(gcnew PanelStructureUpdater())
{
	InitializeComponent();
}

void PanelTree::initialize(DS::Structure * structure)
{
	/*
	tree_ = dynamic_cast<Tree*>(structure);

	Napln vizualne prvky strukturou

	enableControls(?);
	*/
}

void PanelTree::finalize()
{
	/*
	tree_ = nullptr;
	vycisti vizualne prvky
	*/
}

void PanelTree::enableControls(bool value)
{
	/*
	vsetky btn*->Enabled = value;
	*/
}

void PanelTree::show()
{
	UserControl::Visible = true;
}

void PanelTree::hide()
{
	UserControl::Visible = false;
}

void PanelTree::dockFill()
{
	UserControl::Dock = DockStyle::Fill;
}

PanelTree::~PanelTree()
{
	if (components)
	{
		delete components;
	}

	/*
	tree_ = nullptr;
	*/
}