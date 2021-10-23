// https://www.acmicpc.net/problem/1840
// 2021-10-24 00:08:49 4ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > copy_table, input;

int find_num(int x, int y, int target)
{
    for(int i=0; i<9; i++)
        if(copy_table[i][y]==target or copy_table[x][i]==target) return 0;

    int sx=x/3*3, sy=y/3*3;
    for(int i=sx; i<sx+3; i++)
        for(int j=sy; j<sy+3; j++)
            if(copy_table[i][j]==target) return 0;

    return 1;
}

int fill_table(int x, int y) 
{
    if(x>8) return fill_table(0,y+1);
    if(y>8) return 1;
    if(copy_table[x][y]) return fill_table(x+1,y);
    for(int i=1; i<=9; i++)
    {
        if(find_num(x,y,i)) 
        {
            copy_table[x][y]=i;
            if(fill_table(x+1,y)) return 1;
            else copy_table[x][y]=0;
        }
    }
    return 0;
}

int check_complete(void) // 스도쿠가 유호한지 확인
{
    for(int i=0; i<9; i++)
    {
        vector<int> sumX(9,0), sumY(9,0);
        for(int j=0; j<9; j++)
        {
            sumX[copy_table[i][j]-1]=1, sumY[copy_table[j][i]-1]=1;
        }
        if(accumulate(sumX.begin(), sumX.end(), 0) != 9 
           or accumulate(sumY.begin(), sumY.end(), 0) != 9) return 0;
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
                    sumS[copy_table[x][y]-1]=1;
            if(accumulate(sumS.begin(), sumS.end(), 0) != 9) return 0;
            sx+=3;
        }
        sy+=3;
    }
    return 1;
}

int check(int mid)
{
    copy_table.assign(9, vector<int>(9,0));
    for(int i=0; i<=mid; i++)
        copy_table[input[i][0]-1][input[i][1]-1]=input[i][2];

    return fill_table(0,0) ? check_complete():0;
}

int main(void)
{
    vector<vector<int> > table;
    input.assign(81, vector<int>(3));
    table.assign(81, vector<int>(9,0));
    int flag=0;
    for(int i=0; i<81; i++)
    {
        int a,b,c; scanf("%d%d%d", &a,&b,&c);
        input[i][0]=a, input[i][1]=b, input[i][2]=c;
        if(table[a][b] && !flag) flag=i;
        table[a][b]=c;
    }

    int lo=0, hi=flag ? flag-1:80, ans=0;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;

        if(check(mid))
        {
            lo=mid+1;
            ans=mid;
        }
        else
            hi=mid-1;
    }
    if(ans==80) printf("-1");
    else printf("%d", ans+2);
}

/*
    
*/