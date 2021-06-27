#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
namespace algo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for RODCUTTINGform
	/// </summary>
	public ref class RODCUTTINGform : public System::Windows::Forms::Form
	{
	public:
		RODCUTTINGform(void)
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
		~RODCUTTINGform()
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
	private: System::Windows::Forms::Label^ outputstring1;
	private: System::Windows::Forms::Label^ stringlabel2;
	private: System::Windows::Forms::Label^ outputstring2;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ outputstring3;
	private: System::Windows::Forms::Label^ label4;

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
			this->outputstring1 = (gcnew System::Windows::Forms::Label());
			this->stringlabel2 = (gcnew System::Windows::Forms::Label());
			this->outputstring2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->outputstring3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// warning
			// 
			this->warning->AutoSize = true;
			this->warning->Location = System::Drawing::Point(659, 187);
			this->warning->Name = L"warning";
			this->warning->Size = System::Drawing::Size(209, 20);
			this->warning->TabIndex = 31;
			this->warning->Text = L"FILE LIMIT NOT REACHED";
			// 
			// nextbutton
			// 
			this->nextbutton->AutoSize = true;
			this->nextbutton->Location = System::Drawing::Point(389, 169);
			this->nextbutton->Name = L"nextbutton";
			this->nextbutton->Size = System::Drawing::Size(116, 38);
			this->nextbutton->TabIndex = 30;
			this->nextbutton->Text = L"READ NEXT";
			this->nextbutton->UseVisualStyleBackColor = true;
			this->nextbutton->Click += gcnew System::EventHandler(this, &RODCUTTINGform::nextbutton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 190);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 20);
			this->label2->TabIndex = 29;
			this->label2->Text = L"INPUTS READ:";
			// 
			// noofinputs
			// 
			this->noofinputs->AutoSize = true;
			this->noofinputs->Location = System::Drawing::Point(139, 190);
			this->noofinputs->Name = L"noofinputs";
			this->noofinputs->Size = System::Drawing::Size(18, 20);
			this->noofinputs->TabIndex = 28;
			this->noofinputs->Text = L"0";
			// 
			// outputlabel
			// 
			this->outputlabel->AutoSize = true;
			this->outputlabel->Location = System::Drawing::Point(16, 85);
			this->outputlabel->Name = L"outputlabel";
			this->outputlabel->Size = System::Drawing::Size(67, 20);
			this->outputlabel->TabIndex = 27;
			this->outputlabel->Text = L"output : ";
			// 
			// output
			// 
			this->output->AutoSize = true;
			this->output->Location = System::Drawing::Point(89, 85);
			this->output->Name = L"output";
			this->output->Size = System::Drawing::Size(207, 20);
			this->output->TabIndex = 26;
			this->output->Text = L"output will be displayed here";
			// 
			// outputstring1
			// 
			this->outputstring1->AutoSize = true;
			this->outputstring1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputstring1->Location = System::Drawing::Point(86, 11);
			this->outputstring1->Name = L"outputstring1";
			this->outputstring1->Size = System::Drawing::Size(180, 17);
			this->outputstring1->TabIndex = 25;
			this->outputstring1->Text = L"press the button please";
			// 
			// stringlabel2
			// 
			this->stringlabel2->AutoSize = true;
			this->stringlabel2->Location = System::Drawing::Point(16, 31);
			this->stringlabel2->Name = L"stringlabel2";
			this->stringlabel2->Size = System::Drawing::Size(62, 20);
			this->stringlabel2->TabIndex = 24;
			this->stringlabel2->Text = L"values :";
			// 
			// outputstring2
			// 
			this->outputstring2->AutoSize = true;
			this->outputstring2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputstring2->Location = System::Drawing::Point(86, 32);
			this->outputstring2->Name = L"outputstring2";
			this->outputstring2->Size = System::Drawing::Size(180, 17);
			this->outputstring2->TabIndex = 33;
			this->outputstring2->Text = L"press the button please";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(11, 11);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 20);
			this->label3->TabIndex = 32;
			this->label3->Text = L"lengths :";
			// 
			// outputstring3
			// 
			this->outputstring3->AutoSize = true;
			this->outputstring3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputstring3->Location = System::Drawing::Point(115, 51);
			this->outputstring3->Name = L"outputstring3";
			this->outputstring3->Size = System::Drawing::Size(180, 17);
			this->outputstring3->TabIndex = 35;
			this->outputstring3->Text = L"press the button please";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 49);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(97, 20);
			this->label4->TabIndex = 34;
			this->label4->Text = L"Rod Length:";
			// 
			// RODCUTTINGform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(877, 222);
			this->Controls->Add(this->outputstring3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->outputstring2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->warning);
			this->Controls->Add(this->nextbutton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->noofinputs);
			this->Controls->Add(this->outputlabel);
			this->Controls->Add(this->output);
			this->Controls->Add(this->outputstring1);
			this->Controls->Add(this->stringlabel2);
			this->Name = L"RODCUTTINGform";
			this->Text = L"RODCUTTINGform";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		vector <int> convertStrtoArr(string str)
		{
			vector <int> arr;
			int a = 0, temp = str.length();
			int j = 0, i, sum = 0;

			for (i = 0; i < temp; i++)
			{
				if (str[i] == ',')
				{
					arr.push_back(a);
					a = 0;
					continue;
				}
				else {
					a = a * 10 + (str[i] - 48);
				}
			}
			return arr;
		}
		int rodCut(vector <int> price, int n)
		{
			int* T;
			T = new int[n + 1];
			for (int i = 0; i <= n; i++)
				T[i] = 0;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= i; j++)
					T[i] = max(T[i], price[j - 1] + T[i - j]);
			}
			return T[n];
		}
	private: System::Void nextbutton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		static int counter = 0;
		vector <int> array;
		int answer,rl;
		string lengths,values,RL;
		ifstream input;
		input.open("RODCUTTINGsample.txt", ios::in);
		for (int a = 0; a <= counter; a++)
		{
			getline(input, lengths);
			getline(input, values);
			getline(input, RL);
			outputstring1->Text = gcnew String(lengths.c_str());
			outputstring2->Text = gcnew String(values.c_str());
			outputstring3->Text = gcnew String(RL.c_str());
		}
		array = convertStrtoArr(values);
		rl = stoi(RL);
		answer = rodCut(array,array.size()); 
		output->Text = Convert::ToString(answer);

		if (input.eof())
		{
			nextbutton->Enabled = false;
			warning->Text = "INPUT SAMPLES FINISHED";
			input.close();
		}
		counter++;
		noofinputs->Text = Convert::ToString(counter);
	}
};
}
