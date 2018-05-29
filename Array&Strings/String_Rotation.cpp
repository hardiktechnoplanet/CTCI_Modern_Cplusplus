/**
 * @brief String Rotation
 * Assume you have a method isSubstring which checks if one word is a substring of another. Given
 * two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to
 * isSubstring (e.g., "waterbottle" is a rotation of"erbottlewat").
 *
 * @file String_Rotation.cpp
 * @author Hardik Garg
 */
#include<bits/stdc++.h>
using namespace std;

bool isSubstring(string& concatinated, string& s2)
{
	return string ::npos != concatinated.find(s2);
}

bool is_Rotation(string& s1, string& s2)
{
	//test case
	if ( ( s1.length() != s2.length() ) || s1.empty() ) 
	return false;
	
	//concatinate the s1 string with s1
	//s2 will always be a substring of s1s1.
	string concatinated=s1+s1;
	
	return isSubstring(concatinated,s2);
}
int main(int argc, char** argv) {
	
	string s1 ="waterbottle";
	string s2 ="erbottledwat";
	
	if(is_Rotation(s1,s2))
	cout<<"true";
	else
	cout<<"false";

	return 0;
}
