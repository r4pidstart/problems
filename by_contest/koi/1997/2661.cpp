// https://www.acmicpc.net/problem/2661
// 2022-03-12 00:19:15 0ms
#include<bits/stdc++.h>
using namespace std;

int valid_check(string s)
{
    // 마지막 문자가 포함 된 서브스트링만 확인하면 됨.
    for(int i=1; i<=s.length()/2; i++) // 스트링 길이
        if(s.substr(s.length()-i, i) == s.substr(s.length()-i-i, i))
            return 1;
    return 0;
}

string ans;
int dfs(int n)
{
    if(valid_check(ans))
        return 1;   
    
    if(n==0) 
        return 0;
    else
    {
        ans+='1';
        if(!dfs(n-1)) return 0;

        ans.back()='2';
        if(!dfs(n-1)) return 0;

        ans.back()='3';
        if(!dfs(n-1)) return 0;

        ans.pop_back();
        return 1;
    }
}

int main(void)
{
    int n; scanf("%d", &n);
    ans="", dfs(n);
    cout << ans;
}

/* 

*/