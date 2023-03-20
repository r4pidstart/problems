// https://www.acmicpc.net/problem/2291
// 2023-03-20 23:16:36
#include"bits/stdc++.h"
using namespace std;

long dp(int len, int m, int start)
{
    static vector<vector<vector<int> > > memo(len+1, vector<vector<int> >(m+1, vector<int>(m+1, -1)));

    if(m<0)
        return 0;
    if(memo[len][m][start] != -1)
        return memo[len][m][start];
    if(len<=0)
        return m==0;
    
    long ret=0;
    for(int i=start; i<=m; i++)
        ret+=dp(len-1, m-i, i);

    return memo[len][m][start]=ret;
}

int btrk(int idx, int m, int start, int k, vector<int>& arr)
{
    if(idx==arr.size())
        return 0;
    long ret=0;
    for(int i=0; i<=m; i++)
    {
        arr[idx]=start+i;
        int remained_len=arr.size()-idx-1;
        long tmp=dp(remained_len, m-(start+i)*(remained_len+1), 0);
        if(ret+tmp>=k)
            return btrk(idx+1, m-(start+i), start+i, k-ret, arr);
        ret+=tmp;
    }
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,m,k; scanf("%d%d%d", &n, &m, &k);
    vector<int> arr(n);
    dp(n, m, 0);
    btrk(0, m, 1, k, arr);
    for(auto i : arr)
        printf("%d ", i);
}

/*
    
*/