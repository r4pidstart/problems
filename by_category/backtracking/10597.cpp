// https://www.acmicpc.net/problem/10597
// 2024-06-08 22:00:07
#include"bits/stdc++.h"
#define scanf(...) do not use this
#define printf(...) do not use this
using namespace std;

int get_ans(int now, const string& s, vector<int>& used, vector<int>& ans)
{
    if(now==s.length())
    {
        int flag=0;
        for(int i=1; i<=ans.size(); i++)
            if(!used[i])
                flag=1;
        return flag;
    }
    
    for(int i=1; i<=s.length()-now and i<3; i++)
    {
        int tmp=stoi(s.substr(now, i));
        if(tmp>50) continue;

        if(!used[tmp])
        {
            used[tmp]=1;
            ans.push_back(tmp);
            if(!get_ans(now+i, s, used, ans))
                return 0;
            ans.pop_back();
            used[tmp]=0;
        }
    }
    return 1;
}

int main(void)
{
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    vector<int> used(51);
    vector<int> ans;

    string s; cin >> s;
    get_ans(0, s, used, ans);

    for(int i : ans)
        cout << i << ' ';
}

/*
    
*/