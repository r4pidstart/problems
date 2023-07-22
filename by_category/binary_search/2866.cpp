// https://www.acmicpc.net/problem/2866
// 2023-07-23 00:05:00
#include"bits/stdc++.h"
using namespace std;

int check(int cnt, vector<char*>& arr)
{
    for(int i=0; i<arr.size(); i++)
        for(int j=i+1; j<arr.size(); j++)
            if(strcmp(arr[i]+cnt, arr[j]+cnt)==0)
                return 1;
    return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<char> > table(n, vector<char>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            scanf(" %c", &table[i][j]);
    
    vector<char*> arr(m);
    for(int j=0; j<m; j++)
    {
        arr[j]=new char[n+1]; 
        arr[j][n]='\0';  
        for(int i=0; i<n; i++)
            arr[j][i]=table[i][j];
    }

    int lo=0, hi=n, ans=n;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(check(mid, arr))
            ans=mid, hi=mid-1;
        else
            lo=mid+1;
    }
    printf("%d", ans-1);
    int cnt=0;
}

/*
    
*/