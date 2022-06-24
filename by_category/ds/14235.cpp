// https://www.acmicpc.net/problem/13029
// 2022-06-23 23:48:02 100ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    multiset<int> se;
    while(n--)
    {
        int a; scanf("%d", &a);
        if(!a)
            if(se.size())
            {   
                int value=*(--se.end());
                se.erase(--se.end());
                printf("%d\n", value);
            }
            else
                printf("%d\n", -1);
        else
            while(a--)
            {
                int b; scanf("%d", &b);
                se.insert(b);
            }
    }
}

/*
    
*/