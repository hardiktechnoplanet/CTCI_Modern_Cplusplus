/**
 * @brief String Palindrome Permutation
 *  Check if a string is a permutation of a palindrome.
 *  A palindrome is a word or phrase that is the same forwards and backwards.
 *  A permutation is a rearrangement of letters. The palindrome does not need to be limited to just
 *  dictionary words.
 *
 *  EXAMPLE Input: TactoCoa Output: True (permutations: "tacoocat". "atcoocta". etc.)
 *
 * @file string_palindrome_permutation.cpp
 * @author Hardik Garg
 */
 
#include<bits/stdc++.h>

using namespace std;
constexpr size_t num_aplhabets = 26;

/**
 * @brief helper function to convert char to a number in range from 0 to 25
 *
*/
size_t charToNum(const char input)
{
	if(input-'a'>=0 && input-'z'<=0)
	return input-'a';
	
	__throw_invalid_argument( "Not a lower case alphabet" );
}

/**
 * @brief Check if a string is a permutation of a palindrome
 * 1. Case insensitive
 * @input input string
 * @return true if the string is a permutation of palindrome
 * @return false  if the string is not a permutation of palindrome
 */
 
bool palindrome_permutation(const string& input)
{
	array<size_t, num_aplhabets> frequencies{};
	
	//add the frequecy of each char from the string to the array
	for(auto i:input)
	++frequencies.at(charToNum(i));
	
	//check if there is only one char has odd entry in the array
	bool seen_one_frequency=false;
	
	for(auto i:frequencies)
	{
		if(i%2)
		{
			if (seen_one_frequency)
			return false;
			
			seen_one_frequency=true;
		}
	}
	return true;
}

/* function with unordered_map
*/
/*
bool palindrome_permutation(const string& input)
{
	unordered_map <char,size_t> input_map;
	
	for(auto i:input)
	{
		if(input_map.count(i))
		++input_map.at(i);
		
		else
		input_map.insert(make_pair (i,1));
	}
	
	bool seen_one_frequency=false;
	
	for(auto i:input)
	{
		if(input_map.at(i)%2)
		{
			if (seen_one_frequency)
			return false;
			
			seen_one_frequency=true;
		}	
	}
	return true;
}
*/

int main(int argc, char** argv) {
	string input="geegeekk";

	if(palindrome_permutation(input)==true)
	{
		cout<<"yes";
	}
	else
	cout<<"no";
	return 0;
}
