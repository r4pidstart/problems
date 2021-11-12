// https://www.acmicpc.net/problem/23056
// 2021-11-13 00:16:37 B
#include<bits/stdc++.h>
using namespace std;

class Comp
{
    public:
    bool operator()(const string& a, const string& b) const
    {
        if(a.length()==b.length()) return a<b;
        else return a.length()<b.length();
    }
};

int main(void)
{
    map<int, set<string, Comp> > blue, white;
    int n,m; scanf("%d%d", &n,&m);
    while(true)
    {
        int a; string s;
        cin >> a >> s;
        if(a==0 and s=="0") break;
        if(a > n) continue;
        else if(a&1) 
        {
            if(blue[a].size()<m) blue[a].insert(s);
        }
        else
        {
            if(white[a].size()<m) white[a].insert(s);
        }
    }    

    for(auto it : blue)
        for(auto s : it.second)
            cout << it.first << " " << s << '\n';
    for(auto it : white)
        for(auto s : it.second)
            cout << it.first << " " << s << '\n';
}

/*
    
*/