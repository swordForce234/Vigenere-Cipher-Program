//<ProcessMessage.cpp>-This class is used to process the message that the Vigenere Cypher algorithm is encrypting.
#pragma once
#include <vector>
#include <string>
#include "Vigenere.h"
#include "ProcessMessage.h"
#include <fstream>
#include <iostream>
using namespace std;

ProcessedMessage::ProcessedMessage(std::string k)
{
	v.setKey(k);
}

void ProcessedMessage::encryptToken(char* token)
{
	string encryptedWord = v.encryptWord(token); //"token" is encrypted and the result is stored in the variable "encryptedWord".
	processedWords.push_back(encryptedWord); //The encrypted word is added to the vector.
}

void ProcessedMessage::decryptToken(char* token)
{
	//Reminder: Vector should probably not be cleared since then only one word will end up being in it.
	string decryptedWord = v.decryptWord(token); //"token" is decrypted and the result is stored in the variable "decryptedWord".
	processedWords.push_back(decryptedWord); //The decrypted word is added to the vector.
}

void ProcessedMessage::createFile(std::string fileName)
{
	ofstream fileOutput; //This variable will be used to output to the file.
	fileOutput.open(fileName);
	const int vectorSize = static_cast<int>(processedWords.size()); //This constant will store the size of the vector.
	for (int index = 0; index < vectorSize; index++)
		fileOutput << processedWords[index] << ' ';
	fileOutput.close();
}

void ProcessedMessage::outputText()
{
	const int vectorSize = static_cast<int>(processedWords.size());
	for (int index = 0; index < vectorSize; index++)
	{
		if (index == 0)
			cout << endl;
		cout << processedWords[index] << ' ';
	}
	cout << endl << "Number of words: " << vectorSize << endl;
}

int ProcessedMessage::numberWordsInMessage()
{
	return static_cast<int>(processedWords.size()); //Since the size() function for vectors returns an unsigned int value, static_cast is used to convert it to an int value.
}



