// https://www.acmicpc.net/problem/10987
// 2022-03-25 00:36:08 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    printf("%d", count_if(s.begin(), s.end(), [](char c) {return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';}));
}

/*
    
*/