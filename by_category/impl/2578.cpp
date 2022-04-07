// https://www.acmicpc.net/problem/2578
// 2022-04-08 01:12:13 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<vector<int> > table(5, vector<int>(5));
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            scanf("%d", &table[i][j]);
    
    set<int> se;
    for(int n=1; n<=25; n++)
    {
        int t; scanf("%d", &t);
        se.insert(t);

        int bingo_cnt=0;

        for(int i=0; i<5; i++) // 가로
        {
            int cnt=0;
            for(int j=0; j<5; j++)
                if(se.find(table[i][j]) != se.end()) cnt++;
            if(cnt == 5) bingo_cnt++;
        }

        for(int i=0; i<5; i++) // 세로
        {
            int cnt=0;
            for(int j=0; j<5; j++)
                if(se.find(table[j][i]) != se.end()) cnt++;
            if(cnt == 5) bingo_cnt++;
        }

        int cnt=0;
        for(int i=0; i<5; i++) // 대각 1
            if(se.find(table[i][i]) != se.end()) cnt++;
        if(cnt == 5) bingo_cnt++;
    
        cnt=0;
        for(int i=0; i<5; i++) // 대각 2
            if(se.find(table[i][5-i-1]) != se.end()) cnt++;
        if(cnt == 5) bingo_cnt++;


        if(bingo_cnt >= 3)
            return !printf("%d", n);
    }
}

/*
    
*/