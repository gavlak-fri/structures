#pragma once

#include "UserData.h"

namespace UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FormData :
		public System::Windows::Forms::Form
	{
	public:
		static bool tryGetData(UI::UserData::DataType& data);
		static bool tryGetPriorityData(UI::UserData::PriorityType& priority, UI::UserData::DataType& data, bool modifyPriority);
		static bool tryGetKeyData(UI::UserData::KeyType& key, UI::UserData::DataType& data, bool modifyKey);

	protected:
		enum class FormType
		{
			DATA,
			PRIORITY,
			KEY
		};

		FormData(const FormType formType);
		virtual bool isEverythingOK();
		~FormData();
	private:
		FormType formType_;
		bool ok_;
		UI::UserData::DataType data_;
		UI::UserData::PriorityType priority_;
		UI::UserData::KeyType key_;

		void setData(UI::UserData::DataType& data);
		void setPriority(UI::UserData::PriorityType& priority);
		void setKey(UI::UserData::KeyType& key);

		bool areDataCorrect();
		bool isPriorityCorrect();
		bool isKeyCorrect();

	private: System::Windows::Forms::TextBox^  txtData;
	private: System::Windows::Forms::Label^  lblData;
	private: System::Windows::Forms::TextBox^  txtPriority;
	private: System::Windows::Forms::Label^  lblPriority;
	private: System::Windows::Forms::TextBox^  txtKey;
	private: System::Windows::Forms::Label^  lblKey;
	private: System::Windows::Forms::Button^  btnOk;
	private: System::Windows::Forms::Button^  btnCancel;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblData = (gcnew System::Windows::Forms::Label());
			this->btnOk = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->txtData = (gcnew System::Windows::Forms::TextBox());
			this->txtPriority = (gcnew System::Windows::Forms::TextBox());
			this->lblPriority = (gcnew System::Windows::Forms::Label());
			this->txtKey = (gcnew System::Windows::Forms::TextBox());
			this->lblKey = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lblData
			// 
			this->lblData->AutoSize = true;
			this->lblData->Location = System::Drawing::Point(13, 39);
			this->lblData->Name = L"lblData";
			this->lblData->Size = System::Drawing::Size(37, 13);
			this->lblData->TabIndex = 0;
			this->lblData->Text = L"Value:";
			// 
			// btnOk
			// 
			this->btnOk->Location = System::Drawing::Point(65, 62);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(75, 23);
			this->btnOk->TabIndex = 1;
			this->btnOk->Text = L"OK";
			this->btnOk->UseVisualStyleBackColor = true;
			this->btnOk->Click += gcnew System::EventHandler(this, &FormData::btnOk_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->Location = System::Drawing::Point(146, 62);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 2;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &FormData::btnCancel_Click);
			// 
			// txtData
			// 
			this->txtData->Location = System::Drawing::Point(56, 36);
			this->txtData->Name = L"txtData";
			this->txtData->Size = System::Drawing::Size(179, 20);
			this->txtData->TabIndex = 3;
			// 
			// txtPriority
			// 
			this->txtPriority->Location = System::Drawing::Point(56, 12);
			this->txtPriority->Name = L"txtPriority";
			this->txtPriority->Size = System::Drawing::Size(179, 20);
			this->txtPriority->TabIndex = 5;
			// 
			// lblPriority
			// 
			this->lblPriority->AutoSize = true;
			this->lblPriority->Location = System::Drawing::Point(13, 15);
			this->lblPriority->Name = L"lblPriority";
			this->lblPriority->Size = System::Drawing::Size(41, 13);
			this->lblPriority->TabIndex = 4;
			this->lblPriority->Text = L"Priority:";
			// 
			// txtKey
			// 
			this->txtKey->Location = System::Drawing::Point(56, 10);
			this->txtKey->Name = L"txtKey";
			this->txtKey->Size = System::Drawing::Size(179, 20);
			this->txtKey->TabIndex = 6;
			// 
			// lblKey
			// 
			this->lblKey->AutoSize = true;
			this->lblKey->Location = System::Drawing::Point(13, 15);
			this->lblKey->Name = L"lblKey";
			this->lblKey->Size = System::Drawing::Size(28, 13);
			this->lblKey->TabIndex = 7;
			this->lblKey->Text = L"Key:";
			// 
			// FormData
			// 
			this->AcceptButton = this->btnOk;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnCancel;
			this->ClientSize = System::Drawing::Size(270, 93);
			this->Controls->Add(this->lblKey);
			this->Controls->Add(this->txtKey);
			this->Controls->Add(this->txtPriority);
			this->Controls->Add(this->lblPriority);
			this->Controls->Add(this->txtData);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnOk);
			this->Controls->Add(this->lblData);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormData";
			this->Text = L"Data";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormData::FormData_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnOk_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void FormData_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e);
	};
}
