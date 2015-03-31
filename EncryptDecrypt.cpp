/******************************************************************************
*	Title:			EncryptDecrypt.cpp
*	Author:			Travis Waelbroeck
*	Date:			March 27, 2015
*	Description:	Allows user to encrypt or decrypt a file at will.
*					
******************************************************************************/
#include "Decryption.h"
#include "Encryption.h"


int main()
{
	int i = 1;		// Controls main loop execution
	char crypt,		// Holds user choice to encrypt or decrypt file
		keepGoing;	// Holds user answer to manipulate another file 
	fstream file;	// File to manipulate

//  Main loop.
	while (i == 1) {
		int j = 1;	// Resets input validation if user manipulates multiple files


	//  Get encrypt/decrypt choice and validate
		cout << "Do you want to (E)ncrypt or (D)ecrypt a file? ";
		cin >> crypt;
		crypt = toupper(crypt);

		while (j == 1) {
			if (crypt == 'E' || crypt == 'D') { j = 0; }	// Input was valid
			else {
				cout << "Answer must be 'E' or 'D'...\n";
				cout << "Do you want to (E)ncrypt or (D)ecrypt a file? ";
				cin >> crypt;	// loop will re-evaluate until input is valid
				crypt = toupper(crypt);
			}
		}// END GET ENCRYPT/DECRYPT CHOICE


	//  Perform file encryption
		if (crypt == 'D') {
			Decryption();
		}// END ENCRYPTION


	//  Perform file decryption
		else {
			Encryption();
		}// END DECRYPTION


	//  Check if done
		cout << "Do you want to encrypt or decrypt a different file? (Y or N) ";
		cin >> keepGoing;
		keepGoing = toupper(keepGoing);		// Forces upper-case answer

		if (keepGoing == 'N') { i = 0; }	// Causes outside loop exit & program stops
		else if (keepGoing != 'Y') { cout << "Invalid choice... Exiting...\n"; i = 0; }
		// else user choice was Y and they want to go again
	//  END CHECK IF DONE
	}// END MAIN LOOP

	cin.get();
	return 0;
}