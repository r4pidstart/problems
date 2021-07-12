// https://www.acmicpc.net/problem/1365
// 2021-07-13 01:59:57 16ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> num(n, 0); 
    for(int i=0; i<n; i++)
        scanf("%d", &num[i]);

    // longest increasing subsequence
    vector<int> memo;
    for(int i=0; i<n; i++)
    {
        auto it=lower_bound(memo.begin(), memo.end(), num[i]);
        if(it==memo.end()) // 가장 클 경우
            memo.push_back(num[i]);
        else
            *it=min(memo[it-memo.begin()], num[i]);
    }

    printf("%d", n-memo.size());
}

/*

*/
