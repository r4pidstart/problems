// https://www.acmicpc.net/problem/2493
// 2022-01-24 23:11:43 156ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> ans(n);
    stack<pair<int,int> > s;
    for(int i=0; i<n; i++)
    {
        int tmp; scanf("%d", &tmp);
        while(!s.empty() and s.top().second < tmp)
            s.pop();
        if(!s.empty()) ans[i]=s.top().first+1;
        s.push({i, tmp});
    }
    for(auto it : ans)
        printf("%d ", it);
}

/*
    
*/