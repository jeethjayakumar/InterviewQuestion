#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

string breakPalindrome(string palindromeStr);
void displayInputOutput(string input, string output);
int main()
{
	displayInputOutput("bab", breakPalindrome("bab"));
	displayInputOutput("aaaa", breakPalindrome("aaaa"));
	displayInputOutput("acca", breakPalindrome("acca"));
	return 0;
}

// JJ: Function implemented under the assumption that passed string is Palindrome
string breakPalindrome(string palindromeStr)
{
	if (!palindromeStr.empty())
	{
		for(int i = 0; i < palindromeStr.length(); i++)
		{
			if (palindromeStr[i] != 'a')
			{
				palindromeStr[i] = 'a';
				return palindromeStr;
			}	
		}
	}

	return "IMPOSSIBLE";
}

void displayInputOutput(string input, string output)
{
	cout<<"Input: "<<input<<endl;
	cout<<"Output: "<<output<<endl;
}
