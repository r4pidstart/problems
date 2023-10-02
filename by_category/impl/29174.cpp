// https://www.acmicpc.net/problem/29174
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    map<int, int> marbles;
    while(n--)
    {
        int a; scanf("%d", &a);
        marbles[a]++;
    }
    int q; scanf("%d", &q);
    while(q--)
    {
        int flag=0;

        int a_i; scanf("%d", &a_i); 
        map<int, int> a; 
        while(a_i--)
        {
            int t; scanf("%d", &t);
            a[t]++;
            if(a[t] > marbles[t])
                flag=1;
        }
        if(!flag)
            for(auto& [t, c] : a)
                marbles[t]-=c;

        int b_i; scanf("%d", &b_i);
        while(b_i--)
        {
            int t; scanf("%d", &t);
            if(!flag)
                marbles[t]++;
        }
    }
    
    int cnt=0;
    vector<int> print_buf;
    for(auto& [t, c] : marbles)
    {
        cnt+=c;
        while(c--)
            print_buf.push_back(t);
    }
    printf("%d\n", cnt);
    for(int i : print_buf)
        printf("%d ", i);
}

/*
    
*/