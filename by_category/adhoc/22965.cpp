// https://www.acmicpc.net/problem/22965
// 2024-03-11 23:53:16
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    vector<int> sorted=arr;
    sort(sorted.begin(), sorted.end());
    
    int cnt=0;
    for(int i=1; i<n; i++)
    {
        int now=lower_bound(sorted.begin(), sorted.end(), arr[i])-sorted.begin();
        int prev=lower_bound(sorted.begin(), sorted.end(), arr[i-1])-sorted.begin();
        if(now!=prev+1)
            cnt++;
    }

    cnt=min(cnt, 2);
    printf("%d", cnt+1);
}

/*
    
*/