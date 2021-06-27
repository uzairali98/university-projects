#pragma once
#include "LCSform1.h"
#include "SCSform.h"
#include "EDform.h"
#include "LISform.h"
#include "MCMform.h"
#include "KNAPSACKform.h"
#include "PRATITIONPROBLEMform.h"
#include "RODCUTTINGform.h"
#include "COINCHANGEform.h"
#include "WORDBREAKform.h"
#include "HELPform.h"
namespace algo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for mainform
	/// </summary>
	public ref class mainform : public System::Windows::Forms::Form
	{
	public:
		mainform(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mainform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ Welcomelabel;

	protected:


	private: System::Windows::Forms::Button^ LCSbutton;
	private: System::Windows::Forms::Label^ LCSdesc;
	private: System::Windows::Forms::Button^ SCSbutton;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ editdistancebutton;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ LISbutton;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ MCMbutton;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ KNAPSACKbutton;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ PARTITIONPROBLEMbutton;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ RODCUTTINGbutton;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ COINCHANGEbutton;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ WORDBREAKbutton;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ HELPbutton;




	protected:

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
			this->Welcomelabel = (gcnew System::Windows::Forms::Label());
			this->LCSbutton = (gcnew System::Windows::Forms::Button());
			this->LCSdesc = (gcnew System::Windows::Forms::Label());
			this->SCSbutton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->editdistancebutton = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->LISbutton = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->MCMbutton = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->KNAPSACKbutton = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->PARTITIONPROBLEMbutton = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->RODCUTTINGbutton = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->COINCHANGEbutton = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->WORDBREAKbutton = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->HELPbutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Welcomelabel
			// 
			this->Welcomelabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Welcomelabel->Location = System::Drawing::Point(111, 9);
			this->Welcomelabel->Name = L"Welcomelabel";
			this->Welcomelabel->Size = System::Drawing::Size(416, 46);
			this->Welcomelabel->TabIndex = 0;
			this->Welcomelabel->Text = L"WELCOME TO ALGO PROJECT";
			this->Welcomelabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// LCSbutton
			// 
			this->LCSbutton->Location = System::Drawing::Point(27, 76);
			this->LCSbutton->Name = L"LCSbutton";
			this->LCSbutton->Size = System::Drawing::Size(75, 42);
			this->LCSbutton->TabIndex = 2;
			this->LCSbutton->Text = L"LCS";
			this->LCSbutton->UseVisualStyleBackColor = true;
			this->LCSbutton->Click += gcnew System::EventHandler(this, &mainform::LCSbutton_Click);
			// 
			// LCSdesc
			// 
			this->LCSdesc->AutoSize = true;
			this->LCSdesc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LCSdesc->Location = System::Drawing::Point(125, 87);
			this->LCSdesc->Name = L"LCSdesc";
			this->LCSdesc->Size = System::Drawing::Size(389, 20);
			this->LCSdesc->TabIndex = 3;
			this->LCSdesc->Text = L"press this to run Longest common substring Algorithm\r\n";
			// 
			// SCSbutton
			// 
			this->SCSbutton->Location = System::Drawing::Point(27, 136);
			this->SCSbutton->Name = L"SCSbutton";
			this->SCSbutton->Size = System::Drawing::Size(75, 42);
			this->SCSbutton->TabIndex = 4;
			this->SCSbutton->Text = L"SCS";
			this->SCSbutton->UseVisualStyleBackColor = true;
			this->SCSbutton->Click += gcnew System::EventHandler(this, &mainform::SCSbutton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(125, 147);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(392, 20);
			this->label1->TabIndex = 5;
			this->label1->Text = L"press this to run Shortest common substring Algorithm";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(125, 209);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(387, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"press this to run Edit distance of two strings Algorithm";
			// 
			// editdistancebutton
			// 
			this->editdistancebutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editdistancebutton->Location = System::Drawing::Point(27, 198);
			this->editdistancebutton->Name = L"editdistancebutton";
			this->editdistancebutton->Size = System::Drawing::Size(75, 50);
			this->editdistancebutton->TabIndex = 6;
			this->editdistancebutton->Text = L"EDIT DISTANCE";
			this->editdistancebutton->UseVisualStyleBackColor = true;
			this->editdistancebutton->Click += gcnew System::EventHandler(this, &mainform::editdistancebutton_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(125, 279);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(431, 20);
			this->label3->TabIndex = 9;
			this->label3->Text = L"press this to run Longest increasing subsequence Algorithm";
			// 
			// LISbutton
			// 
			this->LISbutton->Location = System::Drawing::Point(27, 268);
			this->LISbutton->Name = L"LISbutton";
			this->LISbutton->Size = System::Drawing::Size(75, 42);
			this->LISbutton->TabIndex = 8;
			this->LISbutton->Text = L"LIS";
			this->LISbutton->UseVisualStyleBackColor = true;
			this->LISbutton->Click += gcnew System::EventHandler(this, &mainform::LISbutton_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(125, 336);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(379, 20);
			this->label4->TabIndex = 11;
			this->label4->Text = L"press this to run Matrix Chain Multiplication Algorithm";
			// 
			// MCMbutton
			// 
			this->MCMbutton->Location = System::Drawing::Point(27, 325);
			this->MCMbutton->Name = L"MCMbutton";
			this->MCMbutton->Size = System::Drawing::Size(75, 42);
			this->MCMbutton->TabIndex = 10;
			this->MCMbutton->Text = L"MCM";
			this->MCMbutton->UseVisualStyleBackColor = true;
			this->MCMbutton->Click += gcnew System::EventHandler(this, &mainform::MCMbutton_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(125, 393);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(296, 20);
			this->label5->TabIndex = 13;
			this->label5->Text = L"press this to run 0/1 KnapSack Algorithm";
			// 
			// KNAPSACKbutton
			// 
			this->KNAPSACKbutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->KNAPSACKbutton->Location = System::Drawing::Point(27, 382);
			this->KNAPSACKbutton->Name = L"KNAPSACKbutton";
			this->KNAPSACKbutton->Size = System::Drawing::Size(75, 50);
			this->KNAPSACKbutton->TabIndex = 12;
			this->KNAPSACKbutton->Text = L"0/1 KnpSac";
			this->KNAPSACKbutton->UseVisualStyleBackColor = true;
			this->KNAPSACKbutton->Click += gcnew System::EventHandler(this, &mainform::KNAPSACKbutton_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(125, 460);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(317, 20);
			this->label6->TabIndex = 15;
			this->label6->Text = L"press this to run Paritiron Probelm Algorithm";
			// 
			// PARTITIONPROBLEMbutton
			// 
			this->PARTITIONPROBLEMbutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->PARTITIONPROBLEMbutton->Location = System::Drawing::Point(27, 449);
			this->PARTITIONPROBLEMbutton->Name = L"PARTITIONPROBLEMbutton";
			this->PARTITIONPROBLEMbutton->Size = System::Drawing::Size(75, 50);
			this->PARTITIONPROBLEMbutton->TabIndex = 14;
			this->PARTITIONPROBLEMbutton->Text = L"Partition Problem";
			this->PARTITIONPROBLEMbutton->UseVisualStyleBackColor = true;
			this->PARTITIONPROBLEMbutton->Click += gcnew System::EventHandler(this, &mainform::PARTITIONPROBLEMbutton_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(125, 526);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(282, 20);
			this->label7->TabIndex = 17;
			this->label7->Text = L"press this to run Rod Cutting Algorithm";
			// 
			// RODCUTTINGbutton
			// 
			this->RODCUTTINGbutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RODCUTTINGbutton->Location = System::Drawing::Point(27, 515);
			this->RODCUTTINGbutton->Name = L"RODCUTTINGbutton";
			this->RODCUTTINGbutton->Size = System::Drawing::Size(75, 50);
			this->RODCUTTINGbutton->TabIndex = 16;
			this->RODCUTTINGbutton->Text = L"Rod Cutting";
			this->RODCUTTINGbutton->UseVisualStyleBackColor = true;
			this->RODCUTTINGbutton->Click += gcnew System::EventHandler(this, &mainform::RODCUTTINGbutton_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(125, 593);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(289, 20);
			this->label8->TabIndex = 19;
			this->label8->Text = L"press this to run Coin Change Algorithm";
			// 
			// COINCHANGEbutton
			// 
			this->COINCHANGEbutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->COINCHANGEbutton->Location = System::Drawing::Point(27, 582);
			this->COINCHANGEbutton->Name = L"COINCHANGEbutton";
			this->COINCHANGEbutton->Size = System::Drawing::Size(75, 50);
			this->COINCHANGEbutton->TabIndex = 18;
			this->COINCHANGEbutton->Text = L"Coin Change";
			this->COINCHANGEbutton->UseVisualStyleBackColor = true;
			this->COINCHANGEbutton->Click += gcnew System::EventHandler(this, &mainform::COINCHANGEbutton_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(125, 666);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(281, 20);
			this->label9->TabIndex = 21;
			this->label9->Text = L"press this to run Word Break Algorithm";
			// 
			// WORDBREAKbutton
			// 
			this->WORDBREAKbutton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->WORDBREAKbutton->Location = System::Drawing::Point(27, 655);
			this->WORDBREAKbutton->Name = L"WORDBREAKbutton";
			this->WORDBREAKbutton->Size = System::Drawing::Size(75, 50);
			this->WORDBREAKbutton->TabIndex = 20;
			this->WORDBREAKbutton->Text = L"Word Break";
			this->WORDBREAKbutton->UseVisualStyleBackColor = true;
			this->WORDBREAKbutton->Click += gcnew System::EventHandler(this, &mainform::WORDBREAKbutton_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(380, 805);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(252, 20);
			this->label10->TabIndex = 22;
			this->label10->Text = L"Made By : k18-1148 and k17-3786";
			// 
			// HELPbutton
			// 
			this->HELPbutton->AutoSize = true;
			this->HELPbutton->Location = System::Drawing::Point(298, 760);
			this->HELPbutton->Name = L"HELPbutton";
			this->HELPbutton->Size = System::Drawing::Size(75, 37);
			this->HELPbutton->TabIndex = 23;
			this->HELPbutton->Text = L"HELP";
			this->HELPbutton->UseVisualStyleBackColor = true;
			this->HELPbutton->Click += gcnew System::EventHandler(this, &mainform::HELPbutton_Click);
			// 
			// mainform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(644, 832);
			this->Controls->Add(this->HELPbutton);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->WORDBREAKbutton);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->COINCHANGEbutton);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->RODCUTTINGbutton);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->PARTITIONPROBLEMbutton);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->KNAPSACKbutton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->MCMbutton);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->LISbutton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->editdistancebutton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->SCSbutton);
			this->Controls->Add(this->LCSdesc);
			this->Controls->Add(this->LCSbutton);
			this->Controls->Add(this->Welcomelabel);
			this->Name = L"mainform";
			this->Text = L"mainform";
			this->Load += gcnew System::EventHandler(this, &mainform::mainform_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LCSbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		LCSform^ f1 = gcnew  LCSform;
		f1->ShowDialog();
	}
	private: System::Void mainform_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void SCSbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		SCSform^ f2 = gcnew  SCSform;
		f2->ShowDialog();
	}
private: System::Void editdistancebutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		EDform^ f3 = gcnew EDform;
		f3->ShowDialog();
	}
private: System::Void LISbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		LISform^ f4 = gcnew LISform;
		f4->ShowDialog();
	}
private: System::Void MCMbutton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MCMform^ f5 = gcnew MCMform;
		f5->ShowDialog();
	}
private: System::Void KNAPSACKbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		KNAPSACKform^ f6 = gcnew KNAPSACKform;
		f6->ShowDialog();
	}
private: System::Void PARTITIONPROBLEMbutton_Click(System::Object^ sender, System::EventArgs^ e) 
    {
		PRATITIONPROBLEMform^ f7 = gcnew PRATITIONPROBLEMform;
		f7->ShowDialog();
	}
private: System::Void RODCUTTINGbutton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		RODCUTTINGform^ f8 = gcnew RODCUTTINGform;
		f8->ShowDialog();
	}
private: System::Void COINCHANGEbutton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		COINCHANGEform^ f9 = gcnew COINCHANGEform;
		f9->ShowDialog();
	}
private: System::Void WORDBREAKbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		WORDBREAKform^ f10 = gcnew WORDBREAKform;
		f10->ShowDialog();
	}
private: System::Void HELPbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		HELPform^ hf = gcnew HELPform;
		hf->ShowDialog();
}
};
}
