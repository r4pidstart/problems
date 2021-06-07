// https://www.acmicpc.net/submit/18258
// 2021-03-20 02:07:52 588ms
#include<stdio.h>
int main(void)
{
    int n,front=0,rear=0; char s[5]; scanf("%d", &n);
    int queue[n+1];
    while(n--)
    {
        scanf("%s", s);
        switch (s[0])
        {
        case 'p':
            if(s[1]=='u') // push
            {
                scanf("%d\n", &queue[++rear]);
            }
            else // pop
            {
                if((rear-front)==0)
                    printf("-1\n");
                else
                    printf("%d\n", queue[++front]);
            }
            break;
        
        case 's': // size
            printf("%d\n", rear-front);
            break;

        case 'e': // empty
            if((rear-front)==0)
                printf("1\n");
            else
                printf("0\n");
        break;

        case 'f': // front
            if((rear-front)==0)
                printf("-1\n");
            else
                printf("%d\n", queue[front+1]);
        break;

        case 'b': // back
            if((rear-front)==0)
                printf("-1\n");
            else
                printf("%d\n", queue[rear]);
        break;
        }
    }
}