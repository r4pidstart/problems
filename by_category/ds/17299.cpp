// https://www.acmicpc.net/problem/17299
// 2021-10-30 05:38:41 236ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> cnt(1000001, 0), input(n), ans(n);
    stack<int> s;

    for(int i=0; i<n; i++) 
    {
        cin >> input[i];
        cnt[input[i]]++; 
    }

    // monotone stack
    for(int i=n-1; i>=0; i--)
    {
        while(!s.empty() and cnt[s.top()] <= cnt[input[i]]) s.pop();
        if(s.empty()) ans[i]=-1;
        else ans[i]=s.top();
        s.push(input[i]);
    }

    for(int& i : ans) cout << i << " ";
}

/*
    
*/