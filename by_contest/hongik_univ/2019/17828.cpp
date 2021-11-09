// https://www.acmicpc.net/problem/17828
//2021-11-10 02:47:52 D
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	long long n,x; scanf("%lld%lld", &n,&x);
	vector<char> arr(n);
	
	if(x<n or x>n*26) return !printf("!");

	int cntZ=x/26, remain=x%26; // 최대 Z 개수
	while(cntZ+remain < n)
	{
		cntZ--, remain+=26;
	}
	
	if(x==n*26)
	{
		while(cntZ--) printf("Z");
	}
	else
	{
		int cntA=n-cntZ-1;
		int target=remain-cntA;
		while(cntA--) printf("A");
		if(target) printf("%c", 'A'-1+target);
		while(cntZ--) printf("Z"); 
	}
}

/*

*/