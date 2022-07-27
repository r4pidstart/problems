// https://www.acmicpc.net/problem/5913
// 2022-07-27 23:14:23 4ms
#include"bits/stdc++.h"
using namespace std;

int dfs(int a, int b, int c, int d, int cnt, vector<vector<int> >& table)
{
    int ret=0;
    const int way[4][2]={{0,1}, {1,0}, {0,-1}, {-1,0}};

    // printf("\n");
    // for(int i=0; i<5; i++)
    // {
    //     for(int j=0; j<5; j++)
    //         printf("%d ", table[i][j]);
    //     printf("\n");
    // }

    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
        {
            int nx1=a+way[i][0], ny1=b+way[i][1];
            int nx2=c+way[j][0], ny2=d+way[j][1];
            if(0<=nx1 and 0<=nx2 and nx1<5 and nx2<5)
                if(0<=ny1 and 0<=ny2 and ny1<5 and ny2<5)
                    if(!table[nx1][ny1] and !table[nx2][ny2])
                    {
                        table[nx1][ny1]=table[nx2][ny2]=1;
                        if(nx1==nx2 and ny1==ny2)
                        {
                            if(cnt==1) ret+=1;
                        }
                        else
                            ret+=dfs(nx1, ny1, nx2, ny2, cnt-2, table);
                        table[nx1][ny1]=table[nx2][ny2]=0;
                    }
        }
    return ret;
}

int main(void)
{
    int k; scanf("%d", &k);
    vector<vector<int> > table(5, vector<int>(5));
    table[0][0]=table[4][4]=1;
    for(int i=0; i<k; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        table[a-1][b-1]=1;
    }

    printf("%d", dfs(0,0, 4,4, 25-k-2, table));
}

/*
    
*/