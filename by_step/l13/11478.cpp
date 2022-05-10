// https://www.acmicpc.net/problem/11478
// 2022-05-09 23:54:25 624ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    string s; cin >> s;
    unordered_set<string> se;
    se.insert(s);
    for(int i=0; i<s.length(); i++)
        for(int j=1; j<s.length(); j++)
            se.insert(s.substr(i, j));
    printf("%d", se.size());
}

/*
    
*/