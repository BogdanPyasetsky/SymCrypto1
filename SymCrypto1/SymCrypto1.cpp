#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
#include <algorithm>
#include <math.h>
//#include <cctype>


using namespace std;


double Frequency(string txt, char x)
{
	double len = txt.length();
	double t = 0;
	for (int i = 0; i < len; i++)
		if (txt[i] == x)
			t++;
	return t / len;
}

double Frequency(string txt, string x)
{
	double len = txt.length();
	double t = 0;
	for (int i = 0; i < len - 1; i++)
		//if ((txt.substr(i,2)).compare(x) == 0)   //43 fucking min
		if((txt[i] == x[0]) && (txt[i+1] == x[1])) //4 min
			t++;
	return t / (len-1);
}



int main()
{
	setlocale(LC_CTYPE, "rus");
	string line = "", str;
	ifstream originFile ("OFile.txt");
	ofstream newFile ("NFile.txt");
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
	
	//line.erase(remove_if(line.begin(), line.end(), &ispunct), line.end());    not working
	str = "";
	//cout << line << endl;
	for (int i = 0; i < line.length(); i++)
		if ( (line[i] != '.') && (line[i] != ' ') && (line[i] != ',') && (line[i] != '%') && (line[i] != '&') && (line[i] != '@') && (line[i] != '#') && (line[i] != '—') && (line[i] != '-') && (line[i] != '+') && (line[i] != '*') && (line[i] != '!') && (line[i] != '?') && (line[i] != '/') && (line[i] != '(') && (line[i] != ')') && (line[i] != '[') && (line[i] != ']') && (line[i] != '«') && (line[i] != '»') && (line[i] != '"') && (line[i] != '1') && (line[i] != '2') && (line[i] != '3') && (line[i] != '4') && (line[i] != '5') && (line[i] != '6') && (line[i] != '7') && (line[i] != '8') && (line[i] != '9') && (line[i] != '0') && (line[i] != ':') && (line[i] != ';'))
			str += line[i];

	//cout << str << endl;
	int sLen = str.length();
	string lett = "абвгдежзийклмнопрстуфхцчшщыьэюя";
	int len = lett.length();
	string bigg[31][31];
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			bigg[i][j] += lett[i];
			bigg[i][j] += lett[j];
		}
	/*for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
			cout << bigg[i][j] << "  ";
		cout << "\n";
	}*/
		
	double frq1[31];
	for (int i = 0; i < 31; i++)
	{
		frq1[i] =  Frequency(str, lett[i]);
		newFile << "frequency for " << lett[i] << " : " << frq1[i] << endl;
	}
	
	double frq2[31][31];
	for (int i = 0; i < 31; i++)
		for (int j = 0; j < 31; j++)
		{
			frq2[i][j] = Frequency(str, bigg[i][j]);
			newFile << "frequency for " << bigg[i][j] << " : " << frq2[i][j] << endl;
		}
	
	

	newFile.close();
	cout << "\n";
	system("Pause");
	return 0;
}
