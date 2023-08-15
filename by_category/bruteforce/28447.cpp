// https://www.acmicpc.net/problem/28447
// 2023-08-16 00:25:58
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n,k; scanf("%d%d", &n, &k);
    vector<vector<int> > table(n, vector<int>(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d", &table[i][j]);
    
    vector<int> combi(n, 1);
    fill(combi.begin(), combi.begin()+n-k, 0);

    int ans=INT32_MIN;
    do
    {   
        int tmp=0;
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(combi[i] and combi[j])
                    tmp+=table[i][j];
        ans=max(ans, tmp);
    } while (next_permutation(combi.begin(), combi.end()));
    printf("%d", ans);
}

/*
    
*/