#pragma once

#include "../Structures/StructureID.h"
#include "../Structures/Structure.h"
#include "../Structures/StructuresFactory.h"
#include "PanelStructure.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Data;
using namespace System::Drawing;

namespace UI {

	public ref class PanelStructures : public System::Windows::Forms::UserControl
	{

	public:
		PanelStructures(void);
		void initialize(const DS::StructureADT adt);

	protected:
		~PanelStructures();

	private:
		DS::AbstractDataTypes* adt_;
	    bool initialized_;

		static PanelStructure^ createPanelFromStructureID(const DS::StructureADT adt);
		void updateControls();

		property DS::Structure* StructureByItem[System::Windows::Forms::ListViewItem^]{
			DS::Structure* get(System::Windows::Forms::ListViewItem^ item)
			{
				return item != nullptr ? adt_->getActiveStructureByIndex(item->Index) : nullptr;
			}
		}

		property DS::Structure* SelectedStructure {
			DS::Structure* get()
			{
				return lviewStructures->SelectedItems->Count > 0 ? StructureByItem[lviewStructures->SelectedItems[0]] : nullptr;
			}
		}

	private: System::Windows::Forms::ColumnHeader^  colStructures;
	private: System::Windows::Forms::Button^  btnClone;
	private: System::Windows::Forms::FlowLayoutPanel^  pnlStructures;
	private: System::Windows::Forms::Button^  btnNew;
	private: System::Windows::Forms::Button^  btnDelete;
	private: System::Windows::Forms::ListView^  lviewStructures;
	private: System::Windows::Forms::Splitter^  splitterStructures;
	private: System::Windows::Forms::Panel^  pnlStructure;
	private: System::Windows::Forms::ComboBox^  cbxADS;

	private:  
		System::ComponentModel::Container ^components;

		PanelStructure ^pnlCustomStructure_;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnlStructures = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->cbxADS = (gcnew System::Windows::Forms::ComboBox());
			this->btnNew = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnClone = (gcnew System::Windows::Forms::Button());
			this->lviewStructures = (gcnew System::Windows::Forms::ListView());
			this->colStructures = (gcnew System::Windows::Forms::ColumnHeader());
			this->splitterStructures = (gcnew System::Windows::Forms::Splitter());
			this->pnlStructure = (gcnew System::Windows::Forms::Panel());
			this->pnlStructures->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlStructures
			// 
			this->pnlStructures->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pnlStructures->Controls->Add(this->cbxADS);
			this->pnlStructures->Controls->Add(this->btnNew);
			this->pnlStructures->Controls->Add(this->btnDelete);
			this->pnlStructures->Controls->Add(this->btnClone);
			this->pnlStructures->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlStructures->Location = System::Drawing::Point(0, 0);
			this->pnlStructures->Name = L"pnlStructures";
			this->pnlStructures->Size = System::Drawing::Size(439, 30);
			this->pnlStructures->TabIndex = 0;
			// 
			// cbxADS
			// 
			this->cbxADS->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cbxADS->FormattingEnabled = true;
			this->cbxADS->Location = System::Drawing::Point(3, 3);
			this->cbxADS->Name = L"cbxADS";
			this->cbxADS->Size = System::Drawing::Size(121, 21);
			this->cbxADS->TabIndex = 3;
			// 
			// btnNew
			// 
			this->btnNew->Location = System::Drawing::Point(130, 3);
			this->btnNew->Name = L"btnNew";
			this->btnNew->Size = System::Drawing::Size(75, 23);
			this->btnNew->TabIndex = 0;
			this->btnNew->Text = L"New";
			this->btnNew->UseVisualStyleBackColor = true;
			this->btnNew->Click += gcnew System::EventHandler(this, &PanelStructures::btnNew_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Enabled = false;
			this->btnDelete->Location = System::Drawing::Point(211, 3);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 23);
			this->btnDelete->TabIndex = 1;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &PanelStructures::btnDelete_Click);
			// 
			// btnClone
			// 
			this->btnClone->Enabled = false;
			this->btnClone->Location = System::Drawing::Point(292, 3);
			this->btnClone->Name = L"btnClone";
			this->btnClone->Size = System::Drawing::Size(75, 23);
			this->btnClone->TabIndex = 2;
			this->btnClone->Text = L"Clone";
			this->btnClone->UseVisualStyleBackColor = true;
			this->btnClone->Click += gcnew System::EventHandler(this, &PanelStructures::btnClone_Click);
			// 
			// lviewStructures
			// 
			this->lviewStructures->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->lviewStructures->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(1) { this->colStructures });
			this->lviewStructures->Dock = System::Windows::Forms::DockStyle::Left;
			this->lviewStructures->FullRowSelect = true;
			this->lviewStructures->HideSelection = false;
			this->lviewStructures->Location = System::Drawing::Point(0, 30);
			this->lviewStructures->MultiSelect = false;
			this->lviewStructures->Name = L"lviewStructures";
			this->lviewStructures->Size = System::Drawing::Size(250, 357);
			this->lviewStructures->TabIndex = 1;
			this->lviewStructures->UseCompatibleStateImageBehavior = false;
			this->lviewStructures->View = System::Windows::Forms::View::Details;
			this->lviewStructures->ItemSelectionChanged += gcnew System::Windows::Forms::ListViewItemSelectionChangedEventHandler(this, &PanelStructures::lviewStructures_ItemSelectionChanged);
			// 
			// colStructures
			// 
			this->colStructures->Text = L"Structures";
			this->colStructures->Width = 228;
			// 
			// splitterStructures
			// 
			this->splitterStructures->Location = System::Drawing::Point(250, 30);
			this->splitterStructures->Name = L"splitterStructures";
			this->splitterStructures->Size = System::Drawing::Size(3, 357);
			this->splitterStructures->TabIndex = 2;
			this->splitterStructures->TabStop = false;
			// 
			// pnlStructure
			// 
			this->pnlStructure->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pnlStructure->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlStructure->Location = System::Drawing::Point(253, 30);
			this->pnlStructure->Name = L"pnlStructure";
			this->pnlStructure->Size = System::Drawing::Size(186, 357);
			this->pnlStructure->TabIndex = 3;
			// 
			// PanelStructures
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->pnlStructure);
			this->Controls->Add(this->splitterStructures);
			this->Controls->Add(this->lviewStructures);
			this->Controls->Add(this->pnlStructures);
			this->Name = L"PanelStructures";
			this->Size = System::Drawing::Size(439, 387);
			this->pnlStructures->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void btnNew_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnDelete_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnClone_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void lviewStructures_ItemSelectionChanged(System::Object^  sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^  e);
};
}
