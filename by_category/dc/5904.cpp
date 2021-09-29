// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

vector<long long> memo(30, -1);

long long get_cnt(int n)
{
    if(n==0) return memo[n]=3;
    if(memo[n]!=-1) return memo[n];
    return memo[n]=2*get_cnt(n-1)+n+3;
}

char get_ans(int n)
{
    if(n==1) return 'm';
    if(n==2 || n==3) return 'o';

    int now;
    for(int i=1; i<=30; i++)
        if(n <= get_cnt(i))
        {
            now=i;
            break;
        }

    if(n <= get_cnt(now-1)+now+3)
    {
        if(n-1==get_cnt(now-1)) return 'm';
        return 'o';
    }
    return get_ans(n-(get_cnt(now-1)+now+3));
}

int main(void)
{
    int n; scanf("%d", &n);
    printf("%c", get_ans(n));
}

/*
    
*/