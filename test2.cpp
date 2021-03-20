
#include<iostream>
#include<string>
#include<deque>
using namespace std;
int main(void)
{
    int t,tmp; scanf("%d", &t);
    deque <int> dq;
    char str[11];
    while(t--)
    {
        scanf("%s", str);
        string s = str;
        if(s=="push_back")
        {
            scanf("%d", &tmp);
            dq.push_back(tmp);
        }
        else if(s=="push_front")
        {
            scanf("%d", &tmp);
            dq.push_front(tmp);
        }
        else if(s=="pop_front")
        {
            if(dq.empty())
                printf("-1\n");
            else
            {  
                printf("%d\n", dq.front());
                dq.pop_front();
            }
        }
        else if(s=="pop_back")
        {
            if(dq.empty())
                printf("-1\n");
            else
            {
                printf("%d\n", dq.back());
                dq.pop_back();
            }
        }
        else if(s=="size")
        {
            printf("%ld\n", dq.size());
        }
        else if(s=="empty")
        {
            printf("%d\n", dq.empty() ? 1:0);
        }
        else if(s=="front")
        {
            if(dq.empty())
                printf("-1\n");
            else
                printf("%d\n", dq.front());
        }
        else // s=="back"
        {
            if(dq.empty())
                printf("-1\n");
            else
                printf("%d\n", dq.back());
        }
        
    }
}