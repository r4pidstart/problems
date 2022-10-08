// https://www.acmicpc.net/problem/20437
// 2022-10-09 00:49:34 20ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        string s; cin >> s;
        int k; scanf("%d", &k);
        vector<vector<int> > arr(26);
        for(int i=0; i<s.length(); i++)
            arr[s[i]-'a'].push_back(i);
        
        int min_len=INT32_MAX, max_len=0;
        for(int i=0; i<26; i++)
        {
            if(arr[i].size() >= k)
            {
                int lo=0, hi=k-1;
                while(hi<arr[i].size())
                {
                    min_len=min(arr[i][hi]-arr[i][lo]+1, min_len);
                    max_len=max(arr[i][hi]-arr[i][lo]+1, max_len);
                    lo++, hi++;
                }
            }
        }
        if(min_len == INT32_MAX or max_len == -1)
            printf("-1\n");
        else
            printf("%d %d\n", min_len, max_len);
    }
}

/*
    
*/