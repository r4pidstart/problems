// https://www.acmicpc.net/problem/20648
// 2021-10-08 03:53:32 128ms
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > cow;
vector<vector<int> > psum;

bool compy(const pair<int,int>& a, const pair<int,int>& b)
{ return a.second < b.second; }

inline long long get_sum(int x, int y, int a, int b)
{ return psum[x][y]-psum[x][b-1]-psum[a-1][y]+psum[a-1][b-1]; }

int main(void)
{
    int n; scanf("%d", &n);
    cow.assign(n, {});
    psum.assign(n+1, vector<int>(n+1,0));
    for(int i=0; i<n; i++)
        scanf("%d%d", &cow[i].first, &cow[i].second);

    // 좌표 압축 (각 x,y좌표는 유일함)
    sort(cow.begin(), cow.end(), compy);
    for(int i=0; i<n; i++) cow[i].second=i+1;
    sort(cow.begin(), cow.end());
    for(int i=0; i<n; i++) cow[i].first=i+1;

    // 2차원 누적 합
    for(int i=0; i<n; i++)
        psum[cow[i].first][cow[i].second]=1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            psum[i][j]=psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1]+psum[i][j];

    long long ans=1; // 공집합
    // x좌표 고정하기
    for(int i=0; i<n; i++)
        for(int j=i; j<n; j++)
        {
            int left=cow[i].first, right=cow[j].first;
            int up=cow[i].second, down=cow[j].second;
            if(up < down) swap(up,down);

            // 구간 밖에 있는 점 갯수를 이용해 가능한 부분집합 수 세기
            ans+=get_sum(right, down, left, 0)*get_sum(right, n, left, up);
        }
    printf("%lld", ans);
}

/*
    
*/