// https://www.acmicpc.net/problem/15655
// 2022-02-23 23:52:48 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n,m; scanf("%d%d", &n,&m);
    vector<int> combi(n, 0), arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    sort(arr.begin(), arr.end());
    fill(combi.begin(), combi.begin()+m, 1);
    do
    {
        for(int i=0; i<n; i++)
            if(combi[i]) printf("%d ", arr[i]);
        printf("\n");
    }
    while(prev_permutation(combi.begin(), combi.end()));
}

/*
    
*/