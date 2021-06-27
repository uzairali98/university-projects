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
	/// Summary for PRATITIONPROBLEMform
	/// </summary>
	public ref class PRATITIONPROBLEMform : public System::Windows::Forms::Form
	{
	public:
		PRATITIONPROBLEMform(void)
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
		~PRATITIONPROBLEMform()
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
			this->outputstring1 = (gcnew System::Windows::Forms::Label());
			this->stringlabel2 = (gcnew System::Windows::Forms::Label());
			this->GENERATEbutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// warning
			// 
			this->warning->AutoSize = true;
			this->warning->Location = System::Drawing::Point(1312, 185);
			this->warning->Name = L"warning";
			this->warning->Size = System::Drawing::Size(209, 20);
			this->warning->TabIndex = 23;
			this->warning->Text = L"FILE LIMIT NOT REACHED";
			// 
			// nextbutton
			// 
			this->nextbutton->AutoSize = true;
			this->nextbutton->Location = System::Drawing::Point(541, 167);
			this->nextbutton->Name = L"nextbutton";
			this->nextbutton->Size = System::Drawing::Size(116, 38);
			this->nextbutton->TabIndex = 22;
			this->nextbutton->Text = L"READ NEXT";
			this->nextbutton->UseVisualStyleBackColor = true;
			this->nextbutton->Click += gcnew System::EventHandler(this, &PRATITIONPROBLEMform::nextbutton_Click);
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
			this->outputlabel->Location = System::Drawing::Point(12, 64);
			this->outputlabel->Name = L"outputlabel";
			this->outputlabel->Size = System::Drawing::Size(67, 20);
			this->outputlabel->TabIndex = 19;
			this->outputlabel->Text = L"output : ";
			// 
			// output
			// 
			this->output->AutoSize = true;
			this->output->Location = System::Drawing::Point(85, 64);
			this->output->Name = L"output";
			this->output->Size = System::Drawing::Size(207, 20);
			this->output->TabIndex = 18;
			this->output->Text = L"output will be displayed here";
			// 
			// outputstring1
			// 
			this->outputstring1->AutoSize = true;
			this->outputstring1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputstring1->Location = System::Drawing::Point(70, 10);
			this->outputstring1->Name = L"outputstring1";
			this->outputstring1->Size = System::Drawing::Size(180, 17);
			this->outputstring1->TabIndex = 17;
			this->outputstring1->Text = L"press the button please";
			// 
			// stringlabel2
			// 
			this->stringlabel2->AutoSize = true;
			this->stringlabel2->Location = System::Drawing::Point(12, 7);
			this->stringlabel2->Name = L"stringlabel2";
			this->stringlabel2->Size = System::Drawing::Size(52, 20);
			this->stringlabel2->TabIndex = 16;
			this->stringlabel2->Text = L"input :";
			// 
			// GENERATEbutton
			// 
			this->GENERATEbutton->AutoSize = true;
			this->GENERATEbutton->Location = System::Drawing::Point(743, 167);
			this->GENERATEbutton->Name = L"GENERATEbutton";
			this->GENERATEbutton->Size = System::Drawing::Size(170, 38);
			this->GENERATEbutton->TabIndex = 24;
			this->GENERATEbutton->Text = L"GENERATE INPUTS";
			this->GENERATEbutton->UseVisualStyleBackColor = true;
			this->GENERATEbutton->Click += gcnew System::EventHandler(this, &PRATITIONPROBLEMform::GENERATEbutton_Click);
			// 
			// PRATITIONPROBLEMform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1533, 220);
			this->Controls->Add(this->GENERATEbutton);
			this->Controls->Add(this->warning);
			this->Controls->Add(this->nextbutton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->noofinputs);
			this->Controls->Add(this->outputlabel);
			this->Controls->Add(this->output);
			this->Controls->Add(this->outputstring1);
			this->Controls->Add(this->stringlabel2);
			this->Name = L"PRATITIONPROBLEMform";
			this->Text = L"PRATITIONPROBLEMform";
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

		bool findPartiion(vector <int> arr, int n)
		{
			int sum = 0;
			int i, j;

			for (i = 0; i < n; i++)
				sum += arr[i];

			if (sum % 2 != 0)
				return false;

			bool** part;
			part = new bool* [sum / 2 + 1];
			for (int a = 0; a < sum / 2 + 1; a++)
				part[a] = new bool[n + 1];

			for (i = 0; i <= n; i++)
				part[0][i] = true;

			for (i = 1; i <= sum / 2; i++)
				part[i][0] = false;

			for (i = 1; i <= sum / 2; i++) {
				for (j = 1; j <= n; j++) {
					part[i][j] = part[i][j - 1];
					if (i >= arr[j - 1])
						part[i][j] = part[i][j]
						|| part[i - arr[j - 1]][j - 1];
				}
			}
			return part[sum / 2][n];
		}
	private: System::Void nextbutton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		static int counter = 0;
		vector <int> array;
		string s1;
		ifstream input;
		input.open("PARTITIONPROBLEMsample.txt", ios::in);
		for (int a = 0; a <= counter; a++)
		{
			getline(input, s1);
			outputstring1->Text = gcnew String(s1.c_str());
		}
		array = convertStrtoArr(s1);
		if (findPartiion(array, array.size()) == true)
			output->Text ="Can be divided into two subsets of equal sum";
		else
			output->Text = "Can not be divided into two subsets of equal sum";
		
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
		in.open("PARTITIONPROBLEMsample.txt", ios::out);
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
