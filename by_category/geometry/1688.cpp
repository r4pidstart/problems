// https://www.acmicpc.net/problem/1688
// 2023-05-13 15:13:54
#include"bits/stdc++.h"
using namespace std;

#define x first
#define y second
#define Point pair<long,long>

inline long ccw(const pair<long,long>& a, const pair<long,long>& b, const pair<long,long>& c)
{
	// af bf cf af
	// as bs cs as
	__int128_t z=1;
	__int128_t tmp=(z*a.first*b.second+b.first*c.second+c.first*a.second),
			   tmp2=(z*b.first*a.second+c.first*b.second+a.first*c.second);
	if(tmp<tmp2) return -1;
	else if(tmp==tmp2) return 0;
	else return 1;
}

int _test(pair<long,long> a, pair<long,long> b, pair<long,long> c, pair<long,long> d)
{
	long one=ccw(a,b,c)*ccw(a,b,d), 
		two=ccw(c,d,a)*ccw(c,d,b);
    if(one <= 0 && two <= 0)
        if(one==two && one==0) // 일직선인경우
        {
            if(a > b) swap(a,b);
            if(c > d) swap(c,d);
			return c<=b && a<=d;     
        }
        else
            return 1;
    else
        return 0;
}

int main(void)
{
#ifdef LOCAL
#endif
	int n; scanf("%d", &n);
	vector<pair<long, long> > arr(n);
	for(int i=0; i<n; i++)
		scanf("%ld%ld", &arr[i].first, &arr[i].second);	
	
	for(int i=0; i<3; i++)
	{
		pair<long,long> target;
		scanf("%ld%ld", &target.first, &target.second);
		pair<long,long> inf(1000000001, target.y+1);
		int flag=0, cnt=0;
		for(int i=0; i<n; i++)
		{
			// check the intersection between target to inf and arr[i] to arr[i+1]
			// is target on the line?
			if(_test(target, target, arr[i], arr[(i+1)%n]))
				flag=1;
			if(_test(target, inf, arr[i], arr[(i+1)%n]))
				cnt++;
		}
		if(cnt&1) flag=1;
		printf("%d\n", flag);
		// printf("%d\n", isSafe(target, arr));
	}
}

/*
	
*/