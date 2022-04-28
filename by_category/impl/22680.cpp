// https://www.acmicpc.net/problem/22680
// 2022-04-28 19:57:29 2728ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n; scanf("%d", &n);
	while(n)
	{
		int initial=n;
		int y=0,z=0;
		z+=pow(n, (double)1/3);
		n-=pow(z, 3);
		if(n)
		{
			y+=pow(n, (double)1/2);
			n-=pow(y, 2);
		}

		int sum=n+y+z;
		for(int i=0; i<=1000000; i++)
		{
			if(i >= sum) break;
			for(int j=0; j<=1000; j++)
			{
				if(i+j >= sum) break;
				for(int k=0; k<=100; k++)
				{
					if(i+j+k >= sum) break;
					if(i+j*j+k*k*k == initial)
						sum=i+j+k;
				}
			}

		}
		printf("%d\n", sum);
		scanf("%d", &n);
	}
}

/*
	
*/