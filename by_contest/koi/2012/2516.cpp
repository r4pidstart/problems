// https://www.acmicpc.net/problem/2516
// 2022-05-21 03:56:03 96ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> group(n+1);
    vector<vector<int> > rival(n+1);
    for(int i=0; i<n; i++)
    {
        int a; scanf("%d", &a);
        while(a--)
        {
            int b; scanf("%d", &b);
            rival[i+1].push_back(b);
        }
    }

    while(true)
    {
        int flag=0;
        for(int i=1; i<=n; i++)
        {
            int cnt=0;
            for(int r : rival[i])
                cnt+=(group[i] == group[r]);
            if(cnt > 1)
                group[i]^=1, flag++;
        }

        if(!flag) break;
    }
    
    int g1_cnt=0;
    for(int i=1; i<=n; i++)
        if(group[i]) g1_cnt++;

    if(g1_cnt==0)
    {
        printf("1 1\n%d ", n-1);
        for(int i=2; i<=n; i++)
            printf("%d ", i);
    }
    else
    {
        printf("%d ", n-g1_cnt);
        for(int i=1; i<=n; i++)
            if(!group[i]) printf("%d ", i);
        printf("\n%d ", g1_cnt);
        for(int i=1; i<=n; i++)
            if(group[i]) printf("%d ", i);
    }
}

/*
    
*/