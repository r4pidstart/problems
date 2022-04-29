// https://www.acmicpc.net/problem/10158
// 2022-04-30 04:41:11 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int w,h,p,q,t; scanf("%d%d%d%d%d", &w, &h, &p, &q, &t);
	// t%=lcm(2*w, 2*h);
	// int dir_p=0, dir_q=0;
	// while(t--)
	// {
	// 	if(p==0 and dir_p) dir_p=0;
	// 	else if(p==w and !dir_p) dir_p=1;

	// 	if(dir_p) p--;
	// 	else p++;
		
	// 	if(q==0 and dir_q) dir_q=0;
	// 	else if(q==h and !dir_q) dir_q=1;
		
	// 	if(dir_q) q--;
	// 	else q++;
	// }
	int pt=t%(w*2), qt=t%(h*2);
	int dir_p=0, dir_q=0;
	while(pt--)
	{
		if(p==0 and dir_p) dir_p=0;
		else if(p==w and !dir_p) dir_p=1;

		if(dir_p) p--;
		else p++;
	}
	while(qt--)
	{
		if(q==0 and dir_q) dir_q=0;
		else if(q==h and !dir_q) dir_q=1;
		
		if(dir_q) q--;
		else q++;
	}
	printf("%d %d", p, q);
}

/*
	
*/