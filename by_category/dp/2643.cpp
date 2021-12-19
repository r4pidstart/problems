// https://www.acmicpc.net/problem/2643
// 2021-12-19 15:35:33 0ms
#include<bits/stdc++.h>
using namespace std;

vector<int> memo;
vector<pair<int,int> > arr;
int dp(int n) // n^2 dp
{
    if(memo[n]!=-1) return memo[n];

    int& ret=memo[n];
    for(int i=0; i<n; i++)
        if((arr[n].first>=arr[i].first and arr[n].second>=arr[i].second))
            ret=max(ret, dp(i)+1);
    dp(n-1);
    return ret;
}

int main(void)
{
    int n; scanf("%d", &n);
    memo.assign(n+1, -1);
    arr.assign(n+1, {});
    memo[0]=0, arr[0]={0,0};
    for(int i=1; i<=n; i++) scanf("%d%d", &arr[i].first, &arr[i].second);
    for(int i=1; i<=n; i++) if(arr[i].first<arr[i].second) swap(arr[i].first, arr[i].second);
    sort(arr.begin(), arr.end());
    dp(n);
    printf("%d", *max_element(memo.begin(), memo.end()));
}

/*

*/