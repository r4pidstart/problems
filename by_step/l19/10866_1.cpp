// https://www.acmicpc.net/problem/10866
// 2021-03-20 18:24:39 failed
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main(void)
{
    int t; scanf("%d", &t);
    int front=0, back=0, deque[10001]={};
    char str[11];
    while(t--)
    {
        scanf("%s", str);
        string s = str;
        if(s=="push_back")
        {
            scanf("%d", &deque[back++]);
        }
        else if(s=="push_front")
        {
            if(front==0)
            {
                memcpy(deque+1, deque, sizeof(int)*(back-front));
                back++;
                scanf("%d", &deque[front]);
            }
            else
            {
                scanf("%d", &deque[--front]);
            }
        }
        else if(s=="pop_front")
        {
            if(back-front==0)
                printf("-1\n");
            else
                printf("%d\n", deque[front++]);
        }
        else if(s=="pop_back")
        {
            if(back-front==0)
                printf("-1\n");
            else
                printf("%d\n", deque[(back--)-1]);
        }
        else if(s=="size")
        {
            printf("%d\n", back-front);
        }
        else if(s=="empty")
        {
            printf("%d\n", back-front==0 ? 1:0);
        }
        else if(s=="front")
        {
            if(back-front==0)
                printf("-1\n");
            else
                printf("%d\n", deque[front]);
        }
        else // s=="back"
        {
            if(back-front==0)
                printf("-1\n");
            else
                printf("%d\n", deque[back-1]);
        }
        
    }
}