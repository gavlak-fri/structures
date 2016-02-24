#pragma once

#include "PanelStructure.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace UI {

	public ref class PanelQueue : 
		public System::Windows::Forms::UserControl,
		public PanelStructure
	{

	private:
		// DS::Queue* queue_;
	public:
		PanelQueue(void);

		virtual void initialize(DS::Structure* structure);
		virtual void finalize();
		virtual void enableControls(bool value);

		virtual void show();
		virtual void hide();
		virtual void dockFill();

	protected:
		~PanelQueue();

	private:
		PanelStructureUpdater^ updater_;

	private: System::Windows::Forms::FlowLayoutPanel^  pnlQueue;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pnlQueue = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->SuspendLayout();
			// 
			// pnlQueue
			// 
			this->pnlQueue->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->pnlQueue->Dock = System::Windows::Forms::DockStyle::Top;
			this->pnlQueue->Location = System::Drawing::Point(0, 0);
			this->pnlQueue->Name = L"pnlQueue";
			this->pnlQueue->Size = System::Drawing::Size(248, 30);
			this->pnlQueue->TabIndex = 0;
			// 
			// PanelQueue
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->pnlQueue);
			this->Name = L"PanelQueue";
			this->Size = System::Drawing::Size(248, 150);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
