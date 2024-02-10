// https://www.acmicpc.net/problem/11578
// 2024-02-11 05:49:03
#include"bits/stdc++.h"
using namespace std;

int solution(int now, int n, const vector<vector<int> >& arr, vector<int>& solved)
{
    if(accumulate(solved.begin(), solved.end(), 0) == n)
        return 0;
    if(now==arr.size())
        return INT32_MAX/2;

    int ret=solution(now+1, n, arr, solved);

    vector<int> prev=solved;
    
    for(int i : arr[now])
        solved[i-1]=1;
    ret=min(ret, solution(now+1, n, arr, solved)+1);
    solved=prev;

    return ret;
}

int main(void)
{
    int n,m; scanf("%d%d", &n, &m);
    vector<vector<int> > arr(m);
    for(int i=0; i<m; i++)
    {
        int n; scanf("%d", &n);
        while(n--)
        {
            int a; scanf("%d", &a);
            arr[i].push_back(a);
        }
    }
    vector<int> solved(n);
    int ans=solution(0, n, arr, solved);
    printf("%d", ans==INT32_MAX/2 ? -1:ans);
}

/*
    
*/