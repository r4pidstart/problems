// https://www.acmicpc.net/problem/23627
// 2021-11-25 12:23:40 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    if(s.length() < 5) return !printf("not cute");
    if(s.substr(s.length()-5) == "driip") printf("cute");
    else printf("not cute");
}

/*
    
*/