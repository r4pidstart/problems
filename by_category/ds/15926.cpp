// https://www.acmicpc.net/problem/15926 
// 2023-10-25 04:40:14
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    string s; cin >> s;
    
    int ans=0;
    deque<pair<int, int> > dq;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='(')
            dq.push_back({1, 0});
        else
        {
            if(dq.size() and dq.back().first)
                dq.pop_back(), dq.push_back({0, 2});
            else if(dq.size()>1 and dq[dq.size()-2].first)
                dq[dq.size()-2]={0, dq.back().second+2}, dq.pop_back();
            else
                dq=deque<pair<int, int> >();

            if(dq.size()>1 and !dq[dq.size()-2].first and !dq.back().first)
                dq[dq.size()-2].second+=dq.back().second, dq.pop_back();
        }
        if(dq.size())
            ans=max(ans, dq.back().second);
    }
    printf("%d", ans);
}

/*
    
*/