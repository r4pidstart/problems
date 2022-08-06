// https://www.acmicpc.net/problem/2992
// 2022-08-07 05:42:03
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    string s; cin >> s;
    int target=stoi(s), ans=INT32_MAX;
    sort(s.begin(), s.end());
    do
    {
        if(stoi(s) > target)
            ans=min(stoi(s), ans);
    } while (next_permutation(s.begin(), s.end()));
    cout << (ans!=INT32_MAX ? ans:0);
}

/*
    
*/