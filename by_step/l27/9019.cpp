// https://www.acmicpc.net/problem/9019
// 2021-04-29 17:27:19 976ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int a,b; scanf("%d%d", &a, &b);
        vector<pair<int, char> > memo(10001, {-1,0});
        // ~에서 ~ 연산을 이용해 도착
        queue<int> q;
        q.push(a);
        while(true)
        {
            int now=q.front();
            q.pop();

            int next=now*2%10000;
            if(memo[next].first==-1)
            {
                memo[next]={now, 'D'};
                q.push(next);
                if(next==b)
                    break;
            }

            next=(now+10000-1)%10000;
            if(memo[next].first==-1)
            {
                memo[next]={now, 'S'};
                q.push(next);
                if(next==b)
                    break;
            }

            next=now/1000 % 10 + now/100 % 10 * 1000 + now/10 % 10 * 100 + now/1 % 10 * 10;
            if(memo[next].first==-1)
            {
                memo[next]={now, 'L'};
                q.push(next);
                if(next==b)
                    break;
            }

            next=now/1000 % 10 * 100 + now/100 % 10 * 10 + now/10 % 10 + now/1 % 10 * 1000;
            if(memo[next].first==-1)
            {
                memo[next]={now, 'R'};
                q.push(next);
                if(next==b)
                    break;
            }
        }
        stack<char> ans;
        int pointer=b;
        while(pointer!=a)
        {
            ans.push(memo[pointer].second);
            pointer=memo[pointer].first;
        }
        while(!ans.empty())
        {
            printf("%c", ans.top());
            ans.pop();
        }
        printf("\n");
    }
}