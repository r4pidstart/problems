// https://www.acmicpc.net/problem/1966
// 2021-03-20 03:33:41 time exceeded
#include<iostream>
#include<utility>
#include<vector>
using namespace std;
int main(void)
{
    int t,tmp; scanf("%d", &t);
    while(t--)
    {
        int n,k, count=0; 
        scanf("%d%d", &n,&k);
        vector<int> priority(9,0);
        vector<pair<int, int>> q(n);
        for(int i=0; i<n; i++)
        {
            scanf("%d", &q[i].first);
            priority[q[i].first]++;
        }
        int target_p=q[k].first;
        q[k].second=-1;
        for(int i=9; i>target_p; i--) // pop higher priorities
        {
            while(priority[i]!=0)
                if(q[0].first==i)
                {
                    q.erase(q.begin()); // pop
                    priority[i]--;
                    count++;
                }
                else
                {
                    q.push_back(make_pair(q[0].first, q[0].second)); // push(pop)
                    q.erase(q.begin());
                }
        }
        for(int i=0, size=q.size(); i<size; i++)
        {
            if(q[0].second!=-1)
                if(q[0].first==target_p)
                    {
                        q.erase(q.begin()); // pop
                        count++;
                    }
                    else
                    {
                        q.push_back(make_pair(q[0].first, q[0].second)); // push(pop)
                        q.erase(q.begin());
                    }
            else
            {
                printf("%d\n", count+1);
                break;
            }
        }
    }
}
