/******************************************************************************
*	Title:			Decryption.cpp
*	Author:			Travis Waelbroeck
*	Date:			March 27, 2015
*	Description:	Function that decrypts file specified by user
*
******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Decryption {
private:
	string file;

public:
	Decryption();	// Constructor

};

Decryption::Decryption() {
	ifstream inputFile;
	ofstream outputFile;
	string fileName,
		line;
	char ch;

	// Open the input file
	cout << "What is the file name to decrypt? (case-sensitive, include extension)\n";
	cout << "Example: File123.txt\n\n";
	cin >> fileName;
	inputFile.open(fileName.c_str(), ios::in);
	cout << "You entered: " << fileName << endl;

	if (inputFile.fail()) {
		cout << "\nThe file could not be opened!\n";
		exit(1);
	}

	// Open the output file
	cout << "What do you want the decrypted file to be named?\n\n";
	string newFileName;
	cin >> newFileName;
	outputFile.open(newFileName, ios::out);

	// Decrypt the file
	while (!inputFile.eof()) {
		while (inputFile >> noskipws >> ch) {
			ch -= 1;
			outputFile << ch;	// Write encoded value to outputFile
		}
	}// End file encryption

	inputFile.close();
	outputFile.close();
};