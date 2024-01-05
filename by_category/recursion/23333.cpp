// https://www.acmicpc.net/problem/23333
// 2024-01-05 03:41:26
#include"bits/stdc++.h"
using namespace std;

string minimul(int siz)
{
    string ret="";
    for(int i=0; i<siz; i++)
        ret+="()";
    return ret;
}

int is_maximal(string s)
{
    if(s=="") return 1;

    stack<char> stk;
    for(char c : s)
    {
        if(c==')') stk.pop();
        else stk.push('(');
        if(stk.size()==s.size()/2) 
            return 1;
    }
    return 0;
}

pair<string, string> separate_digion(string s)
{
    stack<char> stk;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==')') stk.pop();
        else stk.push('('); 
        if(!stk.size())
            return {s.substr(0, i+1), s.substr(i+1)};
    }
    return {"", ""};
}

string get_next_digion(string s)
{
    if(is_maximal(s)) // if ((())) like -> ()()()()
        return minimul(s.size()/2+1);

    auto [d1, d2]=separate_digion(s);

    if(is_maximal(d1) and is_maximal(d2))
        return '('+minimul(d1.size()/2)+')'+minimul(d2.size()/2-1);
    if(is_maximal(d2)) // if (()()) ((())) like -> ((())) ((()))
        return '('+get_next_digion(d1.substr(1, d1.size()-2))+')'+minimul(d2.size()/2);
    return d1+get_next_digion(d2);
}

int main(void)
{
#ifdef LOCAL
#endif
    string s; cin >> s;
    if(s.back()=='$')
        s.pop_back();

    cout << get_next_digion(s) << '\n';
}

/*

*/