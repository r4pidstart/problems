// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        long long ans=0;
        int n; scanf("%d", &n);
        vector<int> arr(n);
        for(int i=0; i<n; i++) scanf("%d", &arr[i]);

        for(int i=0; i<n; i++)
            for(int j=0; j<i; j++)
                ans+=gcd(arr[i], arr[j]);
        printf("%lld\n", ans);
    }
}

/*
    1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000 1000000
*/