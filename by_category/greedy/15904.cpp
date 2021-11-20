// https://www.acmicpc.net/problem/15904
// 2021-11-21 03:12:05 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; getline(cin, s);
    vector<char> seq={'U','C','P','C'};
    int idx=0;
    for(int i=0; i<s.length(); i++)
        if(idx < 4 and s[i]==seq[idx]) idx++;

    printf("%s", idx!=4 ? "I hate UCPC":"I love UCPC");
}

/*
    
*/