// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    
    int q; scanf("%d", &q);
    while(q--)
    {
        int cmd; scanf("%d", &cmd);
        if(cmd == 1)
        {
            int a; scanf("%d", &a);
            for(int i=0; i<n; i++)
                if(!((i+1) % a))
                    arr[i]^=1;
        }
        else
        {
            int a; scanf("%d", &a);
            int s=a-1, e=a-1;
            while(s-1 >= 0 and e+1 < n)
            {
                if(arr[s-1]==arr[e+1])
                    s--, e++;
                else
                    break;
            }
            for(int i=s; i<=e; i++)
                arr[i]^=1;
        }
    }

    int i=0;
    while(i < n)
    {
        int tmp=i+20;
        for(; i<n and i<tmp; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
}

/*
    
*/