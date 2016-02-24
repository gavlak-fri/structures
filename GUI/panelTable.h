#pragma once

#include "PanelStructure.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace UI {

	public ref class PanelTable :
		public System::Windows::Forms::UserControl,
		public PanelStructure
	{

	private:
		// DS::Table* table_;
	public:
		PanelTable(void);

		virtual void initialize(DS::Structure* structure);
		virtual void finalize();
		virtual void enableControls(bool value);

		virtual void show();
		virtual void hide();
		virtual void dockFill();

	protected:
		~PanelTable();

	private:
		PanelStructureUpdater^ updater_;

	private: System::Windows::Forms::FlowLayoutPanel^  pnlTable;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnlTable = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// pnlTable
			// 
			this->pnlTable->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->pnlTable->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlTable->Location = System::Drawing::Point(0, 0);
			this->pnlTable->Name = L"pnlTable";
			this->pnlTable->Size = System::Drawing::Size(442, 30);
			this->pnlTable->TabIndex = 0;
			// 
			// PanelTable
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->pnlTable);
			this->Name = L"PanelTable";
			this->Size = System::Drawing::Size(442, 266);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
