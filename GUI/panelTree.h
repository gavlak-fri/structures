#pragma once

#include "PanelStructure.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace UI {

	public ref class PanelTree : 
		public System::Windows::Forms::UserControl,
		public PanelStructure
	{

	private:
		// DS::Tree* tree_;
	public:
		PanelTree(void);

		virtual void initialize(DS::Structure* structure);
		virtual void finalize();
		virtual void enableControls(bool value);

		virtual void show();
		virtual void hide();
		virtual void dockFill();

	protected:
		~PanelTree();

	private:
		PanelStructureUpdater^ updater_;

	private: System::Windows::Forms::FlowLayoutPanel^  pnlTree;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnlTree = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// pnlTree
			// 
			this->pnlTree->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->pnlTree->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlTree->Location = System::Drawing::Point(0, 0);
			this->pnlTree->Name = L"pnlTree";
			this->pnlTree->Size = System::Drawing::Size(477, 30);
			this->pnlTree->TabIndex = 0;
			// 
			// PanelTree
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->pnlTree);
			this->Name = L"PanelTree";
			this->Size = System::Drawing::Size(477, 150);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
