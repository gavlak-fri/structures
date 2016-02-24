#pragma once

#include "PanelStructure.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace UI {

	public ref class PanelPriorityQueue : 
		public System::Windows::Forms::UserControl,
		public PanelStructure
	{
	private:
		//DS::PriorityQueue<UI::UserData::DataType>* priorityQueue_;
	public:
		PanelPriorityQueue(void);

		virtual void initialize(DS::Structure* structure);
		virtual void finalize();
		virtual void enableControls(bool value);

		virtual void show();
		virtual void hide();
		virtual void dockFill();

	protected:
		~PanelPriorityQueue();

	private:
		PanelStructureUpdater^ updater_;

	private: System::Windows::Forms::FlowLayoutPanel^  pnlPriorityQueue;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnlPriorityQueue = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// pnlPriorityQueue
			// 
			this->pnlPriorityQueue->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->pnlPriorityQueue->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlPriorityQueue->Location = System::Drawing::Point(0, 0);
			this->pnlPriorityQueue->Name = L"pnlPriorityQueue";
			this->pnlPriorityQueue->Size = System::Drawing::Size(269, 30);
			this->pnlPriorityQueue->TabIndex = 0;
			// 
			// PanelPriorityQueue
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->pnlPriorityQueue);
			this->Name = L"PanelPriorityQueue";
			this->Size = System::Drawing::Size(269, 181);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
