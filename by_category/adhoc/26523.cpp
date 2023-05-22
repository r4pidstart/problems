#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	for(int t=0; t<100; t++)
	{
		int n=5000;
		int low=0;
		for(int i=0; i<n; i++)
		{
			double a; scanf("%lf", &a);
			if(0.0<=a and a<=0.1) low++;
		}
		if(low < 400) printf("B\n");
		else printf("A\n");
	}
}
