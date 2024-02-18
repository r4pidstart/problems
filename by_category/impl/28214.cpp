// https://www.acmicpc.net/problem/28214
// 2024-02-18 11:43:11
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k,p; scanf("%d%d%d", &n, &k, &p);
    vector<int> arr(n);
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int cnt=0;
        for(int j=0; j<k; j++)
        {
            int a; scanf("%d", &a);
            cnt+=a;    
        }
        if(k-cnt<p) ans++;
    }
    printf("%d", ans);
}

/*
    
*/