// https://www.acmicpc.net/problem/21236
// 2021-10-20 20:31:55 48ms
#include<bits/stdc++.h>
using namespace std;

const int mov[4][2]={{0,1}, {1,0}, {-1,0}, {0,-1}};
int main(void)
{
    int n; scanf("%d", &n);
    vector<vector<int> > cow(1005, vector<int>(1005,0));
    // x+2, y+2 사용

    int ansCnt=0;
    for(int i=0; i<n; i++)
    {
        int x,y; scanf("%d%d", &x, &y);
        x+=2, y+=2;

        int adjCnt=0;
        for(int i=0; i<4; i++)
            if(cow[x+mov[i][0]][y+mov[i][1]]) adjCnt++;
        if(adjCnt==3) ansCnt++;

        for(int i=0; i<4; i++)
        {
            adjCnt=0;
            for(int j=0; j<4; j++)
                if(cow[x+mov[i][0]][y+mov[i][1]] && cow[x+mov[i][0]+mov[j][0]][y+mov[i][1]+mov[j][1]]) adjCnt++;
            if(adjCnt==3) ansCnt--;
            if(adjCnt==2) ansCnt++;
        }
        cow[x][y]++;
        printf("%d\n", ansCnt);
    }
}

/*
    
*/