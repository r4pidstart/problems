// https://www.acmicpc.net/problem/1269
// 2022-05-09 23:48:29 216ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int a,b; scanf("%d%d", &a, &b);
    map<int, int> arra;
    for(int i=0; i<a; i++)
    {
        int q; scanf("%d", &q);
        arra[q]=0;
    }

    int cnt=0;
    for(int i=0; i<b; i++)
    {
        int q; scanf("%d", &q);
        if(arra.find(q) != arra.end())
            arra[q]=1;
        else
            cnt++;
    }

    for(auto it : arra)
        if(!it.second) cnt++;
    
    printf("%d", cnt);
        
}

/*
    
*/