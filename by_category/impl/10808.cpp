// https://www.acmicpc.net/problem/10808
// 2022-03-11 02:39:45 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s; cin >> s;
    array<int, 26> arr={0};
    for(auto i : s)
        arr[i-'a']++;

    for(auto i : arr)
        printf("%d ", i);
}

/*
    
*/