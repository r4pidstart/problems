// https://www.acmicpc.net/problem/7662
// 2022-01-23 15:41:50 
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        map<int, int> m; // num, cnt
        int cnt=0;
        int n; scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            char cmd; scanf(" %c", &cmd);
            switch (cmd)
            {
            case 'I':
            {
                int tmp; scanf("%d", &tmp);
                if(m.find(tmp) == m.end()) m[tmp]=0;
                m[tmp]++, cnt++;
                break;
            }
            
            default: // D
            {
                int tmp; scanf("%d", &tmp);
                if(cnt)
                {
                    if(tmp==-1) m.begin()->second--;
                    else (--m.end())->second--;
                    if(m.begin()->second==0) m.erase(m.begin());
                    else if((--m.end())->second==0) m.erase(--m.end());
                    cnt--;
                }
                break;
            }
            }
        }
        if(cnt)
            printf("%d %d\n", (--m.end())->first, m.begin()->first);
        else
            printf("EMPTY\n");
    }
}

/*
    
*/