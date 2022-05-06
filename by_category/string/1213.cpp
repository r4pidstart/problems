// https://www.acmicpc.net/problem/1213
// 2022-05-06 23:53:55 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    string s; cin >> s;
    vector<int> arr(26);
    for(int i=0; i<s.length(); i++)
        arr[s[i]-'A']++;
    
    string ans;
    for(int i=0; i<26; i++)
    {
        for(int j=0; j<arr[i]/2; j++)
            ans+=(i+'A');        
    }

    for(int i=0; i<26; i++)
    {
        if(arr[i]&1)
            ans+=(i+'A');      
    }

    for(int i=25; i>=0; i--)
    {
        for(int j=0; j<arr[i]/2; j++)
            ans+=(i+'A');        
    }

    for(int i=0; i<ans.length()/2; i++)
        if(ans[i] != ans[ans.length()-1-i])
            return !printf("I'm Sorry Hansoo");
    cout << ans;
}

/*
    
*/