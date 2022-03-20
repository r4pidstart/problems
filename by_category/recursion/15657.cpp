// https://www.acmicpc.net/problem/15657
// 2022-03-20 14:48:22 4ms
#include<bits/stdc++.h>
using namespace std;

void nnm(int n, int m, int prev, int idx, const vector<int>& arr, vector<int>& ret)
{
    if(m==0)
    {
        for(auto i : ret)
            printf("%d ", i);
        printf("\n");
        return;
    }

    for(int i=prev; i<n; i++)
    {
        ret[idx]=arr[i];
        nnm(n, m-1, i, idx+1, arr, ret);
    }
}
int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<int> arr(n), ret(m);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    sort(arr.begin(), arr.end());
    nnm(n,m,0,0,arr,ret);
}

/*
    
*/