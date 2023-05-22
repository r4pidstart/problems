#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n,m; scanf("%d%d", &n, &m);
	int cnt=0;
	int table[n][m];
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			scanf("%d", &table[i][j]), cnt+=table[i][j];

	int flag=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			if(i and table[i][j] == table[i-1][j]) flag=1;
			if(j and table[i][j] == table[i][j-1]) flag=1;
		}

	if(flag and cnt%2==0 and n*m%2==0)
		printf("1");
	else
		printf("-1");
}
