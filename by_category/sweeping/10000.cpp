// https://www.acmicpc.net/problem/10000
// 2022-12-02 23:06:54
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
#ifdef LOCAL
#endif
    int n; scanf("%d", &n);

    struct st
    {
        int is_start;
        int idx;
        int point;
        int end_point;
        int start_point;
        const bool operator<(const st& a) const
        {
            if(is_start)
            {
                if(this->point == a.point)
                {
                    if(this->is_start != a.is_start)
                        return this->is_start < a.is_start;
                    return this->end_point > a.end_point;
                }
                return this->point < a.point;
            }
            if(this->point == a.point)
                {
                    if(this->is_start != a.is_start)
                        return this->is_start < a.is_start;
                    return this->start_point > a.start_point;
                }
            return this->point < a.point;
        }
    };

    vector<st> arr(2*n);
    for(int i=0; i<n; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        arr[i*2+1]={1, i, a-b, a+b, a-b}; // start
        arr[i*2]={0, i, a+b, a+b, a-b}; // end
    }
    sort(arr.begin(), arr.end());

    map<int, int> separated;
    stack<st> stk;
    int prev=0;
    for(int i=0; i<2*n; i++)
    {
        if(stk.size() and ((prev != arr[i].point and stk.top().idx == arr[i].idx) or (arr[i].is_start and prev != arr[i].point)))
            separated[stk.top().idx]=0;
    
        if(arr[i].is_start)
        {
            separated[arr[i].idx]=1;
            stk.push(arr[i]);
        }
        else
        {
            assert(stk.top().idx == arr[i].idx);
            stk.pop();
        }

        prev=arr[i].point;
    }
    int cnt=0;
    for(auto it : separated)
        cnt+=it.second;
    printf("%d", n+1 + cnt);
    return 0;
}

/*
    
*/