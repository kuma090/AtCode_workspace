/*
問題文
高橋君は新しい会社を作ろうとしています。 今回は検索サイトの会社を作ることにしたため、yahoo の 5 文字を並び替えた文字列を社名にすることにしました。

友人の青木君は、新しい会社の名前として文字列 S を提案しました。この文字列が高橋君の希望に合うかどうかを判定してください。

制約
|S|=5
S は英小文字のみからなる。
*/

#include <iostream>
#include <string.h>

using namespace std;

bool seek_char_sometimes(char* , char, int , int , int&, int j=0);

int main(void)
{
    string str;
    char s[6];
    char yahoo[6] = "yahoo";
    bool b[6] = {0,0,0,0,0,0};
    size_t szy = sizeof(yahoo)/sizeof(*yahoo);
    size_t szs = sizeof(s)/sizeof(*s);
    size_t szb = sizeof(b)/sizeof(*b);

    cin >> str;

    if(str.length() == 5)
    {   
        strcpy(s, str.c_str());
    }else{
        cout << "NO" << endl;
        return 0;
    }

    for(int i=0; i<szy; ++i)
    {
        for(int j=0; j<szs; ++j)
        {
            if(yahoo[i] == s[j])
            {
                b[i] = 1;
                break;
            }
        }
    }

    for(int k; k<szb; ++k)
    {
        if(b[k] != 1)
        {
            cout << "NO" << endl;
            return 0;    
        } 
    } 

    int i=0;
    int counter =0;

    char rr[8] = "aaabbbc";
    counter =0;
    cout << seek_char_sometimes(rr,'a',3,8,counter) <<endl;

    int a = 5;

    cout << (a == 4? 1:0) << endl;

    if(seek_char_sometimes(s,'o',2, szs, counter))
    {
        cout << "YES" <<endl;
        return 0;
    }

    cout << "NO" <<endl;

    return 0;
}

//sの中でcがn回現れているかどうか調べる
bool seek_char_sometimes(char* s, char c, int n, int sz, int& counter, int j)
{
    for(; j<sz; ++j)
    {
        if(s[j] == c)
        {
            ++counter;
            return counter == n? 1: seek_char_sometimes(s,c,n,sz,counter,j);
        }
    }
    return 0;
}