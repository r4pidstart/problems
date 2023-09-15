// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);
    string s; cin >> s;

    vector<int> arr(26);
    for(char c : s)
        arr[c-'A']++;
    
    vector<int> target(26);
    string target_str="BRONZESILVER";
    for(char c : target_str)
        target[c-'A']++;
    
    int ans=INT32_MAX;
    for(int i=0; i<26; i++)
        if(target[i])
            ans=min(ans, arr[i]/target[i]);
    printf("%d", ans);
}

/*
    
*/