// https://www.acmicpc.net/problem/1339
// 2021-11-06 04:31:53 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<string> ss(n);
    vector<int> digit={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000}, arr(26,0);
    for(int i=0; i<n; i++) cin >> ss[i];
    for(string s : ss)
        for(int i=0; i<s.length(); i++)
            arr[s[i]-'A']+=digit[s.length()-i-1];
    
    sort(arr.rbegin(), arr.rend());
    int ans=0;
    for(int i=0; i<10; i++)
        ans+=arr[i]*(9-i);
    printf("%d", ans);
}

/*
    
*/