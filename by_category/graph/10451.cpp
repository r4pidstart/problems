// https://www.acmicpc.net/problem/10451
// 2022-03-22 22:03:52 60ms
#include<bits/stdc++.h>
using namespace std;

int dfs(int now, vector<int>& arr, vector<int>& visit)
{
    if(visit[now]) return 0;
    visit[now]++;
    return dfs(arr[now], arr, visit);
}

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector<int> arr(n+1);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i+1]);

        int cnt=0;
        vector<int> visited(n+1);
        for(int i=1; i<=n; i++)
        {
            if(!visited[i]) cnt++;
            dfs(i, arr, visited);
        }
        printf("%d\n", cnt);
    }
}

/*
    
*/