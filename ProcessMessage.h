//<ProcessMessage.h>-This class is used to process the message that the Vigenere Cypher algorithm is encrypting.
#pragma once
#include <string>
#include <vector>
#include "Vigenere.h"

class ProcessedMessage
{
private:
	std::vector<std::string> processedWords;
	Vigenere v;
public:
	ProcessedMessage(std::string k = "0"); //This is the one-argument constructor for this class and also the default constructor for the class.
	void encryptToken(char* token); //This function will encrypt its aprameter and then add the result to this class's vector.
	void decryptToken(char* token); //This function will decrypt its parameter and add the result to this class's vector.
	void createFile(std::string fileName); //This function creates a file with the parameter as the name and outputs this class's vector in that file.
	void outputText(); //This function will output the contents of this class's vector to the console.
	int numberWordsInMessage(); //This function will return the length of the vector (the number of words it is storing).

};