//<CypherDriver.cpp>--This project implements the Vigenere Cypher algorithm.
//CSIS 112-B01
//The code for encryptWord() and decryptWord() was taken from the instructions for this assignment.
//Instructions from previous assignments were used.
//Code from the textbook and previous assignment instructions was used.
/*
Bibliography:

Audie. (2011, June 20). getline for C-strings. Cplusplus.com. https://cplusplus.com/forum/beginner/45169/#google_vignette
baskin. (2010, May 17). strtok program crashing (M. Al-Qudsi, Ed.). Stack Overflow. https://stackoverflow.com/questions/2843236/strtok-program-crashing
CCBet. (2016, March 10). strtok_s function breaking the program. Stack Overflow. https://stackoverflow.com/questions/35915822/strtok-s-function-breaking-the-program
Chakraborty, A. (2023, October 4). C++ Program to append an element into an array. Www.tutorialspoint.com; Tutorials Point India Private Limited. https://www.tutorialspoint.com/cplusplus-program-to-append-an-element-into-an-array
Chen, R. (2021, August 13). Resolving the ambiguity when your C++ class inherits from multiple base classes that have the same method. Microsoft; Microsoft. https://devblogs.microsoft.com/oldnewthing/20210813-05/?p=105554
cppreference.com. (2022, October 20). strtok, strtok_s. Cppreference.com. https://en.cppreference.com/w/c/string/byte/strtok
DennisHernan. (2011, June 5). Is there a limit to the number of charators per line in notepad? Microsoft. https://answers.microsoft.com/en-us/windows/forum/all/is-there-a-limit-to-the-number-of-charators-per/0a68c583-4a0f-40d9-b691-f479cfdb9905
DevSolar. (2013, January 29). using namespace std; in a header file. Stackoverflow. https://stackoverflow.com/questions/14575799/using-namespace-std-in-a-header-file
Dikhtyar, D. (2022, April 6). How to place a space at the end of cout. Cplusplus.com. https://cplusplus.com/forum/beginner/283041/
Harish. (2016, August 2). printing token returned from strtok or strtok_r crashes. Stack Overflow. https://stackoverflow.com/questions/38718682/printing-token-returned-from-strtok-or-strtok-r-crashes
IBM. (2023a, April 11). memmove() — Copy Bytes. Www.ibm.com; IBM. https://www.ibm.com/docs/en/i/7.4?topic=functions-memmove-copy-bytes#memmove
IBM. (2023b, April 11). strchr() — Search for Character. Www.ibm.com; IBM. https://www.ibm.com/docs/en/i/7.4?topic=functions-strchr-search-character#strchr
IBM. (2023c, April 11). strcoll() — Compare Strings. Www.ibm.com; IBM. https://www.ibm.com/docs/en/i/7.4?topic=functions-strcoll-compare-strings#strcoll
IBM. (2023d, April 11). strcpy() — Copy Strings. Www.ibm.com; IBM. https://www.ibm.com/docs/en/i/7.4?topic=functions-strcpy-copy-strings
IBM. (2023e, April 11). strcspn() — Find Offset of First Character Match. Www.ibm.com; IBM. https://www.ibm.com/docs/en/i/7.4?topic=functions-strcspn-find-offset-first-character-match#strcspn
IBM. (2023f, April 11). strdup() — Duplicate String. Www.ibm.com; IBM. https://www.ibm.com/docs/en/i/7.4?topic=functions-strdup-duplicate-string#strdup
IBM. (2023g, April 11). strerror() — Set Pointer to Runtime Error Message. Www.ibm.com; IBM. https://www.ibm.com/docs/en/i/7.4?topic=functions-strerror-set-pointer-runtime-error-message#strerro
IBM. (2023h, April 11). strrchr() — Locate Last Occurrence of Character in String. Www.ibm.com; IBM. https://www.ibm.com/docs/en/i/7.4?topic=functions-strrchr-locate-last-occurrence-character-in-string
IBM. (2023i, April 11). strstr() — Locate Substring. Www.ibm.com; IBM. https://www.ibm.com/docs/en/i/7.4?topic=functions-strstr-locate-substring#strstr
IBM. (2023j, April 11). . Ibm.com; IBM. https://www.ibm.com/docs/en/i/7.4?topic=files-stringh#stringh
jeja. (2017, September 13). Code crashes when splitting the tokens using strtok by passing the string to function (akshayk07, Ed.). Stack Overflow. https://stackoverflow.com/questions/46176856/code-crashes-when-splitting-the-tokens-using-strtok-by-passing-the-string-to-fun
K, A. (2023, February 19). Exception thrown at 0x00007FFCCCB30369 (ucrtbased.dll) in Project3.exe: 0xC0000005: Access violation writing location 0x000000894B700000 (E. Postpischil, Ed.). Stack Overflow. https://stackoverflow.com/questions/75499075/exception-thrown-at-0x00007ffcccb30369-ucrtbased-dll-in-project3-exe-0xc00000
Kapse, S. (2019, July 30). Why does std::getline() skip input after a formatted extraction? Tutorialspoint; Tutorials Point India Private Limited. https://www.tutorialspoint.com/why-does-std-getline-skip-input-after-a-formatted-extraction
kevcadieux, & Taojunshen. (2021, October 28). FileOutput class. Microsoft; Microsoft. https://learn.microsoft.com/en-us/cpp/build-insights/reference/sdk/cpp-event-data-types/file-output?view=msvc-170
KHAN, M. I., & shantanu_23. (2023, June 7). strtok() and strtok_r() functions in C with examples. GeeksForGeeks; Sanchhaya Education Private Limited. https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/
Khanduri, A. (2023, May 29). Vigenere Cipher. GeeksForGeeks; Sanchhaya Education Private Limited. https://www.geeksforgeeks.org/vigenere-cipher/
Kromenaker, C. (2022, May 29). C-Strings in C++. Clark Kromenaker. http://clarkkromenaker.com/post/cpp-cstrings/?fbclid=IwAR0U1XmH1LFFTyPuDw99oTliN0iDlvWSeNcM_uW0biis7V0XzJhzRXX8z1g
Lipshitz, R. W. (2021, February 25). White space on the end of output string not printing with the string, but rather with the next printed line after it. Stack Overflow. https://stackoverflow.com/questions/57727656/white-space-on-the-end-of-output-string-not-printing-with-the-string-but-rather
maiak, ghogen, Saisang, TimShererWithAquent, mijacobs, gewarren, damabe, & Mikejo5000. (2024, January 11). Error codes. Microsoft; Microsoft. https://learn.microsoft.com/en-us/visualstudio/extensibility/error-codes?view=vs-2022
Microsoft. (n.d.). Microsoft C++, C, and Assembler documentation. Microsoft; Microsoft. Retrieved February 25, 2024, from https://learn.microsoft.com/en-us/cpp/?view=msvc-170
Mikejo5000, ciphercoder, JamesJBarnett, ghogen, mohitp930, GitHubber17, Saisang, j-martens, v-thpra, WilliamAntonRohm, PRMerger13, gewarren, kraigb, oscarsun72, & KayAnd. (2023, September 14). First look at the Visual Studio Debugger. Microsoft; Microsoft. https://learn.microsoft.com/en-us/visualstudio/debugger/debugger-feature-tour?view=vs-2022
Mikejo5000, ghogen, GitHubber17, j-martens, Saisang, anandmeg, v-niranjan, GitHubPang, rmca14, v-thpra, kraigb, gewarren, TerryGLee, JohnHe404, TimCorey, & nschonni. (2023, October 19). Debug for absolute beginners. Microsoft; Microsoft. https://learn.microsoft.com/en-us/visualstudio/debugger/debugging-absolute-beginners?view=vs-2022&tabs=csharp
Mikejo5000, ghogen, mohitp930, GitHubber17, Saisang, anandmeg, j-martens, rmca14, & gewarren. (2023, October 26). Debugging techniques and tools to help you write better code. Microsoft; Microsoft. https://learn.microsoft.com/en-us/visualstudio/debugger/write-better-code-with-visual-studio?view=vs-2022#fix-an-exception
Milk. (2018, March 1). 0xC0000005: Access violation reading location 0x00000000 (Mat, Ed.). Stack Overflow. https://stackoverflow.com/questions/10478941/0xc0000005-access-violation-reading-location-0x00000000
Montag, G. (2016, June 2). prevent from printing extra whitespace at the end of my line C++. Stack Overflow. https://stackoverflow.com/questions/37601555/prevent-from-printing-extra-whitespace-at-the-end-of-my-line-c
NANDINIJAIN. (2021, December 12). Implementing of strtok() function in C++. GeeksforGeeks; Sanchhaya Education Private Limited. https://www.geeksforgeeks.org/implementing-of-strtok-function-in-c/
Nigel. (2023, May 8). C++ variable returns garbage value. Microsoft; Microsoft. https://learn.microsoft.com/en-us/answers/questions/1279869/c-variable-returns-garbage-value
nikhilchhipa9. (2021, January 25). cout in C++. GeeksforGeeks; Sanchhaya Education Private Limited. https://www.geeksforgeeks.org/cout-in-c/
Petlyarsky, R. (2023, January 2). Exception thrown at 0x00007FF83DE5499E (ucrtbased.dll) in HW5_NEW.exe: 0xC0000005: Access violation reading location 0xFFFFFFFFFFFFFFFF. Error in my code. What could cause it? Learn.microsoft.com. https://learn.microsoft.com/en-us/answers/questions/1148378/exception-thrown-at-0x00007ff83de5499e-(ucrtbased
Petr, B. (2017, April 20). Reading C++ Input from a Filestream. Www.youtube.com. https://www.youtube.com/watch?v=9upxUpXNmpU
Petr, B. (2018, April 13). Reading from an External File in C++. Www.youtube.com. https://www.youtube.com/watch?v=bevMh5K0mqI
prakhargvp. (2023, April 18). File Handling through C++ Classes - GeeksforGeeks. GeeksforGeeks; Sanchhaya Education Private Limited. https://www.geeksforgeeks.org/file-handling-c-classes/
rogetsgeneral7. (2021, February 25). Problem with getline() after cin >>. GeeksForGeeks; Sanchhaya Education Private Limited. https://www.geeksforgeeks.org/problem-with-getline-after-cin/
Tammam, A. (2020, November 1). c++ Exception thrown at 0x7A45FF80 (ucrtbased.dll) in ConsoleApplication1.exe: 0xC0000005: Access violation reading location 0x00000000. Stack Overflow. https://stackoverflow.com/questions/64633563/c-exception-thrown-at-0x7a45ff80-ucrtbased-dll-in-consoleapplication1-exe-0
thenewboston. (2011a, May 14). Buckys C++ Programming Tutorials - 65 - Tips for File Handling. Www.youtube.com. https://www.youtube.com/watch?v=qdkabVYgV24&list=PLAE85DE8440AA6B83&index=67
thenewboston. (2011b, May 14). Buckys C++ Programming Tutorials - 66 - Writing Custom File Structures. Www.youtube.com. https://www.youtube.com/watch?v=iGWhPwh3n-o&list=PLAE85DE8440AA6B83&index=67
TylerMSFT, & colin-home. (2022, October 6). Warning C6054. Microsoft; Microsoft. https://learn.microsoft.com/en-us/cpp/code-quality/c6054?view=msvc-170
TylerMSFT, colin-home, rachana-satao, craigcaseyMSFT, v-kents, yecril71pl, mikeblome, Mikejo5000, ghogen, & Sisang. (2022, November 6). basic_ios Class. Microsoft; Microsoft. https://learn.microsoft.com/en-us/cpp/standard-library/basic-ios-class?view=msvc-170#good
TylerMSFT, colin-home, & v-kents. (2022, October 6). Warning C6386. Learn.microsoft.com; Microsoft. https://learn.microsoft.com/en-us/cpp/code-quality/c6386?view=msvc-170
TylerMSFT, Taojunshen, colin-home, alexbuckgit, DCtheGeek, john-par, & mikeblome. (2022, September 29). C and C++ in Visual Studio. Microsoft; Microsoft. https://learn.microsoft.com/en-us/cpp/overview/visual-cpp-in-visual-studio?view=msvc-170
TylerMSFT, Taojunshen, colin-home, v-kents, mairaw, mikeblome, Mikejo5000, ghogen, & Saisang. (2023, February 16). strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l. Microsoft; Microsoft. https://learn.microsoft.com/en-us/cpp/c-runtime-library/reference/strtok-s-strtok-s-l-wcstok-s-wcstok-s-l-mbstok-s-mbstok-s-l?view=msvc-170&redirectedfrom=MSDN
TylerMSFT, Taojunshen, Mikejo5000, mikeblome, ghogen, & Saisang. (2022, July 7). C++ program termination. Microsoft; Microsoft. https://learn.microsoft.com/en-us/cpp/cpp/program-termination?view=msvc-170
TylerMSFT, Taojunshen, v-kents, mikeblome, Mikejo5000, ghogen, & Saisang. (2022, February 28). Output File Stream Member Functions. Microsoft; Microsoft. https://learn.microsoft.com/en-us/cpp/standard-library/output-file-stream-member-functions?view=msvc-170
Udacity. (2015). Vigenere CIpher [YouTube Video]. In YouTube. https://www.youtube.com/watch?v=SkJcmCaHqS0
W3Schools. (2019). C++ While Loop. W3schools.com; Refnes Data. https://www.w3schools.com/cpp/cpp_while_loop.asp
Wikipedia Contributors. (2024, February 16). Vigenère cipher. Wikipedia; Wikimedia Foundation. https://en.wikipedia.org/wiki/Vigen%C3%A8re_cipher#Key_elimination
*/
#pragma once
#include <iostream>
#include <string>
#include "ProcessMessage.h"
#include "Vigenere.h"
#include <fstream>
#include <cstring>
using namespace std;

int displayMenu(); //This function displays the menu and returns the option that the user selected.
string getKey(int selection);
void checkIfFileExists(string file);
void getInput(char array[], string nameOfFile); //This function gets input from the file to be encvrypted.
void tokenizeInput(char array[], ProcessedMessage& processedMessageObject); //This tokenizes the input during the encryption processs.
void tokenizeInputForDecryption(char array[], ProcessedMessage& processedMessageObject); //This tokenizes the input during the decryption process.

int main()
{
	std::cout << "Joshua Hotaling -- Lab 5 - C++ Programming: Pointers Assignment" << endl << endl;
	int userOption = 4; //This variable is given a placeholder value until the user can indicate their selection.
	string fileName;
	char fileContents[1000]; //This character array will be used to store the contents of the input file.
	while (userOption != 3) //This loop executes as long as the user's option is not "3".
	{
		userOption = displayMenu(); //This statement displays the menu and stores the user's input in the variable "userOption".
		while ((userOption != 1) and (userOption != 2) and (userOption != 3)) //This loop ensures that the user's option is valid.
		{
			std::cout << "You must enter 1, 2, or 3. Please enter a valid value: ";
			cin.clear();
			cin.ignore(200, '\n');
			cin >> userOption;
			std::cout << endl;
		}
		if (userOption == 3)
			return 0;
	    string userKey = getKey(userOption); //This variable will be the encryption or decryption key.
	

		ProcessedMessage messageProcessor(userKey); //This statement creates an object of type "ProcessedMessage". The object will be used to use the ProcessedMessage class's functions.
		if (userOption == 1)
		{
			std::cout << "Enter the file name: ";
			std::getline(cin, fileName);
			std::cout << endl;
			checkIfFileExists(fileName); //This function checks if the file exists. If it does not, it will prompt the user again to obtain a valid file name.
			getInput(fileContents, fileName); //This function stores the contents of the input file into the array "fileContents".
			std::cout << "File contents: " << endl;
			std::cout << fileContents << endl << endl; //This statement outputs the contents of "fileContents" to the console.
			//Starting with the next statement, a modified version of the code from Microsoft's article on the strtok_s function is used.
			const char delimiters[] = { ',', ' ', ':', ';', '.', '\0' };
			//The statement above sets the null character, comma, space, colon, semicolon, and period as delimiters.
			const int fileContentsSize = strlen(fileContents); //This constant stores the length of "fileContents".
			tokenizeInput(fileContents, messageProcessor);
			//This is where the modified version of the code from Microsoft's website ends.
			messageProcessor.outputText();
			cout << "Enter the file where you would like the encrypted words to be stored: ";
			getline(cin, fileName);
			cout << endl;
			messageProcessor.outputText(); //This function outputs the contents of the vector to the console.
			messageProcessor.createFile(fileName); //This function outputs the contents of the vector to the file the user specified.
			system("pause"); //This statement pauses the execution of the program to allow the user to view the program's output.
		}
			if (userOption == 2)
			{
				string fileName2;
				cout << "Enter the name of the file you would like to decrypt: ";
				getline(cin, fileName2);
				cout << endl;
				checkIfFileExists(fileName2);
				getInput(fileContents, fileName2);
				cout << "File contents: " << endl << endl;
				cout << fileContents << endl;
				//Starting with the next statement, the program uses a modified version of code from Microsoft's article on the strtok_s function.
				//The statement above sets the null character, comma, space, colon, semicolon, and period as delimiters.
				const int fileContentsSize2 = strlen(fileContents); //This constant stores the length of "fileContents".
				tokenizeInputForDecryption(fileContents, messageProcessor);
				messageProcessor.outputText();
				//This is where the modified version of the code from Microsoft's website ends.
				cout << "Enter the name of the file where you would like the output to go: ";
				getline(cin, fileName);
				cout << endl;
				cout << "File contents: " << endl;
				messageProcessor.outputText(); //This function will output the decrypted words.
				messageProcessor.createFile(fileName); //This function will output the decrypted words to the file the user specified.
				system("pause"); //This statement pauses the program's execution, allowing the user to see the output.
			}
	}
	return 0;
}

int displayMenu() //This function outputs the menu, gets the user's selection, and then returns the result.
{
	int userSelection;
	cout << "Vigenere Cypher" << endl << endl;
	cout << "   Main Menu" << endl << endl;
	cout << "1 - Encrypt File" << endl;
	cout << "2 - Decrypt File" << endl;
	cout << "3 - Quit" << endl << endl << endl;
	cout << "Selection: ";
	cin >> userSelection;
	cout << endl;
	return userSelection;
}

string getKey(int selection)
{
	string userEnteredKey;
	if (selection == 1)
	{
		cout << "Enter an encryption key: ";
		//The next two statements are from the textbook. They clear the input stream since otherwise, the program does not allow the user to input anything,
		//essentially, freezing it.
		cin.clear();
		cin.ignore(200, '\n');
		getline(cin, userEnteredKey);
		cout << endl;
	}
	else if (selection == 2)
	{
		cout << "Enter a decryption key: ";
		cin.clear();
		cin.ignore(200, '\n');
		getline(cin, userEnteredKey);
		cout << endl;
	}
	while ((userEnteredKey == "") or (userEnteredKey == " ") or (userEnteredKey == "  ")) //This loop ensures that the key is not blank.
	{
		cout << "You cannot enter a blank. Please enter a new key: ";
		getline(cin, userEnteredKey);
		cout << endl;
	}
	return userEnteredKey;
}

void checkIfFileExists(string file)
{
	ifstream test; //This variable will be used to check if the file exists.
	test.open(file);
	while (!test) //This loop executes as long as "test" is in the fail state.
	{
		test.clear();
		test.ignore(200, '\n'); //This statement clears any garbage from the input stream. This line was taken from the textbook.
		cout << "The file does not exist. Please enter a valid file: " << endl;
		getline(cin, file);
		test.clear();
		test.ignore(200, '\n');
		test.open(file);
	}
	test.close();
}

void getInput(char array[], string nameOfFile)
{
	ifstream fileInput;
	fileInput.open(nameOfFile);
	fileInput.getline(array, 1000);
	fileInput.clear();
	fileInput.ignore(200, '\n');
	fileInput.close();
	array[static_cast<int>(strlen(array))] = '\0';
}

	void tokenizeInput(char array[], ProcessedMessage& processedMessageObject)
	{
		int index = 0;
		char* pointer = array;
		char placeholder = 'a';
		char* randomPointer = &placeholder;
		char delimiters[] = { '.', ':', ';', ',', ' ', '\0' };
		char* token = strtok_s(array, delimiters, &randomPointer);
		if (token != NULL)
		{
			processedMessageObject.encryptToken(token);

		}
		while (token != NULL)
		{
			token = strtok_s(NULL, delimiters, &randomPointer);
			if (token != NULL)
			{
				processedMessageObject.encryptToken(token);
			}
		}
	}

	void tokenizeInputForDecryption(char array[], ProcessedMessage& processedMessageObject) //This function works identically to tokenizeInput(), but it replaces encryptToken()
		                                                                                    //calls with decryptToken() calls.
	{
		int index = 0;
		char* pointer = array;
		char placeholder = 'a';
		char* randomPointer = &placeholder;
		char delimiters[] = { '.', ':', ';', ',', ' ', '\0' };
		char* token = strtok_s(array, delimiters, &randomPointer);
		if (token != NULL)
		{
			processedMessageObject.decryptToken(token);

		}
		while (token != NULL)
		{
			token = strtok_s(NULL, delimiters, &randomPointer);
			if (token != NULL)
			{
				processedMessageObject.decryptToken(token);
			}
		}
	}

