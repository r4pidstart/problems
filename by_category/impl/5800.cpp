// https://www.acmicpc.net/problem/5800
// 2022-07-20 00:30:15 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int k; scanf("%d", &k);
    for(int t=1; t<=k; t++)
    {
        int n; scanf("%d", &n);
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        sort(arr.begin(), arr.end());
        int maxdif=0;
        for(int i=0; i<n-1; i++)
            maxdif=max(arr[i+1]-arr[i], maxdif);
        printf("Class %d\nMax %d, Min %d, Largest gap %d\n", t, arr[n-1], arr[0], maxdif);
    }
}

/*
    
*/