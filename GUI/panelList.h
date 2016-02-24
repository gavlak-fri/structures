#pragma once

#include "PanelStructure.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace UI {

	public ref class PanelList :
		public System::Windows::Forms::UserControl,
		public PanelStructure
	{
	private:
		//DS::List<UI::UserData::DataType>* list_;

	public:
		PanelList(void);

		virtual void initialize(DS::Structure * structure);
		virtual void finalize();
		virtual void enableControls(bool value);
		virtual void show();
		virtual void hide();
		virtual void dockFill();

	protected:
		~PanelList();

	private:
		PanelStructureUpdater^ updater_;

	private: System::Windows::Forms::FlowLayoutPanel^  pnlList;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnlList = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// pnlList
			// 
			this->pnlList->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->pnlList->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlList->Location = System::Drawing::Point(0, 0);
			this->pnlList->Name = L"pnlList";
			this->pnlList->Size = System::Drawing::Size(281, 30);
			this->pnlList->TabIndex = 1;
			// 
			// PanelList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->pnlList);
			this->Name = L"PanelList";
			this->Size = System::Drawing::Size(281, 208);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
