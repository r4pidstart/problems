// https://www.acmicpc.net/problem/25192
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    string s; cin >> s;

    int cnt=0;
    set<string> se;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        if(s==(string)"ENTER")
            se.clear();
        else
            if(se.find(s) == se.end()) cnt++, se.insert(s);
    }
    cout << cnt;
}

/*
    
*/