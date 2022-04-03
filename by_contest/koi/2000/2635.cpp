// https://www.acmicpc.net/problem/2635
// 2022-04-03 14:38:23 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);

    vector<int> ans;
    for(int i=1; i<=n; i++)
    {
        vector<int> tmp;
        tmp.push_back(n);
        tmp.push_back(i);
        while(tmp[tmp.size()-2] - tmp[tmp.size()-1] >= 0)
            tmp.push_back(tmp[tmp.size()-2] - tmp[tmp.size()-1]);
        if(ans.size() < tmp.size())
            ans = tmp;
    }   
    printf("%d\n", ans.size());
    for(auto i : ans)
        printf("%d ", i);
}

/*
    
*/