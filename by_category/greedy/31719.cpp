// https://www.acmicpc.net/problem/31719
// 2024-04-03 13:49:23
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        int n; scanf("%d", &n);
        vector arr(n, 0);
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        
        queue<int> s1, s2;
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            while((s1.size() and s1.front()==cnt+1) or (s2.size() and s2.front()==cnt+1))
            {
                if(s1.size() and s1.front()==cnt+1)
                    cnt=s1.back(), s1=queue<int>();
                if(s2.size() and s2.front()==cnt+1)
                    cnt=s2.back(), s2=queue<int>();
            }

            if(arr[i] == cnt+1)
                cnt++;
            else
            {
                if(s1.size() and s1.back()+1 == arr[i])
                    s1.push(arr[i]);
                else if(s2.size() and s2.back()+1 == arr[i])
                    s2.push(arr[i]);
                else if(!s1.size())
                    s1.push(arr[i]);
                else if(!s2.size())
                    s2.push(arr[i]);
                else
                    break;
            }
        }

        while((s1.size() and s1.front()==cnt+1) or (s2.size() and s2.front()==cnt+1))
        {
            if(s1.size() and s1.front()==cnt+1)
                cnt=s1.back(), s1=queue<int>();
            if(s2.size() and s2.front()==cnt+1)
                cnt=s2.back(), s2=queue<int>();
        }
        
        printf("%s\n", cnt==n ? "YES":"NO");
    }
}

/*
    
*/