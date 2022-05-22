// https://www.acmicpc.net/problem/13402
// 2022-05-23 03:49:35 2580ms
#include"bits/stdc++.h"
using namespace std;

int check(int mid, const string &s1, const string &s2)
{
    if(s1.length() < mid or s2.length() < mid)
        return 0;

    // O(n*m * log2(1500) * 26)
    set<vector<int> > se;
    
    vector<int> arr(26, 0);
    for(int i=0; i<mid; i++)
        arr[s1[i]-'a']++;
    
    se.insert(arr);
    for(int i=mid; i<s1.length(); i++)
    {
        arr[s1[i]-'a']++, arr[s1[i-mid]-'a']--;
        se.insert(arr);
    }

    arr.assign(26, 0);
    for(int i=0; i<mid; i++)
        arr[s2[i]-'a']++;
    
    if(se.find(arr) != se.end())
        return 1;
    for(int i=mid; i<s2.length(); i++)
    {
        arr[s2[i]-'a']++, arr[s2[i-mid]-'a']--;
        if(se.find(arr) != se.end())
            return 1;
    }

    return 0;
}

int main(void)
{
    string s1, s2; cin >> s1 >> s2;
    int ans=0;
    for(int i=1, l=min(s1.length(), s2.length()); i<=l; i++)
        if(check(i, s1, s2)) ans=i;
    printf("%d", ans);
}

/*
    
*/