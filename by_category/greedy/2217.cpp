// https://www.acmicpc.net/problem/2217
// 2021-09-23 03:01:40 16ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> ropes(n, 0);

    for(int i=0; i<n; i++)
        scanf("%d", &ropes[i]);
    
    sort(ropes.begin(), ropes.end(), greater<int>());
    
    int ans=0;
    for(int i=0; i<n; i++)
        ans=max(ans, ropes[i]*(i+1));
    
    printf("%d", ans);
}

/*
    
*/