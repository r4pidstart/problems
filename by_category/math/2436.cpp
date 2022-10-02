// https://www.acmicpc.net/problem/2436
// 2022-10-03 03:21:19 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
	long a,b; scanf("%ld%ld", &a, &b);
    long tmp=a;
    long ans1=a, ans2=b*gcd(a,b)/tmp;

    while(tmp <= 100000000)
    {
        long tmp2=b*gcd(a,b)/tmp;
        if(ans1+ans2 > tmp+tmp2 and gcd(tmp, tmp2)==a and lcm(tmp, tmp2)==b)
            ans1=tmp, ans2=tmp2;
        else if(ans1+ans2 < tmp+tmp2)
            break;
        tmp+=a;
    }
    printf("%ld %ld", ans1, ans2);
}

/*
	
*/