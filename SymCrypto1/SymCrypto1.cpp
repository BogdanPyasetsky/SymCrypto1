#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
#include <algorithm>
#include <math.h>
//#include <cctype>


using namespace std;


double Frequency(char* txt, int len, char x) // for monograms 
{
	double t = 0;
	for (int i = 0; i < len; i++)
		if (txt[i] == x)
			t++;
	return t/len;
}

double Frequency1(char* txt, int len, char x, char y) // for intersecting bigrams
{
	double t = 0;
	for (int i = 0; i < len - 1; i++)
		if((txt[i] == x) && (txt[i+1] == y)) 
			t++;
	return t / (len-1);
}

double Frequency2(char* txt, int len, char x, char y) // for not intersecting bigrams 
{
	double t = 0;
	for (int i = 0; i < len/2; i+= 2)
		if ((txt[i] == x) && (txt[i + 1] == y))
			t++;
	return t / (len - 1);
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	string line = "", str;
	ifstream originFile("OFile.txt");
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


	//string result = Regex.(lett, @"s+", " ");
	char lett[] = " абвгдежзийклмнопрстуфхцчшщыьэюя";
	int len = size(lett);
	str = "";
	
	int t = 1;
	for (int i = 0; i < len; i++)
		if (line[0] == lett[i])
			str += line[0];
	while (t <= line.length())
	{
		if ((line[t] == lett[0]) && (str.back() != lett[0]))
			str += line[t];
		for (int i = 1; i < len; i++)
			if (line[t] == lett[i])
				str += line[t];
		t++;
	}
		
	int sLen1 = str.length();
	char* arr1 = new char[sLen1];
	for (int i = 0; i < sLen1; i++)
	{
		arr1[i] = str[i];
		//cout << arr1[i];
	}
	//cout << endl << sLen;
	

	/*
	double frq11[32]; // monograms with ' '
	for (int i = 0; i < 32; i++)
	{
		frq11[i] =  Frequency(arr1, sLen1 - 2, lett[i]);
		//newFile << "frequency for " << lett[i] << " : " << frq11[i] << endl;
	}
	*/
	
	double frq211[32][32]; // intersecting bigrams with ' '
	for (int i = 0; i < 32; i++)
		for (int j = 0; j < 32; j++)
		{
			frq211[i][j] = Frequency1(arr1, sLen1-2, lett[i], lett[j]);
			//newFile << "frequency for " << lett[i] << lett[j] <<  " : " << frq211[i][j] << endl;
		}
	
	
	double frq212[32][32]; // not intersecting bigrams with ' '
	for (int i = 0; i < 32; i++)
		for (int j = 0; j < 32; j++)
		{
			//frq212[i][j] = Frequency2(arr1, sLen1 - 2, lett[i], lett[j]);
			//newFile << "frequency for " << lett[i] << lett[j] << " : " << frq212[i][j] << endl;
		}
		
	

	line = "";
	t = 0;
	while (t < sLen1)
	{
		if (arr1[t] != ' ')
			line += arr1[t];
		t++;
	}

	//cout << endl;
	int sLen2 = line.length();
	char* arr2 = new char[sLen2];
	for (int i = 0; i < sLen2; i++)
	{
		arr2[i] = line[i];
		//cout << arr2[i];
	}


	/*
	double frq12[31]; // monograms without ' '
	for (int i = 1; i < 32; i++)
	{
		frq12[i-1] = Frequency(arr2, sLen2 - 2, lett[i]);
		//newFile << "frequency for " << lett[i] << " : " << frq12[i-1] << endl;
	}
	*/
	
	double frq221[31][31]; // intersecting bigrams without ' '
	for (int i = 1; i < 32; i++)
		for (int j = 1; j < 32; j++)
		{
			//frq221[i-1][j-1] = Frequency1(arr2, sLen2 - 2, lett[i], lett[j]);
			//newFile << "frequency for " << lett[i] << lett[j] << " : " << frq221[i-1][j-1] << endl;
		}
		
	
	double frq222[31][31]; // not intersecting bigrams without ' '
	for (int i = 1; i < 32; i++)
		for (int j = 1; j < 32; j++)
		{
			//frq222[i-1][j-1] = Frequency2(arr2, sLen2 - 2, lett[i], lett[j]);
			//newFile << "frequency for " << lett[i] << lett[j] << " : " << frq222[i-1][j-1] << endl;
		}


	/*
	newFile << "               " << "monograms with ' '" << "      " << "monograms without ' '" << endl;
	newFile << "frequency for " << lett[0] << " : " << frq11[0] << endl;
	for (int i = 1; i < 32; i++)
		newFile << "frequency for " << lett[i] << " : " << frq11[i] <<  "               " << frq12[i-1] << endl;
	newFile << endl;
	*/
	
	newFile << "        ";
	for (int i = 0; i < 32; i++)
		newFile << lett[i] << "                ";
	newFile << endl;
	for (int i = 0; i < 32; i++)
	{
		newFile << lett[i];
		for (int j = 1; j < 32; j++)
			newFile << "  " <<frq211[i][j] << "     ";
		newFile << endl;
	}
	



	delete[] arr1;
	delete[] arr2;
	newFile.close();
	cout << "\n";
	system("Pause");
	return 0;
}