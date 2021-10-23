// https://www.acmicpc.net/problem/21235
// 2021-10-22 22:13:54 0ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n; scanf("%d", &n);
    vector<string> cycle=
        {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", 
        "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    string trash;
    map<string, pair<string, int> > dif={{"Bessie", {"Ox", 0}}};
    for(int i=0; i<n; i++)
    {
        string name1; cin >> name1;
        cin >> trash >> trash;
        string seq; cin >> seq;
        string animal; cin >> animal;
        cin >> trash >> trash;
        string name2; cin >> name2;

        int difference=0;
        auto it=find(cycle.begin(), cycle.end(), animal);
        string target=dif.find(name2)->second.first;
        if(seq == "previous")
        {
            if(it == cycle.end()-1) it=cycle.begin(), difference--;
            else it++, difference--;
            while(*it!= target)
            {
                it++, difference--;
                if(it == cycle.end()) it=cycle.begin();
            }
        }
        else
        {
            if(*it=="Ox") it=cycle.end()-1, difference++;
            else it--, difference++;
            while(*it != target)
            {
                if(it == cycle.begin()) it=cycle.end();
                it--, difference++;
            }
        }

        dif[name1]={animal, dif.find(name2)->second.second + difference};
    }

    printf("%d", abs(dif.find("Elsie")->second.second));
}

/*
    
*/