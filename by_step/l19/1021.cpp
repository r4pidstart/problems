// https://www.acmicpc.net/problem/1021
// 2021-03-21 01:40:16 0ms
#include<iostream>
#include<deque>
using namespace std;
int main(void)
{
    int n, k, count=0; scanf("%d%d", &n, &k);
    deque <int> dq(n);
    for(int i=0; i<n; i++)
        dq[i]=i+1;
    while(k--)
    {
        int target; scanf("%d", &target);
        for(int i=0; i<n; i++)
            if(dq[i]==target)
            {
                if(i>(n--)/2) // 뒤쪽에 있을 경우
                {
                    while(dq[0]!=target)
                    {
                        dq.push_front(dq.back());
                        dq.pop_back();
                        count++;
                    }
                }
                else // 앞쪽에 있을 경우
                {
                    while(dq[0]!=target)
                    {
                        dq.push_back(dq.front());
                        dq.pop_front();
                        count++;
                    }
                }
                dq.pop_front();
                break;
            }
    }
    printf("%d", count);
}