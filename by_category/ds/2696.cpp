// https://www.acmicpc.net/problem/2696
// 2022-05-09 01:32:00 4ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        printf("%d\n", (int)ceil((double)n/2));
        priority_queue<int, vector<int>, less<int>> pq_max; 
        priority_queue<int, vector<int>, greater<int>> pq_min;
        int flag=0, cnt=0;;
        for(int i=0; i<n; i++)
        {
            int tmp;
            if(flag==0)
            {
                flag++;
                scanf("%d", &tmp);
                pq_max.push(tmp);
            }
            else
            {
                flag--;
                scanf("%d", &tmp);
                pq_min.push(tmp);
            }
            if(pq_min.size()!=0)
            {
                if(pq_min.top()<pq_max.top())
                {
                    pq_min.push(pq_max.top());
                    pq_max.push(pq_min.top());
                    pq_min.pop();
                    pq_max.pop();
                }
            }
            if(!(i&1)) printf("%d ", pq_max.top()),cnt++;
            if(!(i&1) and !(cnt%10)) printf("\n");
        }
        printf("\n");
    }
}