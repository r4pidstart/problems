// https://www.acmicpc.net/problem/1358
// 2022-06-09 00:23:44 0ms
#include"bits/stdc++.h"
using namespace std;

int main(void)
{
    int w,h,x,y,p; scanf("%d%d%d%d%d", &w, &h, &x, &y, &p);
    int cnt=0;
    for(int i=0; i<p; i++)
    {
        int a,b; scanf("%d%d", &a, &b);
        
        // first circle
        if((x - a)*(x - a) + (y+(h/2) - b)*(y+(h/2) - b) <= (h/2)*(h/2)) cnt++;
        // rectangle
        else if(x<=a and a<=x+w and y<=b and b<=y+h) cnt++;
        // second circle
        else if((x+w - a)*(x+w - a) + (y+(h/2) - b)*(y+(h/2) - b) <= (h/2)*(h/2)) cnt++;
    }
    printf("%d", cnt);
}

/*
    
*/