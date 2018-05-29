/**
 * @brief Check Permutation: Given two strings, check if one is a  permutation of
 * the other.
 *
 * @file Check_String_Permutation.cpp
 * @author Hardik Garg
 */
 
#include<bits/stdc++.h>

using namespace std;
constexpr size_t num_char=256;

// Let length of s be N and length of s1 be M

/**
 * @brief check if the two strings are permutation of each other
 * Notes:
 * 1. Running time O(N log(N) + M log(M)), Memory complexity O(1)
 * @return true if one is the permutation of the other
 * @return false if one is not the permutation of the other
 */
/*
bool ifPermutation(string s,string s1)
{
	//test case: if both the strings are of different lengths
	if(s.length()!=s1.length())
	{
		return false;
	}
	
	sort(s.begin(),s.end());
	sort(s1.begin(),s1.end());
	
	return (s.compare(s1)==0);
}
*/

/**
 * @brief check if the two strings are permutation of each other
 * Notes:
 * 1. Running time O(N+M), Memory complexity O(1)
 * @return true if one is the permutation of the other
 * @return false if one is not the permutation of the other
 */


bool ifPermutation(string s,string s1)
{
	//test case: if both the strings are of different lengths
	if(s.length()!=s1.length())
	{
		return false;
	}
	
	unordered_map <char,size_t> s_counts;
	unordered_map <char,size_t> s1_counts;
	
	for(auto i:s)
	{
		if(s_counts.count(i))
		++s_counts.at(i);
		else
		s_counts.insert(make_pair (i,1));
	}
	for(auto i:s1)
	{
		/*If we want just to check if a key exist, use count. 
		If you would like to check if a key exists, and use its value, then go 
		for find since you will already have an iterator pointing to that element.*/
		
		if(s1_counts.count(i))
		++s1_counts.at(i);
		else
		s1_counts.insert(make_pair (i,1));
	}
	//check if both the unordered_map are equal
	return (s_counts==s1_counts);
}


int main(int argc, char** argv) {
	string s="hmnh";
	string s1="nmnh";
	if(ifPermutation(s,s1)==true)
	{
		cout<<"yes";
	}
	else
	cout<<"no";
	return 0;
}
