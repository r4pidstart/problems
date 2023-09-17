// https://www.acmicpc.net/problem/
// 
#include"bits/stdc++.h"
using namespace std;

/*
보고서에 단어 'Korea'가 등장할 경우, 다음에 나오는 단어와 합쳐 'K-단어'로 축약한다. (ex. Korea language → K-Language)
단어 'Korea'는 대문자와 소문자를 구분한다. v
단어 'Korea' 다음에 나오는 단어의 첫 글자가 소문자일 경우 대문자로 변환한다. v
이 규칙을 여러 번 연달아 적용할 수 있는 경우 뒤에서부터 적용한다. v
단어 'Korea' 뒤에 문장 부호가 붙어 있는 경우 이 규칙을 적용할 수 없다. v
*/
string applyRule1(const string& input) 
{
    string result = input;

    size_t pos=result.rfind("Korea ");
    while(pos != string::npos)
    {
        if(!pos or (pos>=1 and result[pos-1]==' '))
        {
            result[pos+5+1]=toupper(result[pos+5+1]);
            result.replace(pos, 5+1, "K-");
        }
        if(!pos) break;
        pos=result.rfind("Korea ", pos-1);
    }
    
    return result;
}

/*
보고서에 단어 'of' 직후에 단어 'Korea'가 등장할 경우, 단어 'of' 직전에 나오는 단어와 합쳐 K-단어로 축약한다. (ex. Language of Korea → K-Language)
단어 'of'와 'Korea'는 대문자와 소문자를 구분한다. v
단어 'of' 직전에 나오는 단어의 첫 글자가 소문자일 경우 대문자로 변환한다. v
이 규칙을 여러 번 연달아 적용할 수 있는 경우 앞에서부터 적용한다. v
단어 'of' 뒤에 문장 부호가 붙어 있는 경우 이 규칙을 적용할 수 없다. v
단어 'of' 앞에 단어가 없거나, 단어 'of' 직전에 나오는 단어에 문장 부호가 붙어 있는 경우 이 규칙을 적용할 수 없다. v
단어 'Korea' 뒤에 문장 부호가 붙어있는 경우, 단어 'Korea' 뒤의 문장 부호를 단어 'of' 직전에 나오는 단어 뒤에 붙인다. v
*/
string applyRule2(const string& input) 
{
    string result = input;

    size_t pos=result.find(" of Korea");
    while(pos != string::npos)
    {
        if(pos+9 < result.size() and !isalpha(result[pos+9]))
        {
            int start=pos-1;
            while(0<start and result[start]!=' ')
                start--;
            if(result[start] == ' ')
                start++;

            vector<string> arr;
            stringstream ss(result.substr(start, pos+8-start+1));
            string tmp;
            while(ss >> tmp)
                arr.push_back(tmp);

            arr[0][0]=toupper(arr[0][0]);
            if(isalpha(arr[0].back()))
                result.replace(start, pos+8-start+1, "K-"+arr[0]);
        }

        pos=result.find(" of Korea", pos+1);
    }
    return result;
}

int main(void) 
{
    int n; scanf("%d", &n);
    
    string input;
    cin >> ws;
    for(int i=0; i<n; i++)
    {
        getline(cin, input);
        string rule2_result = applyRule2(input);
        string final_result = applyRule1(rule2_result);
        cout << final_result << '\n';
        // cout << applyRule2(input) << '\n';
    }
}


/*
    
*/