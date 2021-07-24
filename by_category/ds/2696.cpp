// https://www.acmicpc.net/problem/2696
// 2021-07-25 02:01:10 4ms
#include<bits/stdc++.h>
using namespace std;

priority_queue<int> minpq, maxpq;
// minpq.top() -> middle

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        minpq=maxpq=priority_queue<int>();
        int n; scanf("%d", &n);
        printf("%d\n", (n+1)/2);
        maxpq.push(INT32_MIN);
        int cnt=0;
        for(int i=1; i<=n; i++)
        {
            int a; scanf("%d", &a);
            if(i&1)
                minpq.push(-a);
            else
                maxpq.push(a);

            while(-minpq.top()<maxpq.top())
            {
                int tmpmin=-minpq.top(), tmpmax=maxpq.top();
                minpq.pop(), maxpq.pop();
                minpq.push(-tmpmax), maxpq.push(tmpmin);
            }
            if(i&1)
            {
                printf("%d ", -minpq.top());
                cnt++;
                if(!(cnt%10))
                    printf("\n");
            }
        }
        printf("\n");
    }
}

/*

*/
