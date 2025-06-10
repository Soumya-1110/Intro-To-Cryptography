#include <bits/stdc++.h>
using namespace std;

string affine(string str, int k, int a)
{
    for(int i=0;i<str.length();i++)
    {
        if (str[i]>='a' && str[i]<= 'z')str[i]=((str[i]-'a')*a + k)%26 + 'a';
        if (str[i]>='A' && str[i]<= 'Z')str[i]=((str[i]-'A')*a + k)%26 + 'A';
    }
    return str;
}
int main()
{
    string str;
    getline(cin, str, '\n');

    for(int b=0;b<= 25;b++){
        for(int a=0;a<=26;a++){
            if((a%2) && a!=13){
                string newstr = affine(str,b,a);
                cout<<newstr<<" "<<a<<" "<<b<<endl;
            }
        }
    }
    return 0;
}