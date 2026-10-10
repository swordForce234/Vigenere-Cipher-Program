//<Vigenere.cpp>-This class is used to implement the vigenere cypher algorithm.
#pragma once
#include "Vigenere.h"
#include <string>

Vigenere::Vigenere(std::string k) //This constructor assigns the value of k to "key".
{
	key = k;
}

void Vigenere::setKey(std::string k) //This function assigns the value of k to key after it is converted to all uppercase.
{
	key = toUpperCase(k);
}

std::string Vigenere::getKey() const
{
	return key;
}

std::string Vigenere::toUpperCase(std::string k)
{
	const int lengthOfK = static_cast<int>(k.length()); //This statement creates a constant of type int that stores the length of the parameter.
	                                                    //It is a constant since it's value should not be changed.
	for (int index = 0; index < lengthOfK; index++) //This loop makes it so that all the characters of the parameter "k" are uppercase.
	{
		k[index] = toupper(k[index]);
	}
	return k; //Now that all the characters of "k" are uppercase, it is returned.
}


//The next two functions are from the instructions for this assignment.
std::string Vigenere::encryptWord(std::string word)
{
	std::string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c + key[j] - 2 * 'A') % 26 + 'A'; //added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
		j = (j + 1) % key.length();
	}
	return output;

} //encryptWord

std::string Vigenere::decryptWord(std::string word)
{
	std::string output;
	for (int i = 0, j = 0; i < word.length(); ++i) {
		char c = word[i];
		if (c >= 'a' && c <= 'z')
			c += 'A' - 'a';
		else if (c < 'A' || c > 'Z')
			continue;
		output += (c - key[j] + 26) % 26 + 'A';//added 'A' to bring it in range of ASCII alphabet [ 65-90 | A-Z ]
		j = (j + 1) % key.length();
	}
	return output;
} //decryptWord


