// https://www.acmicpc.net/problem/17826
// 2021-11-10 01:58:13 A
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	vector<int> arr(50);
	for(int i=0; i<50; i++) scanf("%d", &arr[i]);
	int target; scanf("%d", &target);
	int loca = lower_bound(arr.rbegin(), arr.rend(), target)-arr.rbegin();
	if(50-loca<=5) printf("A+");
	else if(50-loca<=15) printf("A0");
	else if(50-loca<=30) printf("B+");
	else if(50-loca<=35) printf("B0");
	else if(50-loca<=45) printf("C+");
	else if(50-loca<=48) printf("C0");
	else if(50-loca<=50) printf("F");
}

/*
	
*/