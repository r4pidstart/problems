// https://www.acmicpc.net/problem/2800
// 2024-07-13 12:32:30
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    string s; cin >> s;
    // find all parens
    vector<int> paren_idx(s.size()+1, -1);
    stack<int> stk;
    int idx=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(')
            stk.push(idx), paren_idx[i]=idx++;
        else if(s[i]==')')
            paren_idx[i]=stk.top(), stk.pop();
    }

    set<string> ans;
    for(int i=0; i<=idx; i++)
    {
        vector<int> permu(idx, 1);
        fill(permu.begin(), permu.begin()+i, 0);

        do
        {
            string tmp="";
            for(int i=0; i<s.size(); i++)
            {
                if(paren_idx[i]==-1) tmp+=s[i];
                else if(permu[paren_idx[i]]) tmp+=s[i];
            }
            ans.insert(tmp);
        } while (next_permutation(permu.begin(), permu.end()));
    }

    ans.erase(s);
    for(string s : ans)
        cout << s << '\n';

}

/*
    
*/
