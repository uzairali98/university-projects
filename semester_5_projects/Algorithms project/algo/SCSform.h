#pragma once
#include <fstream>
#include <iostream>
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
	/// Summary for SCSform
	/// </summary>
	public ref class SCSform : public System::Windows::Forms::Form
	{
	public:
		SCSform(void)
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
		~SCSform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ outputstring1;
	private: System::Windows::Forms::Label^ stringlabel1;
	private: System::Windows::Forms::Label^ outputstring2;
	private: System::Windows::Forms::Label^ stringlabel2;
	private: System::Windows::Forms::Label^ outputlabel;
	private: System::Windows::Forms::Label^ output;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ noofinputs;
	private: System::Windows::Forms::Button^ nextbutton;
	private: System::Windows::Forms::Label^ warning;
	private: System::Windows::Forms::Button^ GENERATEINPUTSbutton;
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
			this->outputstring1 = (gcnew System::Windows::Forms::Label());
			this->stringlabel1 = (gcnew System::Windows::Forms::Label());
			this->outputstring2 = (gcnew System::Windows::Forms::Label());
			this->stringlabel2 = (gcnew System::Windows::Forms::Label());
			this->outputlabel = (gcnew System::Windows::Forms::Label());
			this->output = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->noofinputs = (gcnew System::Windows::Forms::Label());
			this->nextbutton = (gcnew System::Windows::Forms::Button());
			this->warning = (gcnew System::Windows::Forms::Label());
			this->GENERATEINPUTSbutton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// outputstring1
			// 
			this->outputstring1->AutoSize = true;
			this->outputstring1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputstring1->Location = System::Drawing::Point(87, 33);
			this->outputstring1->Name = L"outputstring1";
			this->outputstring1->Size = System::Drawing::Size(180, 17);
			this->outputstring1->TabIndex = 4;
			this->outputstring1->Text = L"press the button please";
			// 
			// stringlabel1
			// 
			this->stringlabel1->AutoSize = true;
			this->stringlabel1->Location = System::Drawing::Point(12, 31);
			this->stringlabel1->Name = L"stringlabel1";
			this->stringlabel1->Size = System::Drawing::Size(69, 20);
			this->stringlabel1->TabIndex = 5;
			this->stringlabel1->Text = L"string 1 :";
			// 
			// outputstring2
			// 
			this->outputstring2->AutoSize = true;
			this->outputstring2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->outputstring2->Location = System::Drawing::Point(87, 66);
			this->outputstring2->Name = L"outputstring2";
			this->outputstring2->Size = System::Drawing::Size(180, 17);
			this->outputstring2->TabIndex = 7;
			this->outputstring2->Text = L"press the button please";
			// 
			// stringlabel2
			// 
			this->stringlabel2->AutoSize = true;
			this->stringlabel2->Location = System::Drawing::Point(12, 64);
			this->stringlabel2->Name = L"stringlabel2";
			this->stringlabel2->Size = System::Drawing::Size(69, 20);
			this->stringlabel2->TabIndex = 6;
			this->stringlabel2->Text = L"string 2 :";
			// 
			// outputlabel
			// 
			this->outputlabel->AutoSize = true;
			this->outputlabel->Location = System::Drawing::Point(15, 122);
			this->outputlabel->Name = L"outputlabel";
			this->outputlabel->Size = System::Drawing::Size(67, 20);
			this->outputlabel->TabIndex = 9;
			this->outputlabel->Text = L"output : ";
			// 
			// output
			// 
			this->output->AutoSize = true;
			this->output->Location = System::Drawing::Point(86, 122);
			this->output->Name = L"output";
			this->output->Size = System::Drawing::Size(207, 20);
			this->output->TabIndex = 8;
			this->output->Text = L"output will be displayed here";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 210);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(121, 20);
			this->label2->TabIndex = 11;
			this->label2->Text = L"INPUTS READ:";
			// 
			// noofinputs
			// 
			this->noofinputs->AutoSize = true;
			this->noofinputs->Location = System::Drawing::Point(139, 210);
			this->noofinputs->Name = L"noofinputs";
			this->noofinputs->Size = System::Drawing::Size(18, 20);
			this->noofinputs->TabIndex = 10;
			this->noofinputs->Text = L"0";
			// 
			// nextbutton
			// 
			this->nextbutton->AutoSize = true;
			this->nextbutton->Location = System::Drawing::Point(304, 189);
			this->nextbutton->Name = L"nextbutton";
			this->nextbutton->Size = System::Drawing::Size(116, 38);
			this->nextbutton->TabIndex = 12;
			this->nextbutton->Text = L"READ NEXT";
			this->nextbutton->UseVisualStyleBackColor = true;
			this->nextbutton->Click += gcnew System::EventHandler(this, &SCSform::nextbutton_Click_1);
			// 
			// warning
			// 
			this->warning->AutoSize = true;
			this->warning->Location = System::Drawing::Point(659, 207);
			this->warning->Name = L"warning";
			this->warning->Size = System::Drawing::Size(209, 20);
			this->warning->TabIndex = 13;
			this->warning->Text = L"FILE LIMIT NOT REACHED";
			// 
			// GENERATEINPUTSbutton
			// 
			this->GENERATEINPUTSbutton->AutoSize = true;
			this->GENERATEINPUTSbutton->Location = System::Drawing::Point(438, 189);
			this->GENERATEINPUTSbutton->Name = L"GENERATEINPUTSbutton";
			this->GENERATEINPUTSbutton->Size = System::Drawing::Size(170, 38);
			this->GENERATEINPUTSbutton->TabIndex = 14;
			this->GENERATEINPUTSbutton->Text = L"GENERATE INPUTS";
			this->GENERATEINPUTSbutton->UseVisualStyleBackColor = true;
			this->GENERATEINPUTSbutton->Click += gcnew System::EventHandler(this, &SCSform::GENERATEINPUTSbutton_Click);
			// 
			// SCSform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(880, 239);
			this->Controls->Add(this->GENERATEINPUTSbutton);
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
			this->Name = L"SCSform";
			this->Text = L"SCSform";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	int superSeq(string X,string Y, int m, int n)
	{
		int** dp;
		dp = new int* [m + 1];
		for (int a = 0; a < m + 1; a++)
			dp[a] = new int[n + 1];
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				if (!i)
					dp[i][j] = j;
				else if (!j)
					dp[i][j] = i;
				else if (X[i - 1] == Y[j - 1])
					dp[i][j] = 1 + dp[i - 1][j - 1];
				else
					dp[i][j]
					= 1 + min(dp[i - 1][j], dp[i][j - 1]);
			}
		}

		return dp[m][n];
	}
	private: System::Void nextbutton_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void nextbutton_Click_1(System::Object^ sender, System::EventArgs^ e) 
	{
		static int counter = 0;
		int answer;
		string s1, s2;
		ifstream input;
		input.open("SCSsample.txt", ios::in);
		for (int a = 0; a <= counter; a++)
		{
			getline(input, s1);
			getline(input, s2);
			outputstring1->Text = gcnew String(s1.c_str());
			outputstring2->Text = gcnew String(s2.c_str());
		}
		answer = superSeq(s1, s2, s1.length(), s2.length());
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
private: System::Void GENERATEINPUTSbutton_Click(System::Object^ sender, System::EventArgs^ e) 
	{
	srand(time(NULL));
	string name = "mirzamuhammaduzairali";
	string generated;
	ofstream in;
	in.open("SCSsample.txt", ios::out);
	for (int x = 0; x < 10; x++)
	{
		for (int b = 0; b < 2; b++)
		{
			for (int a = 0; a < 30 + rand() % 70; a++)
			{
				generated.push_back(name[rand() % (name.length() - 1)]);
			}
			if (x == 9 && b == 1)
				in << generated;
			else
				in << generated << endl;
			generated.clear();
		}
	}
	in.close();
	}
};
}
