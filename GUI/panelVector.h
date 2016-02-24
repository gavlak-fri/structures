#pragma once

#include "PanelStructure.h"
#include "../Structures/Vector.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace UI {

	public ref class PanelVector : 
		public System::Windows::Forms::UserControl,
		public PanelStructure
	{
	private:
		DS::Vector* vector_;
	public:
		PanelVector(void);

		virtual void initialize(DS::Structure* structure);
		virtual void finalize();
		virtual void enableControls(bool value);

		virtual void show();
		virtual void hide();
		virtual void dockFill();

	protected:
		~PanelVector();
	private:
		System::Windows::Forms::ListViewItem^ selectedItem_;
		PanelStructureUpdater^ updater_;
		
		void checkBoxesToItem(System::Windows::Forms::ListViewItem^ item);
		void bitsToItem(System::Windows::Forms::ListViewItem^ item);
		void refreshItem(System::Windows::Forms::ListViewItem^ item);

	private: System::Windows::Forms::Button^  btnByteSet;
	private: System::Windows::Forms::Button^  btnByteReset;
	private: System::Windows::Forms::Button^  btnByteXOR;
	private: System::Windows::Forms::Button^  btnByteSHL;
	private: System::Windows::Forms::Button^  btnByteSHR;

	private: System::Windows::Forms::FlowLayoutPanel^  pnlVector;
	private: System::Windows::Forms::ListView^  lviewVector;

	private: System::Windows::Forms::ColumnHeader^  columnByte;
	private: System::Windows::Forms::ColumnHeader^  columnBit0;
	private: System::Windows::Forms::ColumnHeader^  columnBit1;
	private: System::Windows::Forms::ColumnHeader^  columnBit2;
	private: System::Windows::Forms::ColumnHeader^  columnBit3;
	private: System::Windows::Forms::ColumnHeader^  columnBit4;
	private: System::Windows::Forms::ColumnHeader^  columnBit5;
	private: System::Windows::Forms::ColumnHeader^  columnBit6;
	private: System::Windows::Forms::ColumnHeader^  columnBit7;

	private: array<System::Windows::Forms::CheckBox^>^ checkboxes_;
	private: System::Windows::Forms::CheckBox^  chbBit0;
	private: System::Windows::Forms::CheckBox^  chbBit1;
	private: System::Windows::Forms::CheckBox^  chbBit2;
	private: System::Windows::Forms::CheckBox^  chbBit3;
	private: System::Windows::Forms::CheckBox^  chbBit4;
	private: System::Windows::Forms::CheckBox^  chbBit5;
	private: System::Windows::Forms::CheckBox^  chbBit6;
	private: System::Windows::Forms::CheckBox^  chbBit7;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) 
		{
			this->pnlVector = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->btnByteSet = (gcnew System::Windows::Forms::Button());
			this->btnByteReset = (gcnew System::Windows::Forms::Button());
			this->btnByteXOR = (gcnew System::Windows::Forms::Button());
			this->btnByteSHL = (gcnew System::Windows::Forms::Button());
			this->btnByteSHR = (gcnew System::Windows::Forms::Button());
			this->lviewVector = (gcnew System::Windows::Forms::ListView());
			this->columnByte = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnBit7 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnBit6 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnBit5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnBit4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnBit3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnBit2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnBit1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnBit0 = (gcnew System::Windows::Forms::ColumnHeader());
			this->chbBit0 = (gcnew System::Windows::Forms::CheckBox());
			this->chbBit1 = (gcnew System::Windows::Forms::CheckBox());
			this->chbBit2 = (gcnew System::Windows::Forms::CheckBox());
			this->chbBit3 = (gcnew System::Windows::Forms::CheckBox());
			this->chbBit4 = (gcnew System::Windows::Forms::CheckBox());
			this->chbBit5 = (gcnew System::Windows::Forms::CheckBox());
			this->chbBit6 = (gcnew System::Windows::Forms::CheckBox());
			this->chbBit7 = (gcnew System::Windows::Forms::CheckBox());
			this->pnlVector->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlVector
			// 
			this->pnlVector->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->pnlVector->Controls->Add(this->btnByteSet);
			this->pnlVector->Controls->Add(this->btnByteReset);
			this->pnlVector->Controls->Add(this->btnByteXOR);
			this->pnlVector->Controls->Add(this->btnByteSHL);
			this->pnlVector->Controls->Add(this->btnByteSHR);
			this->pnlVector->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlVector->Location = System::Drawing::Point(0, 0);
			this->pnlVector->Name = L"pnlVector";
			this->pnlVector->Size = System::Drawing::Size(433, 30);
			this->pnlVector->TabIndex = 0;
			// 
			// btnByteSet
			// 
			this->btnByteSet->Enabled = false;
			this->btnByteSet->Location = System::Drawing::Point(3, 3);
			this->btnByteSet->Name = L"btnByteSet";
			this->btnByteSet->Size = System::Drawing::Size(75, 23);
			this->btnByteSet->TabIndex = 0;
			this->btnByteSet->Text = L"Set byte";
			this->btnByteSet->UseVisualStyleBackColor = true;
			this->btnByteSet->Click += gcnew System::EventHandler(this, &PanelVector::btnByteSet_Click);
			// 
			// btnByteReset
			// 
			this->btnByteReset->Enabled = false;
			this->btnByteReset->Location = System::Drawing::Point(84, 3);
			this->btnByteReset->Name = L"btnByteReset";
			this->btnByteReset->Size = System::Drawing::Size(75, 23);
			this->btnByteReset->TabIndex = 1;
			this->btnByteReset->Text = L"Reset byte";
			this->btnByteReset->UseVisualStyleBackColor = true;
			this->btnByteReset->Click += gcnew System::EventHandler(this, &PanelVector::btnByteReset_Click);
			// 
			// btnByteXOR
			// 
			this->btnByteXOR->Enabled = false;
			this->btnByteXOR->Location = System::Drawing::Point(165, 3);
			this->btnByteXOR->Name = L"btnByteXOR";
			this->btnByteXOR->Size = System::Drawing::Size(75, 23);
			this->btnByteXOR->TabIndex = 2;
			this->btnByteXOR->Text = L"XOR Byte";
			this->btnByteXOR->UseVisualStyleBackColor = true;
			this->btnByteXOR->Click += gcnew System::EventHandler(this, &PanelVector::btnByteXOR_Click);
			// 
			// btnByteSHL
			// 
			this->btnByteSHL->Enabled = false;
			this->btnByteSHL->Location = System::Drawing::Point(246, 3);
			this->btnByteSHL->Name = L"btnByteSHL";
			this->btnByteSHL->Size = System::Drawing::Size(75, 23);
			this->btnByteSHL->TabIndex = 3;
			this->btnByteSHL->Text = L"<< Byte";
			this->btnByteSHL->UseVisualStyleBackColor = true;
			this->btnByteSHL->Click += gcnew System::EventHandler(this, &PanelVector::btnByteSHL_Click);
			// 
			// btnByteSHR
			// 
			this->btnByteSHR->Enabled = false;
			this->btnByteSHR->Location = System::Drawing::Point(327, 3);
			this->btnByteSHR->Name = L"btnByteSHR";
			this->btnByteSHR->Size = System::Drawing::Size(75, 23);
			this->btnByteSHR->TabIndex = 4;
			this->btnByteSHR->Text = L">> Byte";
			this->btnByteSHR->UseVisualStyleBackColor = true;
			this->btnByteSHR->Click += gcnew System::EventHandler(this, &PanelVector::btnByteSHR_Click);
			// 
			// lviewVector
			// 
			this->lviewVector->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->lviewVector->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(9) {
				this->columnByte, this->columnBit7,
					this->columnBit6, this->columnBit5, this->columnBit4, this->columnBit3, this->columnBit2, this->columnBit1, this->columnBit0
			});
			this->lviewVector->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lviewVector->FullRowSelect = true;
			this->lviewVector->GridLines = true;
			this->lviewVector->HeaderStyle = System::Windows::Forms::ColumnHeaderStyle::Nonclickable;
			this->lviewVector->HideSelection = false;
			this->lviewVector->HoverSelection = true;
			this->lviewVector->Location = System::Drawing::Point(0, 30);
			this->lviewVector->MultiSelect = false;
			this->lviewVector->Name = L"lviewVector";
			this->lviewVector->Size = System::Drawing::Size(433, 234);
			this->lviewVector->TabIndex = 1;
			this->lviewVector->UseCompatibleStateImageBehavior = false;
			this->lviewVector->View = System::Windows::Forms::View::Details;
			this->lviewVector->ColumnWidthChanged += gcnew System::Windows::Forms::ColumnWidthChangedEventHandler(this, &PanelVector::lviewVector_ColumnWidthChanged);
			this->lviewVector->ItemSelectionChanged += gcnew System::Windows::Forms::ListViewItemSelectionChangedEventHandler(this, &PanelVector::lviewVector_ItemSelectionChanged);
			// 
			// columnByte
			// 
			this->columnByte->Text = L"Byte";
			// 
			// columnBit7
			// 
			this->columnBit7->Text = L"Bit 7";
			this->columnBit7->Width = 40;
			// 
			// columnBit6
			// 
			this->columnBit6->Text = L"Bit 6";
			this->columnBit6->Width = 40;
			// 
			// columnBit5
			// 
			this->columnBit5->Text = L"Bit 5";
			this->columnBit5->Width = 40;
			// 
			// columnBit4
			// 
			this->columnBit4->Text = L"Bit 4";
			this->columnBit4->Width = 40;
			// 
			// columnBit3
			// 
			this->columnBit3->Text = L"Bit 3";
			this->columnBit3->Width = 40;
			// 
			// columnBit2
			// 
			this->columnBit2->Text = L"Bit 2";
			this->columnBit2->Width = 40;
			// 
			// columnBit1
			// 
			this->columnBit1->Text = L"Bit 1";
			this->columnBit1->Width = 40;
			// 
			// columnBit0
			// 
			this->columnBit0->Text = L"Bit 0";
			this->columnBit0->Width = 40;
			// 
			// chbBit0
			// 
			this->chbBit0->AutoSize = true;
			this->chbBit0->Location = System::Drawing::Point(210, 71);
			this->chbBit0->Name = L"chbBit0";
			this->chbBit0->Size = System::Drawing::Size(15, 14);
			this->chbBit0->TabIndex = 2;
			this->chbBit0->UseVisualStyleBackColor = true;
			this->chbBit0->Visible = false;
			this->chbBit0->CheckedChanged += gcnew System::EventHandler(this, &PanelVector::chbBit0_CheckedChanged);
			// 
			// chbBit1
			// 
			this->chbBit1->AutoSize = true;
			this->chbBit1->Location = System::Drawing::Point(189, 71);
			this->chbBit1->Name = L"chbBit1";
			this->chbBit1->Size = System::Drawing::Size(15, 14);
			this->chbBit1->TabIndex = 3;
			this->chbBit1->UseVisualStyleBackColor = true;
			this->chbBit1->Visible = false;
			this->chbBit1->CheckedChanged += gcnew System::EventHandler(this, &PanelVector::chbBit1_CheckedChanged);
			// 
			// chbBit2
			// 
			this->chbBit2->AutoSize = true;
			this->chbBit2->Location = System::Drawing::Point(168, 71);
			this->chbBit2->Name = L"chbBit2";
			this->chbBit2->Size = System::Drawing::Size(15, 14);
			this->chbBit2->TabIndex = 4;
			this->chbBit2->UseVisualStyleBackColor = true;
			this->chbBit2->Visible = false;
			this->chbBit2->CheckedChanged += gcnew System::EventHandler(this, &PanelVector::chbBit2_CheckedChanged);
			// 
			// chbBit3
			// 
			this->chbBit3->AutoSize = true;
			this->chbBit3->Location = System::Drawing::Point(147, 71);
			this->chbBit3->Name = L"chbBit3";
			this->chbBit3->Size = System::Drawing::Size(15, 14);
			this->chbBit3->TabIndex = 5;
			this->chbBit3->UseVisualStyleBackColor = true;
			this->chbBit3->Visible = false;
			this->chbBit3->CheckedChanged += gcnew System::EventHandler(this, &PanelVector::chbBit3_CheckedChanged);
			// 
			// chbBit4
			// 
			this->chbBit4->AutoSize = true;
			this->chbBit4->Location = System::Drawing::Point(126, 71);
			this->chbBit4->Name = L"chbBit4";
			this->chbBit4->Size = System::Drawing::Size(15, 14);
			this->chbBit4->TabIndex = 6;
			this->chbBit4->UseVisualStyleBackColor = true;
			this->chbBit4->Visible = false;
			this->chbBit4->CheckedChanged += gcnew System::EventHandler(this, &PanelVector::chbBit4_CheckedChanged);
			// 
			// chbBit5
			// 
			this->chbBit5->AutoSize = true;
			this->chbBit5->Location = System::Drawing::Point(105, 71);
			this->chbBit5->Name = L"chbBit5";
			this->chbBit5->Size = System::Drawing::Size(15, 14);
			this->chbBit5->TabIndex = 7;
			this->chbBit5->UseVisualStyleBackColor = true;
			this->chbBit5->Visible = false;
			this->chbBit5->CheckedChanged += gcnew System::EventHandler(this, &PanelVector::chbBit5_CheckedChanged);
			// 
			// chbBit6
			// 
			this->chbBit6->AutoSize = true;
			this->chbBit6->Location = System::Drawing::Point(84, 71);
			this->chbBit6->Name = L"chbBit6";
			this->chbBit6->Size = System::Drawing::Size(15, 14);
			this->chbBit6->TabIndex = 8;
			this->chbBit6->UseVisualStyleBackColor = true;
			this->chbBit6->Visible = false;
			this->chbBit6->CheckedChanged += gcnew System::EventHandler(this, &PanelVector::chbBit6_CheckedChanged);
			// 
			// chbBit7
			// 
			this->chbBit7->AutoSize = true;
			this->chbBit7->Location = System::Drawing::Point(63, 71);
			this->chbBit7->Name = L"chbBit7";
			this->chbBit7->Size = System::Drawing::Size(15, 14);
			this->chbBit7->TabIndex = 9;
			this->chbBit7->UseVisualStyleBackColor = true;
			this->chbBit7->Visible = false;
			this->chbBit7->CheckedChanged += gcnew System::EventHandler(this, &PanelVector::chbBit7_CheckedChanged);
			// 
			// PanelVector
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->chbBit7);
			this->Controls->Add(this->chbBit6);
			this->Controls->Add(this->chbBit5);
			this->Controls->Add(this->chbBit4);
			this->Controls->Add(this->chbBit3);
			this->Controls->Add(this->chbBit2);
			this->Controls->Add(this->chbBit1);
			this->Controls->Add(this->chbBit0);
			this->Controls->Add(this->lviewVector);
			this->Controls->Add(this->pnlVector);
			this->Name = L"PanelVector";
			this->Size = System::Drawing::Size(433, 264);
			this->pnlVector->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

  private: System::Void btnByteSet_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void btnByteReset_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void btnByteXOR_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void btnByteSHL_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void btnByteSHR_Click(System::Object^  sender, System::EventArgs^  e);
  private: System::Void lviewVector_ColumnWidthChanged(System::Object^  sender, System::Windows::Forms::ColumnWidthChangedEventArgs^  e);
  private: System::Void lviewVector_ItemSelectionChanged(System::Object^  sender, System::Windows::Forms::ListViewItemSelectionChangedEventArgs^  e);
  private: System::Void chbBit0_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
  private: System::Void chbBit1_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
  private: System::Void chbBit2_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
  private: System::Void chbBit3_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
  private: System::Void chbBit4_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
  private: System::Void chbBit5_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
  private: System::Void chbBit6_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
  private: System::Void chbBit7_CheckedChanged(System::Object^  sender, System::EventArgs^  e);
};
}
