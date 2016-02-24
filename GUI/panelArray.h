#pragma once

#include "PanelStructure.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace UI {

	public ref class PanelArray :
		public System::Windows::Forms::UserControl,
		public PanelStructure
	{
	private:
		//DS::Array<UI::UserData::DataType>* array_;
	public:
		PanelArray(void);

		virtual void initialize(DS::Structure* structure);
		virtual void finalize();
		virtual void enableControls(bool value);

		virtual void show();
		virtual void hide();
		virtual void dockFill();

	protected:
		~PanelArray();

	private:
		PanelStructureUpdater^ updater_;

	private: System::Windows::Forms::FlowLayoutPanel^  pnlArray;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnlArray = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// pnlArray
			// 
			this->pnlArray->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->pnlArray->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlArray->Location = System::Drawing::Point(0, 0);
			this->pnlArray->Name = L"pnlArray";
			this->pnlArray->Size = System::Drawing::Size(424, 30);
			this->pnlArray->TabIndex = 0;
			// 
			// PanelArray
			// 
			this->Controls->Add(this->pnlArray);
			this->Name = L"PanelArray";
			this->Size = System::Drawing::Size(424, 215);
			this->ResumeLayout(false);

		}
#pragma endregion

};
}
