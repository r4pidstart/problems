// https://www.acmicpc.net/problem/15953
// 2022-03-26 07:09:20 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    vector<vector<int> > prize_table(2);
    prize_table[0]={500, 300, 300, 200, 200, 200, 50, 50, 50, 50, 30, 30, 30, 30, 30, 10, 10, 10, 10, 10, 10};
    prize_table[1]={512, 256, 256, 128, 128, 128, 128, 64, 64, 64, 64, 64, 64, 64, 64, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32};

    while(t--)
    {
        int a,b; scanf("%d%d", &a, &b);
        a--, b--;
        int ans=0;
        if(a>=0 and a < prize_table[0].size()) ans+=prize_table[0][a];
        if(b>=0 and b < prize_table[1].size()) ans+=prize_table[1][b];
        printf("%d\n", ans*10000);
    }
}

/*
    
*/