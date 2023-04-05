// https://www.acmicpc.net/problem/27930
// 2023-04-05 23:39:07 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s1="KOREA", s2="YONSEI";
    int idx1=0, idx2=0;
    string s; cin >> s;
    for(char c : s)
    {
        if(c==s1[idx1]) idx1++;
        if(c==s2[idx2]) idx2++;
        if(idx1 == s1.size()) return !printf("KOREA");
        if(idx2 == s2.size()) return !printf("YONSEI");
    }
}

/*
    
*/