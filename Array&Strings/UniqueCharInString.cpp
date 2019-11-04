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

//Solution 1: Time and Space Complexity O(n)
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

//Solution 2: Time Complexity: O(n),
//Space Complexity O(1)
/*The approach is valid for strings having alphabet as a-z. Instead of maintaining a boolean 
array, we maintain an integer value called checker(32 bits). As we iterate over the string, 
we find the int value of the character with respect to ‘a’ with the statement int bitAtIndex = str.charAt(i)-‘a’;
Then the bit at that int value is set to 1 with the statement 1 << bitAtIndex .
Now, if this bit is already set in the checker, the bit AND operation would make checker > 0. Return false in this case.
Else Update checker to make the bit 1 at that index with the statement checker = checker | (1 <<bitAtIndex);*/
bool areChractersUnique(string str) 
{ 
    // An integer to store presence/absence 
    // of 26 characters using its 32 bits. 
    int checker = 0; 
  
    for (int i = 0; i < str.length(); ++i) 
    { 
        int val = (str[i]-'a'); 
  
        // If bit corresponding to current 
        // character is already set 
        if ((checker & (1 << val)) > 0) 
            return false; 
  
        // set bit in checker 
        checker |=  (1 << val); 
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
