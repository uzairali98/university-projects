#include<iostream>
#include<fstream>
#include<stdlib.h>

using namespace std;

int main()
{
	srand(time(NULL));
	string name = "mirzamuhammaduzairali";
	string generated;

	for (int a = 0; a < 30 + rand() % 70; a++)
	{
		generated.push_back(name[rand() % (name.length()-1)]);
	}
	cout << generated;
}