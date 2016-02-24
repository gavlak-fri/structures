#pragma once

#include "PanelStructure.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace UI {

	public ref class PanelGraph : 
		public System::Windows::Forms::UserControl,
		public PanelStructure
	{
	private:
		// DS::Graph graph_;
	public:
		PanelGraph(void);

		virtual void initialize(DS::Structure* structure);
		virtual void finalize();
		virtual void enableControls(bool value);

		virtual void show();
		virtual void hide();
		virtual void dockFill();

	protected:
		~PanelGraph();

	private:
		PanelStructureUpdater^ updater_;

	private: System::Windows::Forms::FlowLayoutPanel^  pnlGraph;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnlGraph = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// pnlGraph
			// 
			this->pnlGraph->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->pnlGraph->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlGraph->Location = System::Drawing::Point(0, 0);
			this->pnlGraph->Name = L"pnlGraph";
			this->pnlGraph->Size = System::Drawing::Size(150, 30);
			this->pnlGraph->TabIndex = 0;
			// 
			// PanelGraph
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->pnlGraph);
			this->Name = L"PanelGraph";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
