#include "mainform.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args)

{
	Application::EnableVisualStyles(); 
	Application::SetCompatibleTextRenderingDefault(false); 
	algo::mainform form; 
	Application::Run(% form);

}