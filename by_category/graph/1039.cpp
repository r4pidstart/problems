// https://www.acmicpc.net/problem/1039
// 2022-06-27 22:23:59 108ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,k; scanf("%d%d", &n, &k);
    
    vector<vector<int> > visited(1000001, vector<int>(k+1));
    queue<pair<int,int> > q;
    q.push({n, 0});

    if(n < 10)
        return !printf("-1");
    int ans=-1;
    while(q.size())
    {
        int num=q.front().first, cnt=q.front().second;
        q.pop();
        
        if(cnt == k)
        {
            ans=max(ans, num);
            continue;
        }

        string s=to_string(num);
        for(int i=0; i<s.length(); i++)
            for(int j=i+1; j<s.length(); j++)
            {
                swap(s[i], s[j]);
                int next=stoi(s);
                //printf("%d %d\n", num, next);
                if(s[0]!='0' and !visited[next][cnt+1])
                {
                    visited[next][cnt+1]++;
                    q.push({next, cnt+1});
                }
                swap(s[i], s[j]);
            }
    }
    printf("%d", ans);
}

/*
    
*/