// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        string a,b,c;
        cin >> a >> b >> c;
        queue<pair<int,int> > q;
        vector<vector<int> > visited(a.length()+1, vector<int>(b.length()+1,0));
        q.push({0,0});
        int flag=0;
        while(!q.empty())
        {
            auto now=q.front(); q.pop();

            if(now.first+now.second > c.length())
            {
                flag=1;
                continue;
            }

            if(visited[now.first][now.second]) continue;
            visited[now.first][now.second]=1;


            if(a[now.first]==c[now.first+now.second])
                q.push({now.first+1, now.second});
            if(b[now.second]==c[now.first+now.second])
                q.push({now.first, now.second+1});
        }
        printf("Data set %d: %s\n", i+1, flag ? "yes":"no");
    }
}

/*
    
*/