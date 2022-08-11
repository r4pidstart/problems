// https://www.acmicpc.net/problem/12919
// 2022-08-12 04:24:01 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    string s,t; cin >> s >> t;
    map<string, int> m;
    queue<string> q;
    q.emplace(t);

    while(q.size())
    {
        string now=q.front(); q.pop();
        if(now==s)
            return !printf("1");
        
        if(now.back()=='A')
        {
            string next=now.substr(0, now.size()-1);
            if(!m[next])
                q.emplace(next);
        }
        
        if(now.front()=='B')
        {
            string next=now.substr(1);
            reverse(next.begin(), next.end());
            if(!m[next])
                q.emplace(next);
        }
    }
    printf("0");
}

/*
    
*/