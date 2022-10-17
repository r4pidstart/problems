// https://www.acmicpc.net/problem/17615
// 2022-10-16 09:28:54 24ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    string s; cin >> s;

    int b_cnt=0, b_max=0, r_cnt=0, r_max=0;

    int tmp=0, color=s[0];
    for(int i=0; i<n; i++)
    {
        if(s[i] == color) tmp++;
        else if(color != -1)
        {
            if(color == 'B') b_max=tmp;
            else r_max=tmp;
            color=-1;
        }
        
        if(s[i] == 'B') b_cnt++;
        else r_cnt++;
    }

    tmp=0, color=s[n-1];
    for(int i=n-1; i>=0; i--)
    {
        if(s[i] == color) tmp++;
        else if(color != -1)
        {
            if(color == 'B') b_max=max(tmp, b_max);
            else r_max=max(tmp, r_max);
            color=-1;
        }
    }

    printf("%d", min(r_cnt - r_max, b_cnt - b_max));
}

/*
    
*/