/**
 * @brief URLify
 * A method to replace all spaces in a string with '%20:
 * You may assume that the string has sufficient space at the end to hold the additional characters,
 * and that you are given the "true" length of the string.
 *
 * EXAMPLE Input: "Mr John Smith "J 13 Output: "Mr%20J ohn%20Smith"
 *
 * @file URLify.cpp
 * @author Hardik Garg
 */
#include <iostream>
using namespace std;

void RemoveSpaces(string& str, size_t str_length ) 
{
	size_t from_index = str_length - 1;
	cout<<from_index<<endl;
    
	size_t to_index   = str.length() - 1;
    cout<<to_index<<endl;
    
    //Run the loop while the original len != new len
	while ( from_index != to_index ) {
        if ( str[from_index] != ' ' ) {
            str[to_index--] = str[from_index--];
        } else {
            str[to_index--] = '0';
            str[to_index--] = '2';
            str[to_index--] = '%';

            --from_index;
        }
    }
    //print the modified string
    cout<<str<<endl;
}

/*Can use below function also. The algorithm employs a two-scan approach. In the first scan, we
count the number of spaces. By tripling this number, we can compute how many extra characters we will
have in the final string. In the second pass, which is done in reverse order, we actually edit the string. When
we see a space, we replace it with %20. If there is no space, then we copy the original character.*/
/*
void RemoveSpaces(char str[],size_t original_len)
{
	char *final=str;
	
	//In the first pass, calculate the total no of white spaces
	size_t WhiteSpace=0;
	for(size_t i=0;i<original_len;++i)
	{
		if(str[i]==' ')
		{
			++WhiteSpace;
		}
	}	
	//calculate the new length based on no of white spaces
	size_t new_len=original_len+WhiteSpace*2;
	str[new_len]='\0';
	
	//In the second pass, starting from the string end, replace
	//the white spaces
	for(size_t i=original_len-1;i!=-1;--i)
	//or we  can also use for(size_t=original_len; i-- > 0;)
	{
		if(str[i]==' ')
		{
			str[new_len-1]='0';
			str[new_len-2]='2';
			str[new_len-3]='%';
			new_len=new_len-3;
		}
		else
		{
			str[new_len-1]=str[i];
			new_len=new_len-1;
		}
	}
	cout<<final<<endl;
}
*/

int main(int argc, char** argv) {
	//char str[]="ha dik";
	//size_t length=sizeof(str);
	string str="ha dik  ";
	RemoveSpaces(str,6);
	return 0;
}
