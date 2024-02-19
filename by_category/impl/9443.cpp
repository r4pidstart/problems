// https://www.acmicpc.net/problem/9443
// 2024-02-13 05:52:07
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(27);
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        arr[s[0]-'A']++;
    }

    for(int i=0; i<27; i++)
    {
        if(!arr[i])
            return !printf("%d", i);
    }
}

/*
    
*/