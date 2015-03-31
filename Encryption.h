/******************************************************************************
*	Title:			Encryption.cpp
*	Author:			Travis Waelbroeck
*	Date:			March 27, 2015
*	Description:	Function that encrypts file specified by user
*
******************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Encryption {
private:
	string file;

public:
	Encryption();	// Constructor

};

Encryption::Encryption() {
	ifstream inputFile;
	ofstream outputFile;
	string fileName,
		line;
	char ch;

	// Open the input file
	cout << "What is the file name to encrypt? (case-sensitive, include extension)\n";
	cout << "Example: File123.txt\n\n";
	cin >> fileName;
	inputFile.open(fileName.c_str(), ios::in);
	cout << "You entered: " << fileName << endl;

	if (inputFile.fail()) {
		cout << "\nThe file could not be opened!\n";
		exit(1);
	}

	// Open the output file
	cout << "What do you want the encrypted file to be named?\n\n";
	string newFileName;
	cin >> newFileName;
	outputFile.open(newFileName, ios::out);

	// Encrypt the file
	while (!inputFile.eof()) {
		while (inputFile >> noskipws >> ch) {
			ch += 1;
			outputFile << ch;	// Write encoded value to outputFile
		}
	}// End file encryption

	inputFile.close();
	outputFile.close();
};