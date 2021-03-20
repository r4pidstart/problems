
#include<iostream>
#include<deque>
#include<string>
using namespace std;
int main(void)
{
    int t; scanf("%d", &t);
    while(t--)
    {
        string s;
        cin >> s;
        int n, p=s.size(), count_d=0, flag=0;
        scanf("%d", &n);
        for(int i=0; i<p; i++)
            if(s[i]=='D')
                count_d++;
        deque <int> dq(n);

        getchar(); // \n
        getchar(); // [
        for(int i=0; i<n; i++)
        {
            scanf("%d", &dq[i]);
            getchar(); // ; or last ]
        }
        if(n==0)
            getchar(); // ]
            
        if(count_d>n)
        {
            printf("error\n");
            continue;
        }

        for(int i=0; i<p; i++)
        {
            if(s[i]=='R')
                if(flag==0)
                    flag=1;
                else
                    flag=0;
            else // s[i]=='D'
                if(flag==0)
                {
                    dq.pop_front();
                }
                else
                {
                    dq.pop_back();
                }
        }

        if(dq.size()==0)
        {
            printf("[]\n");
        }
        else if(flag==0)
        {
            printf("[");
            for(int i=0; i<n-1; i++)
                printf("%d,", dq[i]);
            printf("%d]\n", dq[n-1]);
        }
        else
        {
            printf("[");
            for(int i=n-1; i!=0; i--)
                printf("%d,", dq[i]);
            printf("%d]\n", dq[0]);
        }
    }
}