// https://www.acmicpc.net/problem/13913
// 2021-04-29 01:51:11 20ms
#include<bits/stdc++.h>
using namespace std;

int const LIMIT = 100001;

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    pair<int,int> memo[LIMIT]={};

    queue<int> q;
    q.push(n);
    memo[n]={1,0};
    while(q.front()!=k)
    {
        int now=q.front();
        q.pop();
        if(now-1>=0)
        {
            if(memo[now-1].first==0)
            {
            q.push(now-1);
            memo[now-1]={memo[now].first+1, now};
            }
        }
        if(now+1<LIMIT)
        {
            if(memo[now+1].first==0)
            {
            q.push(now+1);
            memo[now+1]={memo[now].first+1, now};
            }
        }
        if(now*2<LIMIT)
        {
            if(memo[now*2].first==0)
            {
            q.push(now*2);
            memo[now*2]={memo[now].first+1, now};
            }
        }
    }
    printf("%d\n", memo[k].first-1);
    stack<int> ans;
    int index=k;
    while(memo[index].first!=1)
    {
        ans.push(index);
        index=memo[index].second;
    }
    
    printf("%d ", n);
    while(!ans.empty())
    {
        printf("%d ", ans.top());
        ans.pop();
    }
}