#pragma once

#include "PanelStructure.h"
#include "UserData.h"
#include "../Structures/List.h"

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
		DS::List<UI::UserData::DataType>* list_;

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
		ListViewManager^ lviewManager_;

		void refreshItem(System::Windows::Forms::ListViewItem ^ item);
		void editItem(System::Windows::Forms::ListViewItem^ item);
		void setButtons();

	private: System::Windows::Forms::FlowLayoutPanel^  pnlList;
	private: System::Windows::Forms::Button^  btnAdd;
	private: System::Windows::Forms::Button^  btnInsert;
	private: System::Windows::Forms::Button^  btnEdit;
	private: System::Windows::Forms::Button^  btnRemove;
	private: System::Windows::Forms::Button^  btnRemoveAt;
	private: System::Windows::Forms::Button^  btnGetIndexOf;
	private: System::Windows::Forms::ListView^  lviewList;
	private: System::Windows::Forms::ColumnHeader^  columnIndex;
	private: System::Windows::Forms::ColumnHeader^  columnData;

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
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnInsert = (gcnew System::Windows::Forms::Button());
			this->btnGetIndexOf = (gcnew System::Windows::Forms::Button());
			this->btnRemove = (gcnew System::Windows::Forms::Button());
			this->btnRemoveAt = (gcnew System::Windows::Forms::Button());
			this->lviewList = (gcnew System::Windows::Forms::ListView());
			this->columnIndex = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnData = (gcnew System::Windows::Forms::ColumnHeader());
			this->btnEdit = (gcnew System::Windows::Forms::Button());
			this->pnlList->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlList
			// 
			this->pnlList->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->pnlList->Controls->Add(this->btnAdd);
			this->pnlList->Controls->Add(this->btnInsert);
			this->pnlList->Controls->Add(this->btnEdit);
			this->pnlList->Controls->Add(this->btnGetIndexOf);
			this->pnlList->Controls->Add(this->btnRemove);
			this->pnlList->Controls->Add(this->btnRemoveAt);
			this->pnlList->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlList->Location = System::Drawing::Point(0, 0);
			this->pnlList->Name = L"pnlList";
			this->pnlList->Size = System::Drawing::Size(598, 30);
			this->pnlList->TabIndex = 1;
			// 
			// btnAdd
			// 
			this->btnAdd->Enabled = false;
			this->btnAdd->Location = System::Drawing::Point(3, 3);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(75, 23);
			this->btnAdd->TabIndex = 0;
			this->btnAdd->Text = L"Add";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &PanelList::btnAdd_Click);
			// 
			// btnInsert
			// 
			this->btnInsert->Enabled = false;
			this->btnInsert->Location = System::Drawing::Point(84, 3);
			this->btnInsert->Name = L"btnInsert";
			this->btnInsert->Size = System::Drawing::Size(75, 23);
			this->btnInsert->TabIndex = 1;
			this->btnInsert->Text = L"Insert";
			this->btnInsert->UseVisualStyleBackColor = true;
			this->btnInsert->Click += gcnew System::EventHandler(this, &PanelList::btnInsert_Click);
			// 
			// btnEdit
			// 
			this->btnEdit->Enabled = false;
			this->btnEdit->Location = System::Drawing::Point(165, 3);
			this->btnEdit->Name = L"btnEdit";
			this->btnEdit->Size = System::Drawing::Size(75, 23);
			this->btnEdit->TabIndex = 5;
			this->btnEdit->Text = L"Edit";
			this->btnEdit->UseVisualStyleBackColor = true;
			this->btnEdit->Click += gcnew System::EventHandler(this, &PanelList::btnEdit_Click);
			// 
			// btnGetIndexOf
			// 
			this->btnGetIndexOf->Enabled = false;
			this->btnGetIndexOf->Location = System::Drawing::Point(246, 3);
			this->btnGetIndexOf->Name = L"btnGetIndexOf";
			this->btnGetIndexOf->Size = System::Drawing::Size(75, 23);
			this->btnGetIndexOf->TabIndex = 4;
			this->btnGetIndexOf->Text = L"Get index of";
			this->btnGetIndexOf->UseVisualStyleBackColor = true;
			this->btnGetIndexOf->Click += gcnew System::EventHandler(this, &PanelList::btnGetIndexOf_Click);
			// 
			// btnRemove
			// 
			this->btnRemove->Enabled = false;
			this->btnRemove->Location = System::Drawing::Point(327, 3);
			this->btnRemove->Name = L"btnRemove";
			this->btnRemove->Size = System::Drawing::Size(95, 23);
			this->btnRemove->TabIndex = 2;
			this->btnRemove->Text = L"Find and remove";
			this->btnRemove->UseVisualStyleBackColor = true;
			this->btnRemove->Click += gcnew System::EventHandler(this, &PanelList::btnRemove_Click);
			// 
			// btnRemoveAt
			// 
			this->btnRemoveAt->Enabled = false;
			this->btnRemoveAt->Location = System::Drawing::Point(428, 3);
			this->btnRemoveAt->Name = L"btnRemoveAt";
			this->btnRemoveAt->Size = System::Drawing::Size(75, 23);
			this->btnRemoveAt->TabIndex = 3;
			this->btnRemoveAt->Text = L"Remove at";
			this->btnRemoveAt->UseVisualStyleBackColor = true;
			this->btnRemoveAt->Click += gcnew System::EventHandler(this, &PanelList::btnRemoveAt_Click);
			// 
			// lviewList
			// 
			this->lviewList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->columnIndex, this->columnData });
			this->lviewList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lviewList->FullRowSelect = true;
			this->lviewList->GridLines = true;
			this->lviewList->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->lviewList->HideSelection = false;
			this->lviewList->LabelEdit = true;
			this->lviewList->Location = System::Drawing::Point(0, 30);
			this->lviewList->MultiSelect = false;
			this->lviewList->Name = L"lviewList";
			this->lviewList->Size = System::Drawing::Size(598, 178);
			this->lviewList->TabIndex = 3;
			this->lviewList->UseCompatibleStateImageBehavior = false;
			this->lviewList->View = System::Windows::Forms::View::Details;
			this->lviewList->SelectedIndexChanged += gcnew System::EventHandler(this, &PanelList::lviewList_SelectedIndexChanged);
			this->lviewList->DoubleClick += gcnew System::EventHandler(this, &PanelList::lviewList_DoubleClick);
			// 
			// columnIndex
			// 
			this->columnIndex->Text = L"Index";
			// 
			// columnData
			// 
			this->columnData->Text = L"Data";			
			// 
			// PanelList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->lviewList);
			this->Controls->Add(this->pnlList);
			this->Name = L"PanelList";
			this->Size = System::Drawing::Size(598, 208);
			this->pnlList->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnInsert_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnEdit_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnGetIndexOf_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnRemove_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void btnRemoveAt_Click(System::Object^  sender, System::EventArgs^  e);
private: System::Void lviewList_DoubleClick(System::Object^  sender, System::EventArgs^  e);
private: System::Void lviewList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
};
}
