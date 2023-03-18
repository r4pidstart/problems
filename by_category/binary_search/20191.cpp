// https://www.acmicpc.net/problem/20191
// 2023-03-18 19:08:04
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    string s,t; cin >> s >> t;

    vector<vector<int> > arr(26);
    for(int i=0; i<t.length(); i++)
        arr[t[i]-'a'].push_back(i);
    
    int cur=-1, cnt=1;
    for(char c : s)
    {
        if(!arr[c-'a'].size())
            return !printf("-1");
        
        auto it=upper_bound(arr[c-'a'].begin(), arr[c-'a'].end(), cur);
        if(it == arr[c-'a'].end()) cnt++, cur=arr[c-'a'].front();
        else cur=*it;
    }
    printf("%d", cnt);
}

/*
    
*/