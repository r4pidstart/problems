// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    sort(arr.begin(), arr.end(), greater<int>());
    int ans=0;
    for(int i=0; i<n; i++)
    {
        if(i+2 < n) // 3개 이상 더 존재하면?
            ans+=arr[i]+arr[i+1], i+=2;
        else
            ans+=arr[i];
    }
    printf("%d", ans);
}

/*
    
*/