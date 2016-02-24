#include "Routines.h"
#include <sstream>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace DS;
using namespace UI;
using namespace std;

void Routines::listViewItemSelect(System::Windows::Forms::ListViewItem ^ &item)
{
	item->Selected = true;
}

void Routines::listViewItemDeselect(System::Windows::Forms::ListViewItem ^ &item)
{
	item->Selected = false;
}

void Routines::listViewItemRemove(System::Windows::Forms::ListViewItem ^ &item)
{
	item->ListView->Items->Remove(item);
	item = nullptr;
}

ListViewItem ^ Routines::listViewAddItem(ListView ^ lview, System::String ^ text, bool selectAdded)
{
	listViewDeselect(lview);
	ListViewItem^ item = (gcnew ListViewItem(text));
	lview->Items->Add(item);
	if (selectAdded)
		listViewItemSelect(item);
	return item;
}

ListViewItem ^ Routines::listViewAddItem(ListView ^ lview, string text, bool selectAdded)
{
	return Routines::listViewAddItem(lview, Routines::convertStrToString(text), selectAdded);
}

System::Windows::Forms::ListViewItem ^ UI::Routines::listViewInsertItem(ListView ^ lview, int index, string text, bool selectAdded)
{
	listViewDeselect(lview);
	ListViewItem^ item = (gcnew ListViewItem(Routines::convertStrToString(text)));
	lview->Items->Insert(index, item);
	if (selectAdded)
		listViewItemSelect(item);
	return item;
}

void Routines::listViewRemoveSelected(ListView ^ lview)
{
	listViewProcessSelection(lview, listViewItemRemove);
}

void Routines::listViewDeselect(ListView ^ lview)
{
	listViewProcessSelection(lview, listViewItemDeselect);
}

void Routines::listViewProcessItems(System::Windows::Forms::ListView ^ lview, eventListViewItem event)
{
	int i = 0;

	while (i < lview->Items->Count)
	{
		ListViewItem^ item = lview->Items[i];
		event(item);
		// item mohla byt vymazana
		if (item != nullptr)
			i++;
	}
}

void Routines::listViewProcessSelection(System::Windows::Forms::ListView ^ lview, eventListViewItem event)
{
	int i = 0;
	int count = lview->Items->Count;
	while (i < count)
	{
		ListViewItem^ item = lview->Items[i];
		event(item);
		// item mohla byt vymazana alebo deselectnuta
		if (item != nullptr && count == lview->Items->Count)
			i++;
		else
			count = lview->Items->Count;
	}
}

void UI::Routines::listViewFill(System::Windows::Forms::ListView ^ lview, DS::Iterable<UserData::DataType>* structure)
{
	if (lview != nullptr)
	{
		lview->Items->Clear();
		if (structure != nullptr)
		{
			int i = 0;
			for (auto data : *structure)
			{
				ListViewItem^ item = Routines::listViewAddItem(lview, Routines::convertIntToStr(i), true);
				if (item->SubItems->Count < 2)
					item->SubItems->Add("");
				item->SubItems[1]->Text = UserData::convertDataToStr(data);

				i++;
			}
		}
	}
}

void Routines::layoutControlToCenter(Control^ control, Rectangle^ rect, int offsetLeft, int offsetTop)
{
	control->Left = offsetLeft + rect->Left + rect->Width / 2 - control->Width / 2;
	control->Top = offsetTop + rect->Top + rect->Height / 2 - control->Height / 2;
}

void Routines::layoutControlFillRect(Control^ control, Rectangle^ rect, int offsetLeft, int offsetTop)
{
	control->Left = offsetLeft + rect->Left;
	control->Top = offsetTop + rect->Top;
	control->Width = rect->Width;
	control->Height = rect->Height;
}

string Routines::convertStructureADTToStr(const StructureADT adt)
{
	switch (adt)
	{
	case adtVECTOR:
		return "Vector";
	case adtARRAY:
		return "Array";
	case adtLIST:
		return "List";
	case adtQUEUE:
		return "Queue";
	case adtSTACK:
		return "Stack";
	case adtPRIORITY_QUEUE:
		return "Priority queue";
	case adtTREE:
		return "Tree";
	case adtGRAPH:
		return "Graph";
	case adtTABLE:
		return "Table";
	default:
		return "Unknown ADT";
	}
}

string  UI::Routines::convertStructureADSToStr(const DS::StructureADS ads)
{
	switch (ads)
	{
	case adsVECTOR:
		return "Vector";

	case adsARRAY:
		return "Array";

	case adsLIST_ARRAY:
		return "Array list";
	case adsLIST_LINKED:
		return "Linked list";
	case adsLIST_DOUBLE_LINKED:
		return "Double-linked list";
	case adsLIST_CYCLICAL:
		return "Cyclical list";

	case adsQUEUE_ARRAY:
		return "Queue by array";
	case adsQUEUE_LIST:
		return "Queue by list";

	case adsSTACK_ARRAY:
		return "Stack by array";
	case adsSTACK_LIST:
		return "Stack by list";

	case adsPRIORITY_QUEUE_ARRAY:
		return "Priority queue by array";
	case adsPRIORITY_QUEUE_LIST:
		return "Priority queue by list";
	case adsPRIORITY_QUEUE_TWO_LISTS:
		return "Priority queue by two lists";
	case adsPRIORITY_QUEUE_DOUBLE_LAYER:
		return "Priority queue double layer implementation";
	case adsPRIORITY_QUEUE_HEAP:
		return "Heap";

	case adsTREE:
		return "Tree";

	case adsGRAPH_MATRIX:
		return "Graph by matrix";
	case adsGRAPH_STAR:
		return "Graph by star";

	case adsTABLE_SEQUENCE_SORTED:
		return "Sorted sequence table";
	case adsTABLE_SEQUENCE_NONSORTED:
		return "Nonsorted sequence table";
	case adsTABLE_LINKED:
		return "Linked table";
	case adsTABLE_DIAMOND:
		return "Diamond table";
	case adsTABLE_HASH:
		return "Hash table";
	case adsTABLE_BST:
		return "Binary search tree";
	case adsTABLE_TREAP:
		return "Treap";
	default:
		return "Unknown ADS";
	}
}

string UI::Routines::convertLogTypeToStr(const DS::LogType lt)
{
	switch (lt)
	{
	case ERROR:
		return "Error";
	case WARNING:
		return "Warning";
	case HINT:
		return "Hint";
	case WAIT:
		return "Wait";
	case DEBUG:
		return "Debug";
	default:
		return "Unknown";
	}
}

string Routines::convertIntToStr(int i)
{
	return std::to_string(i);
}

System::String ^ UI::Routines::convertIntToString(int i)
{
	return  Routines::convertStrToString(Routines::convertIntToStr(i));
}

String ^ UI::Routines::convertStrToString(string s)
{
	return gcnew String(s.c_str());
}

Routines::Routines()
{
}
