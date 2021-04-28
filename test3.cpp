
#include<bits/stdc++.h>
using namespace std;
typedef struct
{
    int x,y;
} coordinate;

coordinate car1, car2, cases[1001];

int main(void)
{
    int n,n_cases; scanf("%d%d", &n, &n_cases);
    
    for(int i=0; i<n_cases; i++)
    {
        scanf("%d%d", &cases[i].x,&cases[i].y);
    }
    
    vector<int> ans;
    int total_distance=0;
    car1={1,1}, car2={n,n};

    for(int index=0; index<n_cases; index++)
    {
        int car1_dist=abs(car1.x-cases[index].x)+abs(car1.y-cases[index].y),
            car2_dist=abs(car2.x-cases[index].x)+abs(car2.y-cases[index].y);
        if(car1_dist > car2_dist)
        {
            car2=cases[index];
            total_distance+=car2_dist;
            ans.push_back(2);
        }
        else
        {
            car1=cases[index];
            total_distance+=car1_dist;
            ans.push_back(1);
        }
    }

    printf("%d\n", total_distance);
    for(int num : ans)
        printf("%d\n", num);
    
}