// https://www.acmicpc.net/problem/1264
// 2022-06-19 04:10:25 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    string s; getline(cin, s);
    while(s!="#")
    {
        int cnt=0;
        for(char c : s)
            if(c=='a' or c=='A' or c=='e' or c=='E' or c=='i' or c=='I' or c=='o' or c=='O' or c=='u' or c=='U')
                cnt++;
        printf("%d\n", cnt);
        getline(cin, s);
    }
}

/*
    
*/