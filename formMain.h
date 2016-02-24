#pragma once

#include "Structures/StructureID.h"
#include "GUI/panelStructures.h"
#include "GUI/Logger.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FormMain sealed : 
		public System::Windows::Forms::Form,
		public DS::ILogger
	{

		public:
			FormMain(void);
			virtual void Log(DS::LogType lt, System::String^ message);

		protected:
			~FormMain();
	private: System::Windows::Forms::TabControl^  tabsStructures;
	protected:
	private: System::Windows::Forms::TabPage^  tabVector;
	private: System::Windows::Forms::TabPage^  tabArray;
	private: System::Windows::Forms::TabPage^  tabList;
	private: System::Windows::Forms::TabPage^  tabQueue;
	private: System::Windows::Forms::TabPage^  tabStack;
	private: System::Windows::Forms::TabPage^  tabPriorityQueue;
	private: System::Windows::Forms::TabPage^  tabGraph;
	private: System::Windows::Forms::TabPage^  tabTree;
	private: System::Windows::Forms::TabPage^  tabTable;
	private: System::Windows::Forms::TabPage^  tabSorting;

		private:
			array<UI::PanelStructures^>^ panels_;
			
			void initializePanel(const DS::StructureADT adt);
			System::Windows::Forms::TabPage^ getTabFromStructureADT(const DS::StructureADT adt);












	private: System::ComponentModel::IContainer^  components;

	private: System::Windows::Forms::Panel^  pnlLog;
	private: System::Windows::Forms::ListView^  lviewLog;
	private: System::Windows::Forms::Splitter^  splitterLog;
	private: System::Windows::Forms::ColumnHeader^  columnType;
	private: System::Windows::Forms::ColumnHeader^  columnMessage;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnlLog = (gcnew System::Windows::Forms::Panel());
			this->lviewLog = (gcnew System::Windows::Forms::ListView());
			this->columnType = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnMessage = (gcnew System::Windows::Forms::ColumnHeader());
			this->splitterLog = (gcnew System::Windows::Forms::Splitter());
			this->tabsStructures = (gcnew System::Windows::Forms::TabControl());
			this->tabVector = (gcnew System::Windows::Forms::TabPage());
			this->tabArray = (gcnew System::Windows::Forms::TabPage());
			this->tabList = (gcnew System::Windows::Forms::TabPage());
			this->tabQueue = (gcnew System::Windows::Forms::TabPage());
			this->tabStack = (gcnew System::Windows::Forms::TabPage());
			this->tabPriorityQueue = (gcnew System::Windows::Forms::TabPage());
			this->tabGraph = (gcnew System::Windows::Forms::TabPage());
			this->tabTree = (gcnew System::Windows::Forms::TabPage());
			this->tabTable = (gcnew System::Windows::Forms::TabPage());
			this->tabSorting = (gcnew System::Windows::Forms::TabPage());
			this->pnlLog->SuspendLayout();
			this->tabsStructures->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnlLog
			// 
			this->pnlLog->Controls->Add(this->lviewLog);
			this->pnlLog->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->pnlLog->Location = System::Drawing::Point(0, 293);
			this->pnlLog->Name = L"pnlLog";
			this->pnlLog->Size = System::Drawing::Size(756, 111);
			this->pnlLog->TabIndex = 2;
			// 
			// lviewLog
			// 
			this->lviewLog->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->lviewLog->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) { this->columnType, this->columnMessage });
			this->lviewLog->Dock = System::Windows::Forms::DockStyle::Fill;
			this->lviewLog->FullRowSelect = true;
			this->lviewLog->GridLines = true;
			this->lviewLog->Location = System::Drawing::Point(0, 0);
			this->lviewLog->Name = L"lviewLog";
			this->lviewLog->Size = System::Drawing::Size(756, 111);
			this->lviewLog->TabIndex = 1;
			this->lviewLog->UseCompatibleStateImageBehavior = false;
			this->lviewLog->View = System::Windows::Forms::View::Details;
			// 
			// columnType
			// 
			this->columnType->Text = L"Type";
			this->columnType->Width = 87;
			// 
			// columnMessage
			// 
			this->columnMessage->Text = L"Message";
			this->columnMessage->Width = 564;
			// 
			// splitterLog
			// 
			this->splitterLog->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->splitterLog->Location = System::Drawing::Point(0, 290);
			this->splitterLog->Name = L"splitterLog";
			this->splitterLog->Size = System::Drawing::Size(756, 3);
			this->splitterLog->TabIndex = 3;
			this->splitterLog->TabStop = false;
			// 
			// tabsStructures
			// 
			this->tabsStructures->Controls->Add(this->tabVector);
			this->tabsStructures->Controls->Add(this->tabArray);
			this->tabsStructures->Controls->Add(this->tabList);
			this->tabsStructures->Controls->Add(this->tabQueue);
			this->tabsStructures->Controls->Add(this->tabStack);
			this->tabsStructures->Controls->Add(this->tabPriorityQueue);
			this->tabsStructures->Controls->Add(this->tabGraph);
			this->tabsStructures->Controls->Add(this->tabTree);
			this->tabsStructures->Controls->Add(this->tabTable);
			this->tabsStructures->Controls->Add(this->tabSorting);
			this->tabsStructures->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabsStructures->Location = System::Drawing::Point(0, 0);
			this->tabsStructures->Name = L"tabsStructures";
			this->tabsStructures->SelectedIndex = 0;
			this->tabsStructures->Size = System::Drawing::Size(756, 290);
			this->tabsStructures->TabIndex = 4;
			// 
			// tabVector
			// 
			this->tabVector->Location = System::Drawing::Point(4, 22);
			this->tabVector->Name = L"tabVector";
			this->tabVector->Padding = System::Windows::Forms::Padding(3);
			this->tabVector->Size = System::Drawing::Size(748, 264);
			this->tabVector->TabIndex = 11;
			this->tabVector->Text = L"Vector";
			this->tabVector->UseVisualStyleBackColor = true;
			// 
			// tabArray
			// 
			this->tabArray->Location = System::Drawing::Point(4, 22);
			this->tabArray->Name = L"tabArray";
			this->tabArray->Padding = System::Windows::Forms::Padding(3);
			this->tabArray->Size = System::Drawing::Size(748, 378);
			this->tabArray->TabIndex = 2;
			this->tabArray->Text = L"Array";
			this->tabArray->UseVisualStyleBackColor = true;
			// 
			// tabList
			// 
			this->tabList->Location = System::Drawing::Point(4, 22);
			this->tabList->Name = L"tabList";
			this->tabList->Padding = System::Windows::Forms::Padding(3);
			this->tabList->Size = System::Drawing::Size(748, 378);
			this->tabList->TabIndex = 3;
			this->tabList->Text = L"List";
			this->tabList->UseVisualStyleBackColor = true;
			// 
			// tabQueue
			// 
			this->tabQueue->Location = System::Drawing::Point(4, 22);
			this->tabQueue->Name = L"tabQueue";
			this->tabQueue->Padding = System::Windows::Forms::Padding(3);
			this->tabQueue->Size = System::Drawing::Size(748, 378);
			this->tabQueue->TabIndex = 4;
			this->tabQueue->Text = L"Queue";
			this->tabQueue->UseVisualStyleBackColor = true;
			// 
			// tabStack
			// 
			this->tabStack->Location = System::Drawing::Point(4, 22);
			this->tabStack->Name = L"tabStack";
			this->tabStack->Padding = System::Windows::Forms::Padding(3);
			this->tabStack->Size = System::Drawing::Size(748, 378);
			this->tabStack->TabIndex = 5;
			this->tabStack->Text = L"Stack";
			this->tabStack->UseVisualStyleBackColor = true;
			// 
			// tabPriorityQueue
			// 
			this->tabPriorityQueue->Location = System::Drawing::Point(4, 22);
			this->tabPriorityQueue->Name = L"tabPriorityQueue";
			this->tabPriorityQueue->Padding = System::Windows::Forms::Padding(3);
			this->tabPriorityQueue->Size = System::Drawing::Size(748, 378);
			this->tabPriorityQueue->TabIndex = 6;
			this->tabPriorityQueue->Text = L"Priority queue";
			this->tabPriorityQueue->UseVisualStyleBackColor = true;
			// 
			// tabGraph
			// 
			this->tabGraph->Location = System::Drawing::Point(4, 22);
			this->tabGraph->Name = L"tabGraph";
			this->tabGraph->Padding = System::Windows::Forms::Padding(3);
			this->tabGraph->Size = System::Drawing::Size(748, 378);
			this->tabGraph->TabIndex = 10;
			this->tabGraph->Text = L"Graph";
			this->tabGraph->UseVisualStyleBackColor = true;
			// 
			// tabTree
			// 
			this->tabTree->Location = System::Drawing::Point(4, 22);
			this->tabTree->Name = L"tabTree";
			this->tabTree->Padding = System::Windows::Forms::Padding(3);
			this->tabTree->Size = System::Drawing::Size(748, 378);
			this->tabTree->TabIndex = 7;
			this->tabTree->Text = L"Tree";
			this->tabTree->UseVisualStyleBackColor = true;
			// 
			// tabTable
			// 
			this->tabTable->Location = System::Drawing::Point(4, 22);
			this->tabTable->Name = L"tabTable";
			this->tabTable->Padding = System::Windows::Forms::Padding(3);
			this->tabTable->Size = System::Drawing::Size(748, 378);
			this->tabTable->TabIndex = 8;
			this->tabTable->Text = L"Table";
			this->tabTable->UseVisualStyleBackColor = true;
			// 
			// tabSorting
			// 
			this->tabSorting->Location = System::Drawing::Point(4, 22);
			this->tabSorting->Name = L"tabSorting";
			this->tabSorting->Padding = System::Windows::Forms::Padding(3);
			this->tabSorting->Size = System::Drawing::Size(748, 378);
			this->tabSorting->TabIndex = 9;
			this->tabSorting->Text = L"Sorting";
			this->tabSorting->UseVisualStyleBackColor = true;
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(756, 404);
			this->Controls->Add(this->tabsStructures);
			this->Controls->Add(this->splitterLog);
			this->Controls->Add(this->pnlLog);
			this->Name = L"FormMain";
			this->Text = L"Datastructures";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->pnlLog->ResumeLayout(false);
			this->tabsStructures->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

};

