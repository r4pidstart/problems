// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    vector<int> arr(10,0);
    int digitsSum=0;
    for(int i=0; i<s.length(); i++) arr[s[i]-'0']++, digitsSum+=s[i]-'0';
    
    if(digitsSum%3 or !arr[0]) return !printf("-1");

    for(int i=9; i>=0; i--)
        for(int j=0; j<arr[i]; j++)
            printf("%d", i);
}

/*
    
*/