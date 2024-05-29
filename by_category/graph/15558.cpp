// https://www.acmicpc.net/problem/15558
// 
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,k; cin >> n >> k;
    vector<string> arr(2); cin >> arr[0] >> arr[1];
    arr[0].resize(n+k+1, '1'), arr[1].resize(n+k+1, '1');

    vector<vector<int> > visited(2, vector<int>(n+k+1));
    queue<tuple<int, int, int> > q;
    q.push({0, 1, 0});
    visited[0][1]=1;

    while(q.size())
    {
        auto [row, now, t]=q.front();
        q.pop();

        if(!visited[row][now+1] and arr[row][now]=='1' and now+1>t+1)
        {
            if(now+1 > n)
                return cout << 1, 0;
            q.push({row, now+1, t+1}), visited[row][now+1]=1;
        }

        if(now-1 > 0 and !visited[row][now-1] and arr[row][now-2]=='1' and now-1>t+1)
            q.push({row, now-1, t+1}), visited[row][now-1]=1;
        
        if(!visited[row^1][now+k] and arr[row^1][now+k-1]=='1' and now+k>t+1)
        {
            if(now+k > n)
                return cout << 1, 0;
            q.push({row^1, now+k, t+1}), visited[row^1][now+k]=1;
        }
    }
    cout << 0;
}

/*
    
*/