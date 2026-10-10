//<Vigenere.h>-This class is used to implement the Vigenere Cypher algorithm.
#pragma once //This statement prevents header file libraries from getting included more than once.
#include <string>

class Vigenere
{
private:
	std::string key; //The encryption key will be stored in this variable.
public:
	Vigenere(std::string k = "0"); //This is the one-argument constructor for the class and also the default constructor for the class.
	void setKey(std::string k); //This function allows the user to set the value of the private member variable "key".
	std::string getKey() const; //This function will return the value of the private member variable "key".
	std::string toUpperCase(std::string k); //This function returns the string it is given, but with every character being uppercase.
	std::string encryptWord(std::string w); //This function will encrypt its parameter and then return the result.
	std::string decryptWord(std::string w); //This function will decrypt its parameter and then return the result.



};
