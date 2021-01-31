// LexicalAnalysis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
//#include<bits/stdc++.h> 
using namespace std;

int main()
{
	ifstream input;
	string filename;
	cout << "Enter file name: " << endl;
	cin >> filename;
	string word;

	input.open(filename);
	while (input) {
		std::getline(input, word, ' ');
		//cout<<word<<endl;
		if (word == "for" || word == "while") {
			cout << word << endl;
		}
		else if (word == "if" || word == "else") {
			cout << word << endl;
		}
		else if (word == "int" || word == "float" || word == "string" ||
			word == "double" || word == "bool" || word == "char") {
			cout << word << endl;
		}
		else if (word == "=="||word == "!="||word == "<"
				|| word == ">" || word == "<=" || word == ">="){
			cout << word << endl;
		}
		else if (word == "<<" || word == ">>") {
			cout << word << endl;
		}
	}
	input.close();
}
