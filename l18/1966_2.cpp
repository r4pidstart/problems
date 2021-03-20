// https://www.acmicpc.net/problem/1966
// 2021-03-20 19:39:46 0ms
#include<iostream>
#include<utility>
#include<vector>
using namespace std;
int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n,k; scanf("%d%d", &n,&k);
        vector <int> q(n);
        vector <int> priority(10,0);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &q[i]);
            priority[q[i]]++;
        }
        int index=0, p_index=9, count=0;
        while(1)
        {
            if(index==n)
                index=0;
            
            if(index==k && p_index==q[k])
                break;

            if(q[index]==p_index)
            {
                count++;
                priority[p_index]--;
            }

            if(priority[p_index]==0)
                while(priority[p_index]==0)
                    p_index--;
            else
                index++;
        }
        printf("%d\n", count+1);
    }
}
