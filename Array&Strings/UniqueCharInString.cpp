/**
 * @brief Is Unique
 * Implement an algorithm to determine if a string has all unique characters
 *
 * @file UniqueCharInString.cpp
 * @author Hardik Garg
 */
#include<bits/stdc++.h>

using namespace std;
constexpr size_t num_char=256;

/**
 * @brief detemine if a string has all unique characters
 * Assumes that the character set is ASCII
 * @return true if unique
 * @return false if not 
 */
bool unique(string s)
{
	int len=s.length();
	
	//test case
	if(len>num_char)
	return false;
	
	vector <bool> seen_char(num_char);
	for(auto i:s)
	{
		if(seen_char.at(i))
		return false;
		else
		seen_char.at(i)=true;
	}
	return true;
}

int main(int argc, char** argv) {
	string s="hmnh";
	if(unique(s)==true)
	{
		cout<<"yes";
	}
	else
	cout<<"no";
	return 0;
}

/**
 * Notes:
 * 1. Run time complexity is O(n)
 * 2. Memory complexity is O(1) 
 * 5. vector<bool> will try to pack the input as bits rather than bytes
 * 6. Use for loop with auto makes the code more robuts and clear
 *
 */
