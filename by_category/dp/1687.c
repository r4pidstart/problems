// https://www.acmicpc.net/problem/1687
// 2024-02-23 03:40:36
#include<stdlib.h>
#include<stdio.h>
#include<iso646.h>

int	table[2002][2002], dp[2002][2002];
enum e_stack
{
	INIT = 0,
	PUSH = 1,
	POP = 2,
	TOP = 3,
	IS_EMPTY = 4,
	CLEAR = 5
};

inline int	stack(int cmd, int value)
{
	static int	cur;
	static int	*stk;

	if (cmd == INIT)
	{
		cur = -1;
		stk = (int *)malloc(sizeof(int) * (value + 2));
		return (!stk);
	}
	else if (cmd == PUSH)
	{
		stk[++cur] = value;
		return (0);
	}
	else if (cmd == POP)
		return (stk[cur--]);
	else if (cmd == TOP)
		return (stk[cur]);
	else if (cmd == IS_EMPTY)
		return (cur == -1);
	else
	{
		cur = -1;
		return (0);
	}
}

int	main(void)
{
	int	x, y;
    while(scanf("%d %d", &x, &y) != -1 and (x or y))
    {
        int	i;
        int	j;
        int	ans;
        int	tmp;
        
        i = -1;
        while (++i < x)
        {
            j = -1;
            while (++j < y)
                scanf("%1d", &table[i+1][j+1]);
        }

        i = 0;
        while (++i <= x)
        {
            j = 0;
            while (++j <= y)
            {
                if (!table[i][j])
                    dp[i][j] = dp[i-1][j] + 1;
                else
                    dp[i][j] = 0;
            }
        }

        ans = 0;
        stack(INIT, x+y);
        i = 0;
        while (++i <= x)
        {
            j = -1;
            stack(CLEAR, 0);
            while (++j <= y + 1)
            {
                while (!stack(IS_EMPTY, 0) && dp[i][j] < dp[i][stack(TOP, 0)])
                {
                    tmp = stack(POP, 0);
                    if (ans < (j - stack(TOP, 0) - 1) * dp[i][tmp])
                        ans = (j - stack(TOP, 0) - 1) * dp[i][tmp];
                }
                stack(PUSH, j);
            }
        }
        printf("%d\n", ans);
    }
}
