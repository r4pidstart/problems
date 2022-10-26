// https://www.acmicpc.net/problem/2910
// 2022-10-27 00:33:40
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n,c; scanf("%d%d", &n, &c);
    map<int, pair<int, int> > m;
    for(int i=0; i<n; i++)
    {
        int a;
        scanf("%d", &a);
        if(m.find(a) == m.end())
            m[a].second=i;
        m[a].first++;
    }

    vector<pair<pair<int, int> ,int> > tmp;
    for(auto it : m)    
        tmp.push_back({{it.second.first, -it.second.second}, it.first});
    
    stable_sort(tmp.begin(), tmp.end(), greater<>());
    for(auto it : tmp)
    {
        while(it.first.first--)
            printf("%d ", it.second);
    }
}

/*
    
*/