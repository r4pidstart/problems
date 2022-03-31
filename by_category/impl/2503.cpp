// https://www.acmicpc.net/problem/2503
// 2022-04-01 03:24:25 4ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> possible(1000, 1);
    for(int i=0; i<=999; i++)
    {
        // 가능한 숫자만 놔두기
        if(i < 123) possible[i]=0;
        if(i/100 == i%100/10 or i%100/10 ==  i%10 or i/100 == i%10) possible[i]=0;
        if(i/100 == 0 or i%100/10 == 0 or i%10 == 0) possible[i]=0;
    }

    while(n--)
    {
        int t, a, b; scanf("%d%d%d", &t, &a, &b);
        
        for(int i=123; i<=999; i++)
        {
            string now=to_string(i), comp=to_string(t);
            int a_cnt=0, b_cnt=0;

            if(now[0] == comp[0]) a_cnt++;
            if(now[1] == comp[1]) a_cnt++;
            if(now[2] == comp[2]) a_cnt++;
            if(now[0] == comp[1] or now[0] == comp[2]) b_cnt++;
            if(now[1] == comp[0] or now[1] == comp[2]) b_cnt++;
            if(now[2] == comp[0] or now[2] == comp[1]) b_cnt++;

            if(a_cnt != a or b_cnt != b)
                possible[i]=0;
        }
    }

    printf("%d", accumulate(possible.begin(), possible.end(), 0));
}

/*
    
*/