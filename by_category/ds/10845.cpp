// https://www.acmicpc.net/problem/10845
// 2021-10-27 00:26:11 412ms
#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int curLeft=0, curRight=0;

void push(int x)
{
    arr[curRight++]=x;
}

int empty(void)
{
    return curLeft==curRight;
}

int pop(void)
{
    if(empty())
        return -1;
    else 
        return arr[curLeft++];
}

int size(void)
{
    return curRight-curLeft;
}


int front(void)
{
    if(empty())
        return -1;
    else 
        return arr[curLeft];
}

int back(void)
{
    if(empty())
        return -1;
    else 
        return arr[curRight-1];
}

int main(void)
{
    int n; scanf("%d", &n);
    while(n--)
    {
        string s; cin >> s;
        if(s=="push")
        {
            int tmp; scanf("%d", &tmp);
            push(tmp);
        }
        else if(s=="pop") printf("%d\n", pop());
        else if(s=="size") printf("%d\n", size());
        else if(s=="empty") printf("%d\n", empty());
        else if(s=="front") printf("%d\n", front());
        else if(s=="back") printf("%d\n", back());
    }
}

/*
    
*/