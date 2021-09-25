// https://www.acmicpc.net/problem/19941
// 2021-09-25 23:54:24 0ms
#include<bits/stdc++.h>
using namespace std;

inline int getNext(int now, int type, vector<char>& table)
{
    // type 1 - H
    if(type)
    {
        for(int i=now+1; i<table.size(); i++)
            if(table[i]=='H') return i;
    }
    else
    {
        for(int i=now+1; i<table.size(); i++)
            if(table[i]=='P') return i;
    }
    return table.size();
}

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    vector<char> table(n);
    for(int i=0; i<n; i++)
        scanf(" \n%c", &table[i]);
    
    int hc=getNext(-1,1,table), pc=getNext(-1,0,table), ans=0;
    while(hc!=table.size() && pc!=table.size())
    {
        if(abs(pc-hc)<=k)
        {
            ans++;
            pc=getNext(pc,0,table);
            hc=getNext(hc,1,table);
        }
        // 사람이 앞에 있으면
        else if(pc-hc > 0) hc=getNext(hc,1,table);
        else pc=getNext(pc,0,table);
    }
    printf("%d", ans);
}

/*
    
*/