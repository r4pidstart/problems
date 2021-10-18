// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > table(9,vector<int>(9));

void printTable()
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
            printf("%d", table[i][j]);
        printf("\n");
    }
}

pair<int,int> findNext(void)
{
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            if(table[i][j]==0) return {i,j};
    return {-1,-1};
}

void solution(pair<int,int> point)
{
    if(findNext()==make_pair(-1,-1)) // 더 이상 넣을 공간이 없다면
    {
        printTable();
        exit(0);
    }

    // 없는 숫자 확인
    vector<int> checkX(10,0), checkY(10,0);
    for(int i=0; i<9; i++) 
    {
        checkX[table[i][point.second]]++;
        checkY[table[point.first][i]]++;
    }

    vector<int> checkS(10,0);
    int sx=point.first/3*3, sy=point.second/3*3;
    for(int i=sx; i<sx+3; i++)
        for(int j=sy; j<sy+3; j++)
            checkS[table[i][j]]++;

    // 숫자 채우기
    for(int i=1; i<10; i++)
    {
        if(!checkX[i] && !checkY[i] && !checkS[i]) // 세 조건에 다 부합한다면
        {
            table[point.first][point.second]=i;
            solution(findNext());
        }
    }
    table[point.first][point.second]=0; // 넣을 수 있는 숫자가 더 이상 없는 경우
    return;
}

int main(void)
{
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            scanf("%1d",&table[i][j]); 
    solution(findNext());
}

/*

*/