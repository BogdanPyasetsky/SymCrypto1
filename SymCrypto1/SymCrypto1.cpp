#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
#include <algorithm>


//#include <cctype>

using namespace std;


int main()
{
	setlocale(LC_CTYPE, "rus");
	string line = "", str;
	ifstream originFile ("OFile.txt");
	//fstream newFile ("NFile.txt");
	if (originFile.is_open())
	{
		while (getline(originFile, str))
		{
		    transform (str.begin(), str.end(), str.begin(), tolower);
			line += str;
			line += ' ';
		}
	}
	originFile.close();
	//newFile.close();
	//line.erase(remove_if(line.begin(), line.end(), &ispunct), line.end());    not working
	str = "";
	//cout << line << endl;
	for (int i = 0; i < line.length(); i++)
		if ( (line[i] != '.') && (line[i] != ',') && (line[i] != '!') && (line[i] != '?') && (line[i] != '/') )
			str += line[i];

	//cout << str << endl;
	string lett = "абвгдежзийклмнопрстуфхцчшщыьэюя";
	int len = lett.length();
	string bigg[31][31];
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			bigg[i][j] += lett[i];
			bigg[i][j] += lett[j];
		}
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
			cout << bigg[i][j] << "  ";
		cout << "\n";
	}
		
	


	cout << "\n";
	system("Pause");
	return 0;
}
