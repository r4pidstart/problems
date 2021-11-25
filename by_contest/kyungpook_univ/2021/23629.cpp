// https://www.acmicpc.net/problem/23629
// 2021-11-25 13:37:04 8ms
#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<char> operators;
    vector<int> operands(1,0);
    string s; cin >> s;

    int idx=0;
    while(idx<s.length())
    {
        int prevIdx=idx;
        // num
        if(s.substr(idx, 4) == "ZERO")
            operands.back()=operands.back()*10 + 0, idx+=4;
        else if(s.substr(idx, 3) == "ONE")
            operands.back()=operands.back()*10 + 1, idx+=3;
        else if(s.substr(idx, 3) == "TWO")
            operands.back()=operands.back()*10 + 2, idx+=3;
        else if(s.substr(idx, 5) == "THREE")
            operands.back()=operands.back()*10 + 3, idx+=5;
        else if(s.substr(idx, 4) == "FOUR")
            operands.back()=operands.back()*10 + 4, idx+=4;
        else if(s.substr(idx, 4) == "FIVE")
            operands.back()=operands.back()*10 + 5, idx+=4;
        else if(s.substr(idx, 3) == "SIX")
            operands.back()=operands.back()*10 + 6, idx+=3;
        else if(s.substr(idx, 5) == "SEVEN")
            operands.back()=operands.back()*10 + 7, idx+=5;
        else if(s.substr(idx, 5) == "EIGHT")
            operands.back()=operands.back()*10 + 8, idx+=5;
        else if(s.substr(idx, 4) == "NINE")
            operands.back()=operands.back()*10 + 9, idx+=4;

        // operator
        if(s[idx] == '+')
            operands.push_back(0), operators.push_back('+'), idx++;
        else if(s[idx] == '-')
            operands.push_back(0), operators.push_back('-'), idx++;
        else if(s[idx] == 'x')
            operands.push_back(0), operators.push_back('x'), idx++;
        else if(s[idx] == '/')
            operands.push_back(0), operators.push_back('/'), idx++;
        else if(s[idx]== '=')
            operands.push_back(0), operators.push_back('='), idx++;
    
        if(prevIdx==idx) return !printf("Madness!");
    }

    for(int i=0; i<operands.size()-1; i++)
        if(operands[i]==0) return !printf("Madness!");

    if(operands.size()-operators.size() != 1) return !printf("Madness!");

    // calculate
    long long ans=operands[0];
    printf("%d", operands[0]);
    for(int i=0; i<operators.size()-1; i++)
    {
        printf("%c%d", operators[i], operands[i+1]);
        if(operators[i]=='+')
            ans=ans+operands[i+1];
        if(operators[i]=='-')
            ans=ans-operands[i+1];
        if(operators[i]=='x')
            ans=ans*operands[i+1];
        if(operators[i]=='/')
            ans=ans/operands[i+1];
    }
    printf("=\n");


    stack<string> stk;
    int flag=0;
    if(ans<0) flag++, ans=-ans;
    if(!ans) stk.push("ZERO");
    while(ans)
    {
        int tmp=ans%10; 
        ans/=10;
        
        if(tmp==0) stk.push("ZERO");
        else if(tmp==1) stk.push("ONE");
        else if(tmp==2) stk.push("TWO");
        else if(tmp==3) stk.push("THREE");
        else if(tmp==4) stk.push("FOUR");
        else if(tmp==5) stk.push("FIVE");
        else if(tmp==6) stk.push("SIX");
        else if(tmp==7) stk.push("SEVEN");
        else if(tmp==8) stk.push("EIGHT");
        else if(tmp==9) stk.push("NINE");
    }

    if(flag) cout << '-';
    while(!stk.empty())
        cout << stk.top(), stk.pop();
}

/*
    
*/