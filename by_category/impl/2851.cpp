// https://www.acmicpc.net/problem/2851
// 2022-03-30 23:58:02 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n=10;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int tmp=accumulate(arr.begin(), arr.begin() + i+1, 0);
        if(abs(100 - tmp) < abs(100 - ans) or (abs(100 - tmp) == abs(100 - ans) and tmp > ans))
            ans = tmp;
    }
    printf("%d", ans);
}

/*
    
*/