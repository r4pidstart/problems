// https://www.acmicpc.net/problem/10798
// 2022-03-21 23:52:20 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<string> strs(5);
    cin >> strs[0] >> strs[1] >> strs[2] >> strs[3] >> strs[4];
    for(int i=0; i<15; i++)
        for(string s : strs)
        {
            if(i < s.size())
                printf("%c", s[i]);
        }
}

/*
    
*/