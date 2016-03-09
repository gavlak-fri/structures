#pragma once

#include "PanelStructure.h"
#include "UserData.h"
#include "../Structures/Array.h"


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
		DS::Array<UI::UserData::DataType>* array_;
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
		ListViewManager^ lviewManager_;

		void refreshItem(System::Windows::Forms::ListViewItem^ item);
		void editItem(System::Windows::Forms::ListViewItem^ item);

	private: System::Windows::Forms::FlowLayoutPanel^  pnlArray;
	private: System::Windows::Forms::ListView^  lviewArray;
	private: System::Windows::Forms::ColumnHeader^  columnIndex;
	private: System::Windows::Forms::ColumnHeader^  columnData;
	private: System::Windows::Forms::ColumnHeader^  columnBits;
	private: System::Windows::Forms::Button^  btnEdit;

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
			this->btnEdit = (gcnew System::Windows::Forms::Button());
			this->lviewArray = (gcnew System::Windows::Forms::ListView());
			this->columnIndex = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnData = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnBits = (gcnew System::Windows::Forms::ColumnHeader());
			this->pnlArray->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlArray
			// 
			this->pnlArray->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->pnlArray->Controls->Add(this->btnEdit);
			this->pnlArray->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlArray->Location = System::Drawing::Point(0, 0);
			this->pnlArray->Name = L"pnlArray";
			this->pnlArray->Size = System::Drawing::Size(424, 30);
			this->pnlArray->TabIndex = 0;
			// 
			// btnEdit
			// 
			this->btnEdit->Location = System::Drawing::Point(3, 3);
			this->btnEdit->Name = L"btnEdit";
			this->btnEdit->Size = System::Drawing::Size(75, 23);
			this->btnEdit->TabIndex = 0;
			this->btnEdit->Text = L"Edit";
			this->btnEdit->UseVisualStyleBackColor = true;
			this->btnEdit->Click += gcnew System::EventHandler(this, &PanelArray::btnEdit_Click);
			// 
			// lviewArray
			// 
			this->lviewArray->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnIndex, this->columnData, this->columnBits
			});
			this->lviewArray->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lviewArray->FullRowSelect = true;
			this->lviewArray->GridLines = true;
			this->lviewArray->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->lviewArray->Location = System::Drawing::Point(0, 30);
			this->lviewArray->MultiSelect = false;
			this->lviewArray->Name = L"lviewArray";
			this->lviewArray->Size = System::Drawing::Size(424, 185);
			this->lviewArray->TabIndex = 2;
			this->lviewArray->UseCompatibleStateImageBehavior = false;
			this->lviewArray->View = System::Windows::Forms::View::Details;
			this->lviewArray->ItemSelectionChanged += gcnew System::Windows::Forms::ListViewItemSelectionChangedEventHandler(this, &PanelArray::lviewArray_ItemSelectionChanged);
			this->lviewArray->DoubleClick += gcnew System::EventHandler(this, &PanelArray::lviewArray_DoubleClick);
			// 
			// columnIndex
			// 
			this->columnIndex->Text = L"Index";
			// 
			// columnData
			// 
			this->columnData->Text = L"Data";
			// 
			// columnBits
			// 
			this->columnBits->Text = L"Bits";
			this->columnBits->Width = 300;
			// 
			// PanelArray
			// 
			this->Controls->Add(this->lviewArray);
			this->Controls->Add(this->pnlArray);
			this->Name = L"PanelArray";
			this->Size = System::Drawing::Size(424, 215);
			this->pnlArray->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		// Inherited via PanelStructure
	private: System::Void lviewArray_DoubleClick(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnEdit_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void lviewArray_ItemSelectionChanged(System::Object^  sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^  e);
};
}
