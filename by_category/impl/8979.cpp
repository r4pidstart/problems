// https://www.acmicpc.net/problem/8979
// 2022-04-01 03:43:35 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    struct rank
    {
        int n, g, s, b;
        bool operator<(const rank& a)
        {
            return g != a.g ? (g<a.g) : (s != a.s ? (s<a.s) : (b != a.b ? (b<a.b) : 0));
        }
        // bool operator==(const rank &a)
        // {
        //     return g==a.g and s==a.s and b==a.b;
        // }
    };

    int n,k,target; scanf("%d%d", &n, &k);
    vector<rank> arr(n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d%d%d", &arr[i].n, &arr[i].g, &arr[i].s, &arr[i].b);
        if(arr[i].n == k) target=i;
    }
    
    int ans=1;
    for(int i=0; i<n; i++)
        if(arr[target] < arr[i]) ans++;
    printf("%d", ans);
}

/*
    
*/