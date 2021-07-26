// https://www.acmicpc.net/problem/5015
// 2021-07-27 05:08:57 4ms
#include<bits/stdc++.h>
using namespace std;

int flag;
vector<vector<int> > visited;
void dp(string p, string s, int a, int b)
{
    if(flag)
        return;

    if(a==p.length() && b==s.length())
    {
        cout << s << '\n';
        flag++;
        return;
    }
    if(a>=p.length() || b>s.length())
        return;
    
    if(visited[a][b])
        return;
    
    visited[a][b]=1;
    
    if(p[a]!='*')
    {
        if(p[a]!=s[b])
            return;
        else
            dp(p, s, a+1, b+1);
    }
    else
    {
        if(a==p.length()-1)
            dp(p, s, p.length(), s.length());
        else
        {
            dp(p, s, a, b+1); // use *
            dp(p, s, a+1, b); // do not use *
        }
    }
}

int main(void)
{
    string p;
    cin >> p;

    int n;
    cin >> n;

    for(int i=0; i<n; i++)
    {
        flag=0;
        string s;
        cin >> s;
        visited.assign(p.length()+1, vector<int>(s.length()+1, 0));
        dp(p, s, 0, 0);
    }
}

/*

*/
