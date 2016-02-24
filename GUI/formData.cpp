#include "formData.h"
#include "Routines.h"

UI::FormData::FormData(const FormType formType)
{
	InitializeComponent();

	switch (formType)
	{
		case FormType::DATA:
			txtPriority->Visible = false;
			lblPriority->Visible = false;
			txtKey->Visible = false;
			lblKey->Visible = false;
			break;
		case FormType::PRIORITY:
			txtPriority->Visible = true;
			lblPriority->Visible = true;
			txtKey->Visible = false;
			lblKey->Visible = false;
			break;
		case FormType::KEY:
			txtPriority->Visible = false;
			lblPriority->Visible = false;
			txtKey->Visible = true;
			lblKey->Visible = true;
			break;
	}

	formType_ = formType;
	ok_ = true;
}

UI::FormData::~FormData()
{
	if (components)
	{
		delete components;
	}
}

void UI::FormData::setData(UI::UserData::DataType& data)
{
	data_ = data;
	txtData->Text = UI::UserData::convertDataToStr(data);
}

void UI::FormData::setPriority(UI::UserData::PriorityType& priority)
{
	priority_ = priority;
	txtPriority->Text = UI::UserData::convertPriorityToStr(priority);
}

void UI::FormData::setKey(UI::UserData::KeyType & key)
{
	throw gcnew System::NotImplementedException();
}

bool UI::FormData::areDataCorrect()
{
	try
	{
		/*if (data_ == nullptr)
		{
			data_ = UserData::defaultDataValue();
		}*/
		data_ = System::Convert::ToInt32(txtData->Text);
	}
	catch (System::FormatException^)
	{
		System::Windows::Forms::MessageBox::Show("Data are not a 32-bits integer.");
		txtData->Focus();
		return false;
	}
	catch (System::OverflowException^)
	{
		System::Windows::Forms::MessageBox::Show("Data are not a 32-bits integer.");
		txtData->Focus();
		return false;
	}
	return true;
}

bool UI::FormData::isPriorityCorrect()
{
	try
	{
		priority_ = System::Convert::ToInt32(txtPriority->Text);
	}
	catch (System::FormatException^)
	{
		System::Windows::Forms::MessageBox::Show("Priority is not a 32-bits integer.");
		txtPriority->Focus();
		return false;
	}
	catch (System::OverflowException^)
	{
		System::Windows::Forms::MessageBox::Show("Priority is not a 32-bits integer.");
		txtPriority->Focus();
		return false;
	}
	return true;
}

bool UI::FormData::isKeyCorrect()
{
	try
	{
		key_ = System::Convert::ToInt32(txtKey->Text);
	}
	catch (System::FormatException^)
	{
		System::Windows::Forms::MessageBox::Show("Key is not a 32-bits integer.");
		txtKey->Focus();
		return false;
	}
	catch (System::OverflowException^)
	{
		System::Windows::Forms::MessageBox::Show("Key is not a 32-bits integer.");
		txtKey->Focus();
		return false;
	}
	return true;
}

bool UI::FormData::tryGetData(UI::UserData::DataType& data)
{
	UI::FormData^ frmData = gcnew UI::FormData(FormType::DATA);
	frmData->setData(data);
	frmData->ShowDialog();

	data = frmData->data_;
	bool result = frmData->ok_;

	delete frmData;
	return result;
}

bool UI::FormData::tryGetPriorityData(UI::UserData::PriorityType& priority, UI::UserData::DataType& data, bool modifyPriority)
{
	UI::FormData^ frmData = gcnew UI::FormData(FormType::PRIORITY);
	frmData->setData(data);
	frmData->setPriority(priority);
	frmData->txtPriority->Enabled = modifyPriority;
	frmData->ShowDialog();

	data = frmData->data_;
	priority = frmData->priority_;
	bool result = frmData->ok_;

	delete frmData;
	return result;
}

bool UI::FormData::tryGetKeyData(UI::UserData::KeyType& key, UI::UserData::DataType & data, bool modifyKey)
{
	UI::FormData^ frmData = gcnew UI::FormData(FormType::KEY);
	frmData->setData(data);
	frmData->setKey(key);
	frmData->txtKey->Enabled = modifyKey;
	frmData->ShowDialog();

	data = frmData->data_;
	key = frmData->priority_;
	bool result = frmData->ok_;

	delete frmData;
	return result;
}

bool UI::FormData::isEverythingOK()
{
	return areDataCorrect() &&
		(formType_ != FormType::PRIORITY || (formType_ == FormType::PRIORITY && isPriorityCorrect())) &&
		(formType_ != FormType::KEY || (formType_ == FormType::KEY && isKeyCorrect()));
}

System::Void UI::FormData::btnOk_Click(System::Object ^ sender, System::EventArgs ^ e) {
	if (isEverythingOK())
	{
		Close();
		ok_ = true;
	}
}

System::Void UI::FormData::btnCancel_Click(System::Object ^ sender, System::EventArgs ^ e) {
	Close();
}

System::Void UI::FormData::FormData_FormClosing(System::Object ^ sender, System::Windows::Forms::FormClosingEventArgs ^ e) {
	ok_ = false;
}

/*
System::Void UI::FormData::txtData_KeyUp(System::Object ^ sender, System::Windows::Forms::KeyEventArgs ^ e) {
	//if (e->KeyCode == Keys::Enter)
}*/
