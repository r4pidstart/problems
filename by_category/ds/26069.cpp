// https://www.acmicpc.net/problem/26069
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    map<string, bool> ma;
    ma["ChongChong"]=true;
    while(n--)
    {
        string a,b; cin >> a >> b;
        ma[a]=ma[b]=max(ma[a], ma[b]);
    }

    int cnt=0;
    for(auto it : ma)
        cnt+=it.second;
    printf("%d", cnt);
}

/*
    
*/