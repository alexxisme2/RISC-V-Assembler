#include<iostream>
#include<string>
#include<unordered_map>
#include<cmath>
#include "functs.h"
using namespace std;
//Returns the first register present in the input string and deletes it from the input string
string functs::get_reg(string &inp)
{
    
    string str= "";
    int i =0;

    while(i<inp.length() && inp[i] != ',' && inp[i] != ')')
    {
        if(inp[i]==';') 
        {
            inp = "";
            return str;
        }
        str+= inp[i];
        i++;
    }
    if(i<inp.length()-1) 
    {
        inp = inp.substr(i+2,inp.length()-1);
        if(inp[0]==';') inp = "";
    }
    else inp = "";

    return str;
}
//Returns the first immediate present in the input string and deletes it from the input string
string functs::get_imm(string &inp)
{
    
    string str= "";
    int i =0;
    while(i<inp.length() && inp[i] != '(' && inp[i] != ',')
    {
        if(inp[i]==';') 
        {
            inp = "";
            return str;
        }
        str+= inp[i];
        i++;
    }
    if(inp[i] == '(') i--;
    if(i<inp.length()-1) 
    {
        inp = inp.substr(i+2,inp.length()-1);
        if(inp[0]==';') inp = "";
    }
    else inp = "";
    return str;
}
//Returns the Label present in the input string and deletes it from the input string
string functs::get_label(string &inp)
{
    string str= "";
    int i =0;
    
    while(i<inp.length() && inp[i] != ' ' && inp[i] != ',')
    {
        if(inp[i]==';') 
        {
            inp = "";
            return str;
        }
        str+= inp[i];
        i++;
    }
    if(inp[i] == ' ')i--;
    if(i<inp.length()-1) 
    {
        inp = inp.substr(i+2,inp.length()-1);
        if(inp[0]==';') inp = "";
    }
    else inp = "";
    return str;
}
//Converts the given binary to hexadecimal
string functs::bin_to_hex(string bin)
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
//Updates teh unordered_map alias with the aliases name and its corresponding register
void functs::ini_alia(unordered_map<string,string> &alias)
{
    alias.insert({"zero","x0"});
    alias.insert({"ra","x1"});
    alias.insert({"sp","x2"});
    alias.insert({"gp","x3"});
    alias.insert({"tp","x4"});
    alias.insert({"t0","x5"});
    alias.insert({"t1","x6"});
    alias.insert({"t2","x7"});
    alias.insert({"s0","x8"});
    alias.insert({"fp","x8"});
    alias.insert({"s1","x9"});
    alias.insert({"a0","x10"});
    alias.insert({"a1","x11"});
    alias.insert({"a2","x12"});
    alias.insert({"a3","x13"});
    alias.insert({"a4","x14"});
    alias.insert({"a5","x15"});
    alias.insert({"a6","x16"});
    alias.insert({"a7","x17"});
    alias.insert({"s2","x18"});
    alias.insert({"s3","x19"});
    alias.insert({"s4","x20"});
    alias.insert({"s5","x21"});
    alias.insert({"s6","x22"});
    alias.insert({"s7","x23"});
    alias.insert({"s8","x24"});
    alias.insert({"s9","x25"});
    alias.insert({"s10","x26"});
    alias.insert({"s11","x27"});
    alias.insert({"t3","x28"});
    alias.insert({"t4","x29"});
    alias.insert({"t5","x30"});
    alias.insert({"t6","x31"});
}
//Converts a given decimal number to binary with len digits , 
// sign = true signed representation
// sign = false unsigned representation 
string functs::to_bin(string num, int len, bool sign)
{
    string bin ="";
    int a = stoi(num);
    if(sign && (a > pow(2,len-1)-1 || a < -pow(2,len-1)) ) 
    {
        cout<<"Value exceeds the assigned bits limit : ";
        return num.substr(-1);
    }
    if(!sign && (a > pow(2,len)-1 || a < -pow(2,len)))
    {
        cout<<"Value exceeds the assigned bits limit : ";
        return num.substr(-1);
    }
    for (int i = len-1; i>= 0; i--) {
        int k = a >> i;
        if (k & 1)
            bin+= "1";
        else
            bin+="0";
    }
   
    return bin;
}
//Finds and stores the label along with its line number in map and rev_map,
//returns 0 : If duplicate label foudn
//returns 2: If Label format is wrong
//returns 1: if label stored successfully
int functs::store_labels(string inp, unordered_map<string,int>&map ,unordered_map<int,string>&rev_map, int line){

    for(int i = 0 ; i < inp.length() ; i++)
    {
        if(inp[i] == ':')
        {
            if(map.count(inp.substr(0,i)))
            {
                return 0;
            }
            if(inp[i-1]== ' ') return 2;
            map.insert({inp.substr(0,i),line});
            rev_map.insert({line,inp.substr(0,i)});
            return 1;
            
        }
    }
    return 1;
}