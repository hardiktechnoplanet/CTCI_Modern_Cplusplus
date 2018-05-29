/**
 * @brief One Edit Away
 * There are three types of edits that can be performed on strings:
 * insert a character, remove a character, or replace a character.
 * Given two strings, write a function to check if they are one edit (or zero edits) away.
 * EXAMPLE pale, pIe -> true pales. pale -> true pale. bale -> true pale. bake -> false
 *
 * @file OneEditAway.h
 * @author Hardik Garg
 */
#include<bits/stdc++.h>

using namespace std;

/**
 * @brief checks if first string can be equal to second by just replacing one characted
 * @return true
 * @return false
 */
 
bool one_edit_replace(const string& first, const string& second)
{
	assert( first.length() == second.length() );
	
	bool seen_replacement=false;
	
	for(size_t i=0;i<first.length();++i)
	{
		if(first.at(i)!=second.at(i))
		{
			if(seen_replacement)
			return false;
			
			seen_replacement=true;
		}
	}
	return true;
}

/**
 * @brief checks if inserting one character to the first string can make it same as second
 *
 * @first string of length one less than second
 * @second string of length one more than first
 * @return true
 * @return false
 */
 
bool one_edit_insert(const string& first, const string& second)
{
	size_t ptr_first=0;
	size_t ptr_second=0;
	
	while(ptr_first<first.length() && ptr_second<second.length())
	{
		if(first.at(ptr_first)==second.at(ptr_second))
		{
			++ptr_first;
			++ptr_second;
		}
		else
		{
			if(ptr_first!=ptr_second)
			return false;
			
			ptr_second++;
		}
	}
	return true;
}
bool OneEditAway(const string& first, const string& second)
{
	//if length of both the strings are same
	if(first.length()==second.length())
	return one_edit_replace(first,second);
	
	//if first string length is < len of second string
	else if(first.length()+1==second.length())
	return one_edit_insert(first,second);
	
	////if first string length is > len of second string
	else if(first.length()-1==second.length())
	return one_edit_insert(second,first);
	
	return false;
}

/**
* other way to write the function
*/
/*
bool OneEditAway(string first, string second)
{
	size_t ptr_first=0;
	size_t ptr_sec=0;
	size_T count=0;
		
	while(ptr_first<first.length() && ptr_sec<second.length())
	{
		//if the chars are not same
		if(first.at(ptr_first)!=second.at(ptr_sec))
		{
			//if they are already one edit away
			if(count==1)
			return false;
			
			if(first.length()>second.length())
			++ptr_first;
			
			else if(first.length()<second.length())
			++ptr_sec;
			
			else
			{
				++ptr_first;
				++ptr_sec;
			}
			count++;
		}
		//if the chars are some
		else
		{
			++ptr_first;
			++ptr_sec;
		}
	}
	
	//if the last char is extra in any of the string
	if(ptr_first<first.length() || ptr_sec<second.length())
	count++;
	
	return count==1;
}
*/

int main(int argc, char** argv) {
	string first="geeks";
	string second="gesks";
	if(OneEditAway(first,second)==true)
	{
		cout<<"yes";
	}
	else
	cout<<"no";
	return 0;
}
