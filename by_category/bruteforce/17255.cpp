// https://www.acmicpc.net/problem/17255
// 2024-07-08 23:07:36
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int solution(string& s, string& history, set<string>& set)
{
    if(s=="")
        set.insert(history);
    else
    {
        string next_his=history+s;

        string pf=s.substr(1);
        solution(pf, next_his, set);
        string pb=s.substr(0, s.size()-1);
        solution(pb, next_his, set);
    }
    return 0;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n; cin >> n;
    string s=to_string(n), his="";
    set<string> se;
    solution(s, his, se);
    cout << se.size();
}

/*
    
*/
