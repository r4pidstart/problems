// https://www.acmicpc.net/problem/6359
// 2022-03-26 05:57:12 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> arr(n+1);
        for(int i=1; i<=n; i++)
            for(int j=i; j<=n; j+=i)
                arr[j]^=1;
        printf("%d\n", accumulate(arr.begin(), arr.end(), 0));
    }
}

/*
    
*/