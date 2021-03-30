// https://www.acmicpc.net/problem/1655
// 2021-03-30 21:45:55 40ms

// 45 50
//  35 pq_min

//  30 pq_max
// 20 15

#include<iostream>
#include<queue>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    priority_queue<int, vector<int>, less<int>> pq_max; 
    priority_queue<int, vector<int>, greater<int>> pq_min;
    int flag=0;
    while(n--)
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
            while(pq_min.top()<pq_max.top())
            {
                pq_min.push(pq_max.top());
                pq_max.push(pq_min.top());
                pq_min.pop();
                pq_max.pop();
            }
        }
        printf("%d\n", pq_max.top());
    }
}