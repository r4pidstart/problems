// https://www.acmicpc.net/problem/2669
// 2022-03-29 01:04:16 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<vector<int> > table(101, vector<int>(101));
    int ans=0;
    for(int i=0; i<4; i++)
    {
        int a,b,c,d; scanf("%d%d%d%d", &a, &b, &c, &d);
        for(int i=a; i<c; i++)
            for(int j=b; j<d; j++)
                table[i][j] ? 0 : (table[i][j]=1, ans++);
    }
    printf("%d", ans);
}

/*
    
*/