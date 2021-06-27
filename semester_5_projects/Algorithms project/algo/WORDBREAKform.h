#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
namespace algo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for WORDBREAKform
	/// </summary>
	public ref class WORDBREAKform : public System::Windows::Forms::Form
	{
	public:
		WORDBREAKform(void)
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
		~WORDBREAKform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ warning;
	protected:
	private: System::Windows::Forms::Button^ nextbutton;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ noofinputs;
	private: System::Windows::Forms::Label^ outputlabel;
	private: System::Windows::Forms::Label^ output;
	private: System::Windows::Forms::Label^ outputstring2;
	private: System::Windows::Forms::Label^ stringlabel2;
	private: System::Windows::Forms::Label^ stringlabel1;
	private: System::Windows::Forms::Label^ outputstring1;
	private: System::Windows::Forms::Button^ GENERATEbutton;

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
			this->warning = (gcnew System::Windows::Forms::Label());
			this->nextbutton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->noofinputs = (gcnew System::Windows::Forms::Label());
			this->outputlabel = (gcnew System::Windows::Forms::Label());
			this->output = (gcnew System::Windows::Forms::Label());
			this->outputstring2 = (gcnew System::Windows::Forms::Label());
			this->stringlabel2 = (gcnew System::Windows::Forms::Label());
			this->stringlabel1 = (gcnew System::Windows::Forms::Label());
			this->outputstring1 = (gcnew System::Windows::Forms::Label());
			this->GENERATEbutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// warning
			// 
			this->warning->AutoSize = true;
			this->warning->Location = System::Drawing::Point(1091, 185);
			this->warning->Name = L"warning";
			this->warning->Size = System::Drawing::Size(209, 20);
			this->warning->TabIndex = 23;
			this->warning->Text = L"FILE LIMIT NOT REACHED";
			// 
			// nextbutton
			// 
			this->nextbutton->AutoSize = true;
			this->nextbutton->Location = System::Drawing::Point(499, 167);
			this->nextbutton->Name = L"nextbutton";
			this->nextbutton->Size = System::Drawing::Size(116, 38);
			this->nextbutton->TabIndex = 22;
			this->nextbutton->Text = L"READ NEXT";
			this->nextbutton->UseVisualStyleBackColor = true;
			this->nextbutton->Click += gcnew System::EventHandler(this, &WORDBREAKform::nextbutton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 188);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 20);
			this->label2->TabIndex = 21;
			this->label2->Text = L"INPUTS READ:";
			// 
			// noofinputs
			// 
			this->noofinputs->AutoSize = true;
			this->noofinputs->Location = System::Drawing::Point(139, 188);
			this->noofinputs->Name = L"noofinputs";
			this->noofinputs->Size = System::Drawing::Size(18, 20);
			this->noofinputs->TabIndex = 20;
			this->noofinputs->Text = L"0";
			// 
			// outputlabel
			// 
			this->outputlabel->AutoSize = true;
			this->outputlabel->Location = System::Drawing::Point(15, 100);
			this->outputlabel->Name = L"outputlabel";
			this->outputlabel->Size = System::Drawing::Size(67, 20);
			this->outputlabel->TabIndex = 19;
			this->outputlabel->Text = L"output : ";
			// 
			// output
			// 
			this->output->AutoSize = true;
			this->output->Location = System::Drawing::Point(86, 100);
			this->output->Name = L"output";
			this->output->Size = System::Drawing::Size(207, 20);
			this->output->TabIndex = 18;
			this->output->Text = L"output will be displayed here";
			// 
			// outputstring2
			// 
			this->outputstring2->AutoSize = true;
			this->outputstring2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputstring2->Location = System::Drawing::Point(87, 44);
			this->outputstring2->Name = L"outputstring2";
			this->outputstring2->Size = System::Drawing::Size(180, 17);
			this->outputstring2->TabIndex = 17;
			this->outputstring2->Text = L"press the button please";
			// 
			// stringlabel2
			// 
			this->stringlabel2->AutoSize = true;
			this->stringlabel2->Location = System::Drawing::Point(12, 42);
			this->stringlabel2->Name = L"stringlabel2";
			this->stringlabel2->Size = System::Drawing::Size(69, 20);
			this->stringlabel2->TabIndex = 16;
			this->stringlabel2->Text = L"string 2 :";
			// 
			// stringlabel1
			// 
			this->stringlabel1->AutoSize = true;
			this->stringlabel1->Location = System::Drawing::Point(12, 9);
			this->stringlabel1->Name = L"stringlabel1";
			this->stringlabel1->Size = System::Drawing::Size(69, 20);
			this->stringlabel1->TabIndex = 15;
			this->stringlabel1->Text = L"string 1 :";
			// 
			// outputstring1
			// 
			this->outputstring1->AutoSize = true;
			this->outputstring1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputstring1->Location = System::Drawing::Point(87, 11);
			this->outputstring1->Name = L"outputstring1";
			this->outputstring1->Size = System::Drawing::Size(180, 17);
			this->outputstring1->TabIndex = 14;
			this->outputstring1->Text = L"press the button please";
			// 
			// GENERATEbutton
			// 
			this->GENERATEbutton->AutoSize = true;
			this->GENERATEbutton->Location = System::Drawing::Point(641, 167);
			this->GENERATEbutton->Name = L"GENERATEbutton";
			this->GENERATEbutton->Size = System::Drawing::Size(159, 38);
			this->GENERATEbutton->TabIndex = 24;
			this->GENERATEbutton->Text = L"GENERATE INPUT";
			this->GENERATEbutton->UseVisualStyleBackColor = true;
			this->GENERATEbutton->Click += gcnew System::EventHandler(this, &WORDBREAKform::GENERATEbutton_Click);
			// 
			// WORDBREAKform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1312, 214);
			this->Controls->Add(this->GENERATEbutton);
			this->Controls->Add(this->warning);
			this->Controls->Add(this->nextbutton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->noofinputs);
			this->Controls->Add(this->outputlabel);
			this->Controls->Add(this->output);
			this->Controls->Add(this->outputstring2);
			this->Controls->Add(this->stringlabel2);
			this->Controls->Add(this->stringlabel1);
			this->Controls->Add(this->outputstring1);
			this->Name = L"WORDBREAKform";
			this->Text = L"WORDBREAKform";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		bool wordBreak(vector<string> const& dict, string str)
		{
			if (str.size() == 0)
				return true;

			for (int i = 1; i <= str.size(); i++)
			{
				string prefix = str.substr(0, i);

				if (find(dict.begin(), dict.end(), prefix) != dict.end() && wordBreak(dict, str.substr(i)))
					return true;
			}
			return false;
		}
	private: System::Void nextbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		static int counter = 0;
		int answer;
		vector <string> words;
		string s1, s2, temp;
		ifstream input;
		input.open("WORDBREAKsample.txt", ios::in);
		for (int a = 0; a <= counter; a++)
		{
			getline(input, s1);
			getline(input, s2);
			outputstring1->Text = gcnew String(s1.c_str());
			outputstring2->Text = gcnew String(s2.c_str());
		}

		for (int a = 0; a < s1.length(); a++)
		{
			if (s1[a] == ',')
			{
				words.push_back(temp);
				temp.clear();
			}
			else
				temp.push_back(s1[a]);
		}
		
		if (wordBreak(words,s2))
		{
			output->Text = " yes! The string can be segmented ";
		}
		else
		{
			output->Text = " NO! The string cannot be segmented ";
		}
		if (input.eof())
		{
			nextbutton->Enabled = false;
			warning->Text = "INPUT SAMPLES FINISHED";
			input.close();
		}
		counter++;
		noofinputs->Text = Convert::ToString(counter);
	}
private: System::Void GENERATEbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
	srand(time(NULL));
	string name = "abcdefghijklmnopqrstuvwxyz";
	string generated;
	ofstream in;
	in.open("WORDBREAKsample.txt", ios::out);
	for (int x = 0; x < 10; x++)
	{
		for (int b = 0; b < 30+rand()%20; b++)
		{
			for (int a = 0; a < 1+rand() %5; a++)
			{
				generated.push_back(name[rand() % (name.length() - 1)]);
			}
			in << generated <<",";
			generated.clear();
		}
		if (x != 9)
		{
			in << endl;
			in << "mirzamuhammaduzairali";
			in << endl;
		}
		else
		{
			in << endl;
			in << "mirzamuhammaduzairali";
		}

	}
	in.close();
	}
};
}
