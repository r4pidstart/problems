// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int check(vector<vector<int> >& stu, int mask)
{
    int cnt=0;
    for(auto& v : stu)
    {
        int flag=0;
        for(auto& i : v)
            if(~mask & (1<<i))
            {
                flag++; break;
            }
        if(!flag) cnt++;
    }
    return cnt;
}

int main(void)
{
    int n,d,k; scanf("%d%d%d", &n,&d,&k);
    vector<vector<int> > stu(n);
    for(int i=0; i<n; i++)
    {
        int c; scanf("%d", &c);
        while(c--)
        {
            int tmp; scanf("%d", &tmp);
            stu[i].push_back(tmp-1);
        }
    }

    // dCk 마다, 조건에 맞는 학생의 수를 구하기
    int ans=0;
    for(int i=0; i<(1<<d)+1; i++)
        if(__builtin_popcount(i)==k) 
            ans=max(ans, check(stu, i));
    
    printf("%d", ans);
}

/*
    
*/