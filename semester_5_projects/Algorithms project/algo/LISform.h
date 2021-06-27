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
	/// Summary for LISform
	/// </summary>
	public ref class LISform : public System::Windows::Forms::Form
	{
	public:
		LISform(void)
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
		~LISform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label2;
	protected:
	private: System::Windows::Forms::Label^ noofinputs;
	private: System::Windows::Forms::Label^ outputlabel;
	private: System::Windows::Forms::Label^ output;
	private: System::Windows::Forms::Label^ stringlabel1;
	private: System::Windows::Forms::Label^ outputstring1;
	private: System::Windows::Forms::Label^ warning;
	private: System::Windows::Forms::Button^ nextbutton;
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->noofinputs = (gcnew System::Windows::Forms::Label());
			this->outputlabel = (gcnew System::Windows::Forms::Label());
			this->output = (gcnew System::Windows::Forms::Label());
			this->stringlabel1 = (gcnew System::Windows::Forms::Label());
			this->outputstring1 = (gcnew System::Windows::Forms::Label());
			this->warning = (gcnew System::Windows::Forms::Label());
			this->nextbutton = (gcnew System::Windows::Forms::Button());
			this->GENERATEbutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 227);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 20);
			this->label2->TabIndex = 19;
			this->label2->Text = L"INPUTS READ:";
			// 
			// noofinputs
			// 
			this->noofinputs->AutoSize = true;
			this->noofinputs->Location = System::Drawing::Point(139, 227);
			this->noofinputs->Name = L"noofinputs";
			this->noofinputs->Size = System::Drawing::Size(18, 20);
			this->noofinputs->TabIndex = 18;
			this->noofinputs->Text = L"0";
			// 
			// outputlabel
			// 
			this->outputlabel->AutoSize = true;
			this->outputlabel->Location = System::Drawing::Point(12, 57);
			this->outputlabel->Name = L"outputlabel";
			this->outputlabel->Size = System::Drawing::Size(63, 20);
			this->outputlabel->TabIndex = 17;
			this->outputlabel->Text = L"output :";
			// 
			// output
			// 
			this->output->AutoSize = true;
			this->output->Location = System::Drawing::Point(73, 57);
			this->output->Name = L"output";
			this->output->Size = System::Drawing::Size(207, 20);
			this->output->TabIndex = 16;
			this->output->Text = L"output will be displayed here";
			// 
			// stringlabel1
			// 
			this->stringlabel1->AutoSize = true;
			this->stringlabel1->Location = System::Drawing::Point(23, 25);
			this->stringlabel1->Name = L"stringlabel1";
			this->stringlabel1->Size = System::Drawing::Size(56, 20);
			this->stringlabel1->TabIndex = 13;
			this->stringlabel1->Text = L"input : ";
			// 
			// outputstring1
			// 
			this->outputstring1->AutoSize = true;
			this->outputstring1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputstring1->Location = System::Drawing::Point(74, 28);
			this->outputstring1->Name = L"outputstring1";
			this->outputstring1->Size = System::Drawing::Size(180, 17);
			this->outputstring1->TabIndex = 12;
			this->outputstring1->Text = L"press the button please";
			// 
			// warning
			// 
			this->warning->AutoSize = true;
			this->warning->Location = System::Drawing::Point(1204, 227);
			this->warning->Name = L"warning";
			this->warning->Size = System::Drawing::Size(209, 20);
			this->warning->TabIndex = 21;
			this->warning->Text = L"FILE LIMIT NOT REACHED";
			// 
			// nextbutton
			// 
			this->nextbutton->AutoSize = true;
			this->nextbutton->Location = System::Drawing::Point(447, 206);
			this->nextbutton->Name = L"nextbutton";
			this->nextbutton->Size = System::Drawing::Size(116, 38);
			this->nextbutton->TabIndex = 20;
			this->nextbutton->Text = L"READ NEXT";
			this->nextbutton->UseVisualStyleBackColor = true;
			this->nextbutton->Click += gcnew System::EventHandler(this, &LISform::nextbutton_Click);
			// 
			// GENERATEbutton
			// 
			this->GENERATEbutton->AutoSize = true;
			this->GENERATEbutton->Location = System::Drawing::Point(734, 206);
			this->GENERATEbutton->Name = L"GENERATEbutton";
			this->GENERATEbutton->Size = System::Drawing::Size(170, 38);
			this->GENERATEbutton->TabIndex = 22;
			this->GENERATEbutton->Text = L"GENERATE INPUTS";
			this->GENERATEbutton->UseVisualStyleBackColor = true;
			this->GENERATEbutton->Click += gcnew System::EventHandler(this, &LISform::GENERATEbutton_Click);
			// 
			// LISform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1425, 256);
			this->Controls->Add(this->GENERATEbutton);
			this->Controls->Add(this->warning);
			this->Controls->Add(this->nextbutton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->noofinputs);
			this->Controls->Add(this->outputlabel);
			this->Controls->Add(this->output);
			this->Controls->Add(this->stringlabel1);
			this->Controls->Add(this->outputstring1);
			this->Name = L"LISform";
			this->Text = L"LISform";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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
		int lis(vector <int> arr)
		{
			int* lis, i, j, max = 0;
			int temp = (int)arr.size();
			lis = (int*)malloc(sizeof(int) * arr.size());

			for (i = 0; i < temp; i++)
				lis[i] = 1;

			for (i = 1; i<temp; i++)
				for (j = 0; j < i; j++)
					if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
						lis[i] = lis[j] + 1;

			for (i = 0; i < temp; i++)
				if (max < lis[i])
					max = lis[i];
			free(lis);

			return max;
		}
	private: System::Void nextbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		static int counter = 0;
		vector <int> array;
		int answer;
		string s1, s2;
		ifstream input;
		input.open("LISsample.txt", ios::in);
		for (int a = 0; a <= counter; a++)
		{
			getline(input, s1);
			outputstring1->Text = gcnew String(s1.c_str());
		}
		array = convertStrtoArr(s1);
		answer = lis(array);
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
		in.open("LISsample.txt", ios::out);
		for (int x = 0; x < 10; x++)
		{
				for (int a = 0; a < 30 + rand() % 70; a++)
				{
					in << numbers[rand() % 100]<<",";
				}
				if (x == 9)
					continue;
				else
					in <<endl;
			
		}
		in.close();
	}
};
}
