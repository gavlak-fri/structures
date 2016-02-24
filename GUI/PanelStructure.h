#pragma once

#include "../Structures/Structure.h"

namespace UI {

	interface class PanelStructure
	{
		void initialize(DS::Structure* structure);
		void finalize();
		void enableControls(bool value);

		void show();
		void hide();
		void dockFill();
	};

	ref class PanelStructureUpdater {
	private:
		int counter_;
	public:
		PanelStructureUpdater():counter_(0){};

		void beginUpdate() { counter_++; };
		void endUpdate() { counter_--; };
		bool canEditData() { return counter_ == 0; };
	};

}

