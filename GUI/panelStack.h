#pragma once

#include "PanelStructure.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace UI {

	public ref class PanelStack :
		public System::Windows::Forms::UserControl,
		public PanelStructure
	{
	private:
		//DS::Stack<UI::UserData::DataType> *stack_;
	public:
		PanelStack(void);

		virtual void initialize(DS::Structure* structure);
		virtual void finalize();
		virtual void enableControls(bool value);

		virtual void show();
		virtual void hide();
		virtual void dockFill();

	protected:
		~PanelStack();

	private:
		PanelStructureUpdater^ updater_;

	private: System::Windows::Forms::FlowLayoutPanel^  pnlStack;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnlStack = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// pnlStack
			// 
			this->pnlStack->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->pnlStack->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlStack->Location = System::Drawing::Point(0, 0);
			this->pnlStack->Name = L"pnlStack";
			this->pnlStack->Size = System::Drawing::Size(318, 30);
			this->pnlStack->TabIndex = 0;
			// 
			// PanelStack
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->pnlStack);
			this->Name = L"PanelStack";
			this->Size = System::Drawing::Size(318, 150);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
