// https://www.acmicpc.net/problem/1159
// 2022-03-14 21:17:47 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int first_name[26]={};
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        string s; cin >> s;
        first_name[s[0]-'a']++;
    }

    int cnt=0;
    for(int i=0; i<26; i++)
        if(first_name[i] >= 5)
            printf("%c", i+'a'), cnt++;
    if(!cnt)
        printf("PREDAJA");
}

/*
    
*/