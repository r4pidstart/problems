// https://www.acmicpc.net/problem/
//
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    stack<int> stk;
    queue<char> ans;
    int last_n=1;
    for(int i=0; i<n; i++)
    {
        int target; scanf("%d", &target);
        if(last_n <= target) // 타겟이 스택에 아직 들어가지 않은 경우
        {
            // push + pop
            while(last_n <= target)
            {
                stk.push(last_n++);
                ans.push('+');
            }
            stk.pop();
            ans.push('-');
        }
        else // 타겟이 스택에 이미 들어가 있는 경우
        {
            // pop
            int check=stk.top();
            stk.pop();
            ans.push('-');
            if(check != target)
            {
                printf("NO");
                return 0;
            }
        }
    }
    while(!ans.empty())
    {
        printf("%c\n", ans.front());
        ans.pop();
    }
}

/*
    
*/