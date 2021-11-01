// https://www.acmicpc.net/problem/23322
// 2021-11-02 00:08:11 C
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    // 시뮬레이션?
    int n,k; scanf("%d%d", &n,&k);
    vector<int> arr(n);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    int cnt=0, days=0;
    for(int i=k; i<n; i++)
    {
        while(arr[i] > arr[i-k])
        {
            days++, cnt+=arr[i]-arr[i-k];
            arr[i]=arr[i-k];
            sort(arr.begin(), arr.end());
        }
    }
    printf("%d %d", cnt, days);
}

/*
    
*/