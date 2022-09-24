// https://www.acmicpc.net/problem/3015
// 2022-09-24 23:50:59 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    long ans=0;
    stack<pair<int,int> > stk;
    for(int i=0; i<n; i++)
    {
        int cnt=1;
        while(stk.size() and stk.top().first < arr[i])
            ans+=stk.top().second, stk.pop();
        if(stk.size() and stk.top().first == arr[i])
            ans+=stk.top().second, cnt+=stk.top().second, stk.pop();
        if(stk.size())
            ans+=1;
        stk.push({arr[i], cnt});
    }
    printf("%ld", ans);
}

/*
    
*/