// https://www.acmicpc.net/problem/16395
// 2021-09-09 03:05:41 0ms
#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > combi_table(31, vector<int>(31,0));

int get_combi(int n, int k)
{
    if(n-k < k) k=n-k;
    if(combi_table[n][k]) return combi_table[n][k];
    if(k==0) return combi_table[n][k]=1;
    if(k==1) return combi_table[n][k]=n;
    return combi_table[n][k]=get_combi(n-1, k)+get_combi(n-1, k-1);
}

int main(void)
{
    int n,k; scanf("%d%d", &n,&k);
    printf("%d", get_combi(n-1,k-1));    
}

/*

*/