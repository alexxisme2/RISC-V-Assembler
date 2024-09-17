#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string bin_to_hex(string bin)
{
    int len = bin.length();
    string hex = "";
    while(bin.length()>0)
    {
        string temp = bin.substr(len-4,4);
        bin = bin.substr(0,len-4);
        int num = 0;
        for(int i = 3; i>=0;i--)
        {
            if(temp[3-i] == '1') num+= pow(2,i);
        }
        if(num <= 9) hex =to_string(num)+hex;
        else hex = (char)(num+87) + hex;
        len += -4;
    }
    return hex;
}
int main(){
    string a = bin_to_hex("00000000001000001000001001100011");
    cout<<a;
}