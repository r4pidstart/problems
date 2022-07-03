// https://www.acmicpc.net/problem/4779
// 2022-07-03 23:00:58 8ms
#include"bits/stdc++.h"
using namespace std;

void get_cantor(string &s, int st, int ed)
{
    int len=ed-st;
    if(len <= 1) return;

    for(int i=st + len/3; i<ed - len/3; i++)
        s[i]=' ';
    get_cantor(s, st, st+(len/3)), get_cantor(s, st+(2*len/3), ed);
}

void print_cantor(int n)
{
    string s;
    for(int i=0, l=pow(3, n); i<l; i++)
        s+='-';
    get_cantor(s, 0, s.length());
    cout << s << '\n';
}

int main(void)
{
    int n;
    while(scanf("%d", &n) != EOF)
        print_cantor(n);
}

/*
    
*/