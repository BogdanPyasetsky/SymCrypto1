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
	
	string lett = "aбвгдежзийклмнопрстуфхцчшщыьэюя";
	int len = lett.length();
	str = "";
	int t = 0;
	while (t <= line.length())
	{
		for (int i = 0; i < len; i++)
			if (line[t] == lett[i])
				str += line[t];
		t++;
	}

	
	//var result = Regex.(lett, @"s+", " ");


	//cout << str << endl;
	int sLen = str.length();
	
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