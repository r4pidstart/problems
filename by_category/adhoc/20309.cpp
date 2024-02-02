// https://www.acmicpc.net/problem/20309
// 2024-02-03 01:27:53
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++) 
        scanf("%d", &arr[i]);
    
    vector<int> odd, even;
    for(int i=0; i<n; i++)
        if(i&1) odd.push_back(arr[i]);
        else even.push_back(arr[i]);
    
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());

    vector<int> tmp(n);
    int io=0, ie=0;
    for(int i=0; i<n; i++)
    {
        if(i&1) tmp.push_back(odd[io++]);
        else tmp.push_back(even[ie++]);
    }

    vector<int> origin=tmp;
    sort(tmp.begin(), tmp.end());

    printf(origin == tmp ? "YES":"NO");
}

/*
    
*/