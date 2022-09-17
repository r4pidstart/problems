// https://www.acmicpc.net/problem/25501
// 2022-09-17 23:40:32
#include"bits/stdc++.h"
using namespace std;

int cnt=0; 
int recursion(const char *s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(void)
{
    int n; scanf("%d", &n);
    while(n--)
    {
        cnt=0;
        string s; cin >> s;
        printf("%d ", isPalindrome(s.c_str()));
        printf("%d\n", cnt);
    }
}

/*
    
*/