// https://www.acmicpc.net/problem/5546
// 2023-10-10 02:07:47
#include"bits/stdc++.h"
using namespace std;

int solution(int idx, int now, int cnt, int n, map<int, int>& ma)
{
    static vector<vector<vector<int> > > memo(n+1, vector<vector<int> >(4, vector<int>(3, -1)));
    if(cnt==3) return 0;
    if(idx==n) return 1;
    if(memo[idx][now][cnt]!=-1) return memo[idx][now][cnt];
    
    int ret=0;
    if(ma.find(idx+1) != ma.end())
    {
        ret+=solution(idx+1, ma[idx+1], now==ma[idx+1] ? cnt+1:1, n, ma);
    }
    else
    {
        ret+=solution(idx+1, 1, now==1 ? cnt+1:1, n, ma);
        ret+=solution(idx+1, 2, now==2 ? cnt+1:1, n, ma);
        ret+=solution(idx+1, 3, now==3 ? cnt+1:1, n, ma);
    }
    return memo[idx][now][cnt]=ret%10000;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    map<int, int> ma;
    for(int i=0; i<k; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        ma[a]=b;
    }
    printf("%d", solution(0, 0, 0, n, ma));
}

/*
    
*/