/*
  Implementation of methods for classes Response, AngryResponse, HappyResponse
*/
#include <iostream>
#include <string>
#include <algorithm>

#include "response.h"

using namespace std;

/*
  Implementation of Word class
  Don't worry too hard about these implementations.
  If you'd like to learn more about STL see: 
    https://www.geeksforgeeks.org/the-c-standard-template-library-stl/
*/
string Word::upper()
{
  string result(theWord);
  transform(result.begin(), result.end(), result.begin(), ::toupper);
  return result;
}

string Word::lower()
{
  string result(theWord);
  transform(result.begin(), result.end(), result.begin(), ::tolower);
  return result;
}

/*
  Implementation of Response methods
*/
bool Response::checkAndRespond(const string& inWord, ostream& toWhere)
{
    // TODO:
    // This method should check if the current object's keyword is in the
    // input message (inWord), and send the proper response to the toWhere
    // output stream
    // String class provides the function 'find' which you might find useful

	//init return var
	bool ret = false;

	//determine if keyword is in given message
	size_t found = inWord.find(keyword.normal());
	size_t found_upper = inWord.find(keyword.upper());
	size_t found_lower = inWord.find(keyword.lower());

	// Change return boolean based on result of keyword being found in message
	if (found != string::npos or found_upper != string::npos or found_lower != string::npos) 
	{
		ret = true;
		respond(toWhere);
	}
	
	return ret;
}

void Response::respond(ostream& toWhere)
{
    // TODO:
    // This method should 'insert' "I am neither angry nor happy: " followed by
    // the object's response word to the toWhere output stream, along with
    // a newline at the end
    toWhere << "I am neither angry nor happy: " << response << endl;
}


void AngryResponse::respond(ostream& toWhere)
{
  // TODO:
  // Implement the 'respond' member function for the AngryResponse class so that
  // the angry rseponse "I am angry: " followed by the object's response word 
  // is inserted to the toWhere output stream, along with a newline at the end
  toWhere << "I am angry: " << response << endl;
}


void HappyResponse::respond(ostream& toWhere)
{
    // Implement the 'respond' member function for the HappyResponse class so that
    // the happy rseponse "I am happy: " followed by the object's response word 
    // is inserted to the toWhere output stream, along with a newline at the end
    toWhere << "I am happy: " << response << endl; 
}
