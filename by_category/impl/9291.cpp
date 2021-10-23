// https://www.acmicpc.net/problem/9291
// 2021-10-23 23:50:54 0ms
#include<bits/stdc++.h>
using namespace std;

int arr[9][9];

int check_complete(void)
{
    for(int i=0; i<9; i++)
    {
        vector<int> sumX(9,0), sumY(9,0);
        for(int j=0; j<9; j++)
        {
            sumX[arr[i][j]-1]=1, sumY[arr[j][i]-1]=1;
        }
        if(accumulate(sumX.begin(), sumX.end(), 0) != 9 or accumulate(sumY.begin(), sumY.end(), 0) != 9) return 0;
    }

    int sx=0, sy=0;
    for(int i=0; i<3; i++)
    {
        sx=0;
        for(int j=0; j<3; j++)
        {
            vector<int> sumS(9,0);
            for(int x=sx; x<sx+3; x++)
                for(int y=sy; y<sy+3; y++)
                    sumS[arr[x][y]-1]=1;
            if(accumulate(sumS.begin(), sumS.end(), 0) != 9) return 0;
            sx+=3;
        }
        sy+=3;
    }
    return 1;
}

int main(void)
{
    int t; scanf("%d", &t);
    for(int T=1; T<=t; T++)
    {
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                scanf("%d", &arr[i][j]);
        printf("Case %d: %s\n", T, check_complete() ? "CORRECT":"INCORRECT");
    }
}

/*
    
*/