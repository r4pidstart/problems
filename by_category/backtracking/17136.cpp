// https://www.acmicpc.net/problem/17136
// 2023-10-15 00:37:55
#include"bits/stdc++.h"
using namespace std;

bitset<6> check_square(int x, int y, vector<vector<int> >& table)
{
    bitset<6> ret;
    for(int r=0; r<5; r++)
    {
        if(0<=x-r and 0<=y-r)
        {
            int cnt=0;
            for(int i=x-r; i<=x; i++)
                for(int j=y-r; j<=y; j++)
                    cnt+=table[i][j];
            if(cnt==(r+1)*(r+1))
                ret[r+1]=1;
        }
    }
    return ret;
}

int fill_square(int x, int y, int siz, int erase, vector<vector<int> >& table)
{
    for(int i=x-siz+1; i<=x; i++)
        for(int j=y-siz+1; j<=y; j++)
            table[i][j]=erase;
    return 0;
}

// backtracking backward
int solution(int x, int y, vector<vector<int> >& table, vector<int>& remain_square)
{
    if(x==-1) return 0;
    if(y==-1) return solution(x-1, 9, table, remain_square);

    int ret=INT32_MAX/2;
    if(table[x][y]==1)
    {
        auto square=check_square(x, y, table);
        for(int i=1; i<=5; i++)
        {
            if(square[i] and remain_square[i])
            {
                fill_square(x, y, i, 0, table);
                remain_square[i]--;
                ret=min(ret, solution(x, y-1, table, remain_square)+1);  
                remain_square[i]++;
                fill_square(x, y, i, 1, table);
            }
        }
        return ret;
    }
    else
        return solution(x, y-1, table, remain_square);
}

int main(void)
{
#ifdef LOCAL
#endif
    vector<vector<int> > table(10, vector<int>(10));
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            scanf("%d", &table[i][j]);
    vector<int> remain_square{0, 5, 5, 5, 5, 5};
    int ans=solution(9, 9, table, remain_square);
    printf("%d", ans==INT32_MAX/2 ? -1:ans);
}

/*
    
*/