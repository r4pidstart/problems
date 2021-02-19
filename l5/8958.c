#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    while(N)
    {
        char s[79]={0,};
        scanf("%s", s);
        int score=0, streak=0, n=(sizeof(s)/sizeof(char));
        for (int i=0; i<n; i++)
        {
            if (s[i] == 'O')
                score += ++streak;
            else
                streak = 0;
        }
        N--;
        printf("%d\n", score);
    }
}