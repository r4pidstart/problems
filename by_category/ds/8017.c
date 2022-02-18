// https://www.acmicpc.net/problem/8017
// 2022-02-19 02:24:32 372ms

#include<stdlib.h>
#include<stdio.h>

enum e_stack
{
	INIT = 0,
	PUSH = 1,
	POP = 2,
	TOP = 3,
	IS_EMPTY = 4,
	CLEAR = 5
};

int	stack(int cmd, int value)
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

void	memorization(int size, int **table, int **dp)
{
	int	i;
	int	j;

	i = 0;
	while (++i <= size)
	{
		j = 0;
		while (++j <= size)
		{
			if (!table[i][j])
				dp[i][j] = dp[i-1][j] + 1;
			else
				dp[i][j] = 0;
		}
	}
}

int	memory_allocation(int size, int ***table, int ***dp)
{
	int	i;
	int	j;

	i = -1;
	*table = (int **)malloc(sizeof(int *) * size);
	*dp = (int **)malloc(sizeof(int *) * size);
	if (!table || !dp)
		return (1);
	while (++i < size)
	{
		(*table)[i] = (int *)malloc(sizeof(int) * size);
		(*dp)[i] = (int *)malloc(sizeof(int) * size);
		if (!(*table)[i] || !(*dp)[i])
			return (1);
		j = -1;
		while (++j < size)
			(*dp)[i][j] = 0;
	}
	return (0);
}

int	solve(int size, int **dp)
{
	int	i;
	int	j;
	int	ans;
	int	tmp;

	ans = 0;
	stack(INIT, size);
	i = 0;
	while (++i <= size)
	{
		j = -1;
		stack(CLEAR, 0);
		while (++j <= size + 1)
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
	return (ans);
}

int	main(int argc, char *argv[])
{
	int	n;
	int	i;
	int	j;
	int	**table;
	int	**dp;

	(void)argc, (void)argv;
	table = 0;
	dp = 0;
	scanf("%d", &n);
	if (memory_allocation(n+2, &table, &dp))
		return (1);
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			scanf("%d", &table[i+1][j+1]);
	}
	memorization(n, table, dp);
	printf("%d", solve(n, dp));
}
