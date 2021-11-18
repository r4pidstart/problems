// https://www.acmicpc.net/problem/23350
// 2021-11-19 01:09:41 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    priority_queue<int> pq;
    queue<pair<int, int> > q;
    stack<pair<int, int> > stk;
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a,&b);
        q.push({a,b});
        pq.push(a);
    }

    int ans=0;
    while(!q.empty())
    {
        if(pq.top() == q.front().first)
        {
            // monotone stack
            stack<pair<int,int> > tmp;
            while(!stk.empty() and q.front().second > stk.top().second and q.front().first == stk.top().first)
            {
                tmp.push(stk.top());
                ans+=2*stk.top().second;
                stk.pop();
            }
            stk.push(q.front());
            ans+=q.front().second;
            q.pop();
            while(!tmp.empty())
                stk.push(tmp.top()), tmp.pop();

            pq.pop();
        }
        else
        {
            q.push(q.front());
            ans+=q.front().second;
            q.pop();
        }
    }
    printf("%d", ans);
}

/*
    
*/