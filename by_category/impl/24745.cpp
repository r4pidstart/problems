// https://www.acmicpc.net/problem/24745
// 2022-04-28 20:09:42 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	// . -> 0, - -> 1
	string morse_code_alpha[]={
		"01", "1000", "1010", "100", "0", "0010", "110", "0000", "00", "0111", "101", "0100",
		"11", "10", "111", "0110", "1101", "010", "000", "1", "001", "0001", "011", "1001",
		"1011", "1100"
	};
	string morse_code_num[]={
		"11111", "01111", "00111", "00011", "00001", "00000", "10000", "11000", "11100", "11110"
	};

	string s; getline(cin, s);
	string coded="";
	for(auto c : s)
	{
		if(isdigit(c))
			coded+=morse_code_num[c-'0'];
		else if(isalpha(c))
			coded+=morse_code_alpha[tolower(c)-'a'];
	}

	for(int i=0; i<coded.length()/2; i++)
	{
		if(coded[i] != coded[coded.length() - 1 - i])
			return !printf("NO");
	}
	if(coded.size() == 0) printf("NO");
	else printf("YES");
}

/*
	
*/