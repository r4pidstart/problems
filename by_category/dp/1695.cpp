// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<vector<int> > memo;

int dp(int l, int r)
{
    if(l>r) return 0;
    if(memo[l][r] != -1) return memo[l][r];

    int& ret=memo[l][r];
    if(arr[l]==arr[r]) 
    {   ret=dp(l+1, r-1);  }
    else 
    {   ret=min(dp(l+1,r), dp(l,r-1))+1;    }
    return ret;
}

int main(void)
{
    int n; scanf("%d", &n);
    arr.assign(n,0);
    for(int i=0; i<n; i++) scanf("%d", &arr[i]);

    memo.assign(n, vector<int>(n,-1));
    // memo[i][j] : i~j까지를 팰린드롬으로 만들기 위해 필요한 최소 횟수
    for(int i=0; i<n; i++) memo[i][i]=0;
    printf("%d", dp(0,n-1));
}

/*
    
*/