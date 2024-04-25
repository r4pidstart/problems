// https://www.acmicpc.net/problem/16678
// 2024-04-12 00:16:08
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    sort(arr.begin(), arr.end());
    long ans=0, prev=1;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==prev-1)
            continue;
        else
            ans+=arr[i]-prev, prev++;
    }
    printf("%ld", ans);
}

/*
    
*/