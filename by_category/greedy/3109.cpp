// https://www.acmicpc.net/problem/3109
// 2021-07-07 03:35:10 316ms
#include<bits/stdc++.h>
using namespace std;

const int way[3][2]={{-1, 1}, {0, 1}, {1, 1}};
int r,c,cnt=1;
vector<vector<int> > m;

int dfs(int x, int y)
{
    m[x][y]=cnt;
    if(y==c-1) // 도달
    {
        cnt++;
        return 1;
    }

    for(int i=0; i<3; i++)
    {
        int nx=x+way[i][0], ny=y+way[i][1];
        if(0<=nx && nx<r && ny<c)
        {
            if(m[nx][ny]) continue;
            if(dfs(nx, ny))
                return 1;
        }
    }
    return 0;
}

int main(void)
{
    scanf("%d%d", &r,&c);
    m=vector<vector<int> > (r, vector<int>(c,0));

    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
        {
            char c; scanf("\n %c", &c);
            m[i][j]=c=='x' ? 1:0;
        }
    
    for(int i=0; i<r; i++)
        dfs(i, 0);

    // for(int i=0; i<r; i++)
    // {
    //     for(int j=0; j<c; j++)
    //         printf("%d", m[i][j]);
    //     printf("\n");
    // }
    printf("%d", cnt-1);
}

/*
    최대한 위쪽으로 경로를 만들어볼까?
*/


// 6 10
// aaxaaaaaaa
// bbabbxbbbb
// cxbccbxccc
// dccxdccxxd
// edddedddde
// .eeexeeee.