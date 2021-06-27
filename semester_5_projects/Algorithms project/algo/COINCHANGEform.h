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
	/// Summary for COINCHANGEform
	/// </summary>
	public ref class COINCHANGEform : public System::Windows::Forms::Form
	{
	public:
		COINCHANGEform(void)
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
		~COINCHANGEform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ outputstring2;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ warning;
	private: System::Windows::Forms::Button^ nextbutton;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ noofinputs;
	private: System::Windows::Forms::Label^ outputlabel;
	private: System::Windows::Forms::Label^ output;
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
			this->outputstring2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->warning = (gcnew System::Windows::Forms::Label());
			this->nextbutton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->noofinputs = (gcnew System::Windows::Forms::Label());
			this->outputlabel = (gcnew System::Windows::Forms::Label());
			this->output = (gcnew System::Windows::Forms::Label());
			this->stringlabel1 = (gcnew System::Windows::Forms::Label());
			this->outputstring1 = (gcnew System::Windows::Forms::Label());
			this->GENERATEbutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// outputstring2
			// 
			this->outputstring2->AutoSize = true;
			this->outputstring2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputstring2->Location = System::Drawing::Point(80, 32);
			this->outputstring2->Name = L"outputstring2";
			this->outputstring2->Size = System::Drawing::Size(180, 17);
			this->outputstring2->TabIndex = 37;
			this->outputstring2->Text = L"press the button please";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(5, 32);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(70, 20);
			this->label3->TabIndex = 36;
			this->label3->Text = L"change :";
			// 
			// warning
			// 
			this->warning->AutoSize = true;
			this->warning->Location = System::Drawing::Point(1143, 185);
			this->warning->Name = L"warning";
			this->warning->Size = System::Drawing::Size(209, 20);
			this->warning->TabIndex = 35;
			this->warning->Text = L"FILE LIMIT NOT REACHED";
			// 
			// nextbutton
			// 
			this->nextbutton->AutoSize = true;
			this->nextbutton->Location = System::Drawing::Point(543, 170);
			this->nextbutton->Name = L"nextbutton";
			this->nextbutton->Size = System::Drawing::Size(116, 38);
			this->nextbutton->TabIndex = 34;
			this->nextbutton->Text = L"READ NEXT";
			this->nextbutton->UseVisualStyleBackColor = true;
			this->nextbutton->Click += gcnew System::EventHandler(this, &COINCHANGEform::nextbutton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 188);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 20);
			this->label2->TabIndex = 33;
			this->label2->Text = L"INPUTS READ:";
			// 
			// noofinputs
			// 
			this->noofinputs->AutoSize = true;
			this->noofinputs->Location = System::Drawing::Point(132, 188);
			this->noofinputs->Name = L"noofinputs";
			this->noofinputs->Size = System::Drawing::Size(18, 20);
			this->noofinputs->TabIndex = 32;
			this->noofinputs->Text = L"0";
			// 
			// outputlabel
			// 
			this->outputlabel->AutoSize = true;
			this->outputlabel->Location = System::Drawing::Point(8, 110);
			this->outputlabel->Name = L"outputlabel";
			this->outputlabel->Size = System::Drawing::Size(67, 20);
			this->outputlabel->TabIndex = 31;
			this->outputlabel->Text = L"output : ";
			// 
			// output
			// 
			this->output->AutoSize = true;
			this->output->Location = System::Drawing::Point(79, 110);
			this->output->Name = L"output";
			this->output->Size = System::Drawing::Size(207, 20);
			this->output->TabIndex = 30;
			this->output->Text = L"output will be displayed here";
			// 
			// stringlabel1
			// 
			this->stringlabel1->AutoSize = true;
			this->stringlabel1->Location = System::Drawing::Point(12, 9);
			this->stringlabel1->Name = L"stringlabel1";
			this->stringlabel1->Size = System::Drawing::Size(62, 20);
			this->stringlabel1->TabIndex = 27;
			this->stringlabel1->Text = L"values :";
			// 
			// outputstring1
			// 
			this->outputstring1->AutoSize = true;
			this->outputstring1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputstring1->Location = System::Drawing::Point(80, 11);
			this->outputstring1->Name = L"outputstring1";
			this->outputstring1->Size = System::Drawing::Size(180, 17);
			this->outputstring1->TabIndex = 26;
			this->outputstring1->Text = L"press the button please";
			// 
			// GENERATEbutton
			// 
			this->GENERATEbutton->AutoSize = true;
			this->GENERATEbutton->Location = System::Drawing::Point(689, 167);
			this->GENERATEbutton->Name = L"GENERATEbutton";
			this->GENERATEbutton->Size = System::Drawing::Size(170, 38);
			this->GENERATEbutton->TabIndex = 38;
			this->GENERATEbutton->Text = L"GENERATE INPUTS";
			this->GENERATEbutton->UseVisualStyleBackColor = true;
			this->GENERATEbutton->Click += gcnew System::EventHandler(this, &COINCHANGEform::GENERATEbutton_Click);
			// 
			// COINCHANGEform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1364, 219);
			this->Controls->Add(this->GENERATEbutton);
			this->Controls->Add(this->outputstring2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->warning);
			this->Controls->Add(this->nextbutton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->noofinputs);
			this->Controls->Add(this->outputlabel);
			this->Controls->Add(this->output);
			this->Controls->Add(this->stringlabel1);
			this->Controls->Add(this->outputstring1);
			this->Name = L"COINCHANGEform";
			this->Text = L"COINCHANGEform";
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
		int count(vector <int> S, int m, int n)
		{
			int i, j, x, y;
			int** table;
			table = new int* [n + 1];
			for (int a = 0; a < n + 1; a++)
				table[a] = new int[m];
 
			for (i = 0; i < m; i++)
				table[0][i] = 1;

			for (i = 1; i < n + 1; i++)
			{
				for (j = 0; j < m; j++)
				{ 
					x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;

					y = (j >= 1) ? table[i][j - 1] : 0;

					table[i][j] = x + y;
				}
			}
			return table[n][m - 1];
		}
private: System::Void nextbutton_Click(System::Object^ sender, System::EventArgs^ e)
	{
	static int counter = 0;
	vector <int> values;
	int answer, change;
	string s1, s2;
	ifstream input;
	input.open("COINCHANGEsample.txt", ios::in);
	for (int a = 0; a <= counter; a++)
	{
		getline(input, s1);
		getline(input, s2);
		outputstring1->Text = gcnew String(s1.c_str());
		outputstring2->Text = gcnew String(s2.c_str());
	}
	values = convertStrtoArr(s1);
	change = stoi(s2);
	answer = count(values,values.size(),change);
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
private: System::Void GENERATEbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		srand(time(NULL));
		int numbers[101];
		for (int s = 0; s <= 100; s++)
			numbers[s] = s;
		ofstream in;
		in.open("COINCHANGEsample.txt", ios::out);
		for (int x = 0; x < 10; x++)
		{
			for (int a = 0; a < 30 + rand() % 70; a++)
			{
				in << numbers[rand() % 100] << ",";
			}
			in << endl << 148;
			if (x == 9)
				continue;
			else
				in << endl;
		}
		in.close();
	}
};
}
