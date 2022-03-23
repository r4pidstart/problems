// https://www.acmicpc.net/problem/1120
// 2022-03-23 22:51:25 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string s1, s2; cin >> s1 >> s2;

    queue<string> q;
    unordered_set<string> us;
    q.push(s2);
    // s2에서 한글자씩 빼보기
    int ans=INT32_MAX;
    while(!q.empty())
    {
        string s=q.front(); q.pop();
        if(us.find(s) != us.end()) continue;

        us.insert(s);
        if(s.length()==s1.length())
        {
            int tmp=0;
            for(int i=0; i<s.length(); i++)
                if(s[i] != s1[i]) tmp++;
            ans=min(tmp, ans);
        }
        else
        {
            q.push(s.substr(1));
            q.push(s.substr(0, s.size()-1));
        }
    }
    printf("%d", ans);
}

/*
    
*/