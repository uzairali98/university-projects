#pragma once
#include <algorithm>
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
	/// Summary for MCMform
	/// </summary>
	public ref class MCMform : public System::Windows::Forms::Form
	{
	public:
		MCMform(void)
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
		~MCMform()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Button^ nextbutton;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ noofinputs;
	private: System::Windows::Forms::Label^ outputlabel;
	private: System::Windows::Forms::Label^ output;
	private: System::Windows::Forms::Label^ stringlabel1;
	private: System::Windows::Forms::Label^ outputstring1;
	private: System::Windows::Forms::Label^ warning;
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
			this->nextbutton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->noofinputs = (gcnew System::Windows::Forms::Label());
			this->outputlabel = (gcnew System::Windows::Forms::Label());
			this->output = (gcnew System::Windows::Forms::Label());
			this->stringlabel1 = (gcnew System::Windows::Forms::Label());
			this->outputstring1 = (gcnew System::Windows::Forms::Label());
			this->warning = (gcnew System::Windows::Forms::Label());
			this->GENERATEbutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// nextbutton
			// 
			this->nextbutton->AutoSize = true;
			this->nextbutton->Location = System::Drawing::Point(515, 209);
			this->nextbutton->Name = L"nextbutton";
			this->nextbutton->Size = System::Drawing::Size(116, 38);
			this->nextbutton->TabIndex = 28;
			this->nextbutton->Text = L"READ NEXT";
			this->nextbutton->UseVisualStyleBackColor = true;
			this->nextbutton->Click += gcnew System::EventHandler(this, &MCMform::nextbutton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(11, 227);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 20);
			this->label2->TabIndex = 27;
			this->label2->Text = L"INPUTS READ:";
			// 
			// noofinputs
			// 
			this->noofinputs->AutoSize = true;
			this->noofinputs->Location = System::Drawing::Point(138, 227);
			this->noofinputs->Name = L"noofinputs";
			this->noofinputs->Size = System::Drawing::Size(18, 20);
			this->noofinputs->TabIndex = 26;
			this->noofinputs->Text = L"0";
			// 
			// outputlabel
			// 
			this->outputlabel->AutoSize = true;
			this->outputlabel->Location = System::Drawing::Point(11, 57);
			this->outputlabel->Name = L"outputlabel";
			this->outputlabel->Size = System::Drawing::Size(67, 20);
			this->outputlabel->TabIndex = 25;
			this->outputlabel->Text = L"output : ";
			// 
			// output
			// 
			this->output->AutoSize = true;
			this->output->Location = System::Drawing::Point(82, 57);
			this->output->Name = L"output";
			this->output->Size = System::Drawing::Size(207, 20);
			this->output->TabIndex = 24;
			this->output->Text = L"output will be displayed here";
			// 
			// stringlabel1
			// 
			this->stringlabel1->AutoSize = true;
			this->stringlabel1->Location = System::Drawing::Point(21, 27);
			this->stringlabel1->Name = L"stringlabel1";
			this->stringlabel1->Size = System::Drawing::Size(56, 20);
			this->stringlabel1->TabIndex = 23;
			this->stringlabel1->Text = L"input : ";
			// 
			// outputstring1
			// 
			this->outputstring1->AutoSize = true;
			this->outputstring1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputstring1->Location = System::Drawing::Point(83, 29);
			this->outputstring1->Name = L"outputstring1";
			this->outputstring1->Size = System::Drawing::Size(180, 17);
			this->outputstring1->TabIndex = 22;
			this->outputstring1->Text = L"press the button please";
			// 
			// warning
			// 
			this->warning->AutoSize = true;
			this->warning->Location = System::Drawing::Point(1309, 227);
			this->warning->Name = L"warning";
			this->warning->Size = System::Drawing::Size(209, 20);
			this->warning->TabIndex = 29;
			this->warning->Text = L"FILE LIMIT NOT REACHED";
			// 
			// GENERATEbutton
			// 
			this->GENERATEbutton->AutoSize = true;
			this->GENERATEbutton->Location = System::Drawing::Point(799, 209);
			this->GENERATEbutton->Name = L"GENERATEbutton";
			this->GENERATEbutton->Size = System::Drawing::Size(172, 38);
			this->GENERATEbutton->TabIndex = 30;
			this->GENERATEbutton->Text = L"GENERATE INPUTS";
			this->GENERATEbutton->UseVisualStyleBackColor = true;
			this->GENERATEbutton->Click += gcnew System::EventHandler(this, &MCMform::GENERATEbutton_Click);
			// 
			// MCMform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1530, 259);
			this->Controls->Add(this->GENERATEbutton);
			this->Controls->Add(this->warning);
			this->Controls->Add(this->nextbutton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->noofinputs);
			this->Controls->Add(this->outputlabel);
			this->Controls->Add(this->output);
			this->Controls->Add(this->stringlabel1);
			this->Controls->Add(this->outputstring1);
			this->Name = L"MCMform";
			this->Text = L"MCMform";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int MatrixChainOrder(vector <int> p, int n)
		{
			int** m;
			m = new int* [n];
			for (int a = 0; a < n; a++)
				m[a] = new int[n];

			int i, j, k, L, q;

			for (i = 1; i < n; i++)
				m[i][i] = 0;

			for (L = 2; L < n; L++)
			{
				for (i = 1; i < n - L + 1; i++)
				{
					j = i + L - 1;
					m[i][j] = INT_MAX;
					for (k = i; k <= j - 1; k++)
					{
						// q = cost/scalar multiplications 
						q = m[i][k] + m[k + 1][j]
							+ p[i - 1] * p[k] * p[j];
						if (q < m[i][j])
							m[i][j] = q;
					}
				}
			}

			return m[1][n - 1];
		}
		vector <int> convertStrtoArr(string str)
		{
			vector <int> arr;
			int a = 0,temp = str.length();
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
	private: System::Void nextbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		static int counter = 0;
		vector <int> array;
		int answer;
		string s1;
		ifstream input;
		input.open("MCMsample.txt", ios::in);
		for (int a = 0; a <= counter; a++)
		{
			getline(input, s1);
			outputstring1->Text = gcnew String(s1.c_str());
		}
		array = convertStrtoArr(s1);
		answer = MatrixChainOrder(array, array.size());
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
	in.open("MCMsample.txt", ios::out);
	for (int x = 0; x < 10; x++)
	{
		for (int a = 0; a < 30 + rand() % 70; a++)
		{
			in << numbers[rand() % 100] << ",";
		}
		if (x == 9)
			continue;
		else
			in << endl;
	}
	in.close();
	}
};
}
