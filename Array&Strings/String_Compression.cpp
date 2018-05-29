/**
 * @brief String Compression
 * Implement a  method to perform basic string compression using the counts of repeated characters.
 * For example, the string aabcccccaaa would become a2blc5a3. If the "compressed" string would not
 * become smaller than the original string, your method should return the original string. You can
 * assume the string has only uppercase and lowercase letters (a - z).
 *
 * @file String_Compression.h
 * @author Hardik Garg
 */
 
#include<bits/stdc++.h>

using namespace std;

/*The function below uses a vector of chars*/

/*
void StringCompress(string str)
{
	vector <char> output_string;
	vector <char>::iterator it;
	size_t count=1;
	
	for(size_t i=0;i<str.length();++i)
	{
		if(str[i]==str[i+1])
		{
			++count;
		}
		else
		{
			output_string.push_back(str[i]);
			output_string.push_back(count+'0');
			count=1;
		}
	}
	for(it =output_string.begin();it!=output_string.end();++it)
	cout<<*it;
}
*/

/*The below function uses string append method and it checks for
shortest len at the last. It can be optimized if we can first check
the shortest len*/
string StringCompress(string str)
{
	string output;
	size_t count=1;
	
	for(size_t i=0;i<str.length();++i)
	{
		if(str[i]==str[i+1])
		{
			++count;
		}
		else
		{
			output.append(str,i,1);
			output.append(to_string(count));
			count=1;
		}
	}
	if(str.length()<output.length())
	return str;
	return output;
}

int main(int argc, char** argv) {
	string str="aabcccccaaa";
    cout<<StringCompress(str);
	return 0;
}
