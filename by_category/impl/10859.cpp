// https://www.acmicpc.net/problem/10859
// 2023-01-24 02:07:30
#include"bits/stdc++.h"
using namespace std;

int is_prime(long a)
{
    if(a==1)
        return (0);
    for(long i=2; a>=i*i; i++)
        if(a%i == 0)
            return (0);
    return (1);
}

int main(void)
{
#ifdef LOCAL
#endif
    long n; scanf("%ld", &n);
    if(!is_prime(n))
        return !printf("no");
    string s=to_string(n);
    reverse(s.begin(), s.end());
    n=0;
    for(auto i : s)
    {
        if(i=='6') i='9';
        else if(i=='9') i='6';
        
        if(i=='3' or i=='4' or i=='7')
            return !printf("no");
        n=n*10+i-'0';
    }
    if(!is_prime(n))
        return !printf("no");
    printf("yes");
}

/*
    
*/