// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int t; scanf("%d", &t);
    while(t--)
    {
        long a; scanf("%ld", &a);
        if(a==0 || a==1)
        {
            printf("2\n");
            continue;
        }
        while(true)
        {
            int flag=0;
            for(long i=2; i*i<=a; i++)
                if(a%i == 0)
                {
                    flag=1;
                    break;
                }
            
            if(!flag)
            {
                printf("%ld\n", a);
                break;
            }
            a++;
        }
    }
}

/*
    
*/