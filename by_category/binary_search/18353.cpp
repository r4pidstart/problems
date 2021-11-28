// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n), dp;
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);
    reverse(arr.begin(), arr.end());
    for(int i=0; i<n; i++)
    {
        auto it=lower_bound(dp.begin(), dp.end(), arr[i]);
        if(it==dp.end()) dp.push_back(arr[i]);
        else *it=arr[i];
    }
    printf("%d", n-dp.size());
}

/*
    
*/