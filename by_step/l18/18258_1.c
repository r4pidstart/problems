// https://www.acmicpc.net/submit/18258
// 2021-03-20 01:44:58 time exceeded
#include<stdio.h>
#include<string.h>
int main(void)
{
    int n,top=0; char s[5]; scanf("%d", &n);
    int queue[n+1];
    while(n--)
    {
        scanf("%s", s);
        switch (s[0])
        {
        case 'p':
            if(s[1]=='u') // push
            {
                scanf("%d", &queue[top++]);
            }
            else // pop
            {
                if(top==0)
                    printf("-1\n");
                else
                {
                    printf("%d\n", queue[0]);
                    memcpy(queue, queue+1, sizeof(int)*(--top));
                }
            }
            break;
        
        case 's': // size
            printf("%d\n", top);
            break;

        case 'e': // empty
        if(top==0)
            printf("1\n");
        else
            printf("0\n");
        break;

        case 'f': // front
            if(top==0)
                printf("-1\n");
            else
            printf("%d\n", queue[0]);
        break;

        case 'b': // back
            if(top==0)
                printf("-1\n");
            else
                printf("%d\n", queue[top-1]);
        break;
        }
    }
}