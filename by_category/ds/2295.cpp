// https://www.acmicpc.net/problem/2295
// 2022-09-30 04:17:56
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<long> arr(n);
    for(int i=0; i<n; i++)
        scanf("%ld", &arr[i]);
    
    set<long> se;
    long ans=0;
    se.insert(arr.begin(), arr.end());
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            se.insert(arr[i]+arr[j]);
    
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(se.find(arr[i] - arr[j]) != se.end())
                ans=max(ans, arr[i]);
        }
    printf("%ld", ans);
}

/*
    
*/