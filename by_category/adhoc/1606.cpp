#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int a,b; scanf("%d%d", &a, &b);
	long ans=1, floor=0;

	if(!b) floor++;
	while(b--)
		ans+=floor++*6+1;
	while(a--)
		ans+=floor++*6;
	printf("%ld", ans);
}
