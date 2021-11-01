// https://www.acmicpc.net/problem/17952
// 2021-10-30 22:55:28 208ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    stack<pair<int, int> > tasks;
    int score=0;
    // remaining, score
    for(int i=0; i<n; i++)
    {
        int cmd; scanf("%d", &cmd);
        if(cmd)
        {
            int a,b; scanf("%d%d", &a,&b);
            if(b==1) score+=a;
            else tasks.push({b-1, a});
        }
        else
        {
            if(!tasks.empty())
            {
                auto tmp=tasks.top();
                tasks.pop();
                if(tmp.first==1) score+=tmp.second;
                else tasks.push({tmp.first-1, tmp.second});
            }
        }
    }
    printf("%d", score);
}

/*
    
*/