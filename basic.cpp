#include<iostream>
#include <string>
#include <fstream>
#include <queue>
#include <unordered_map>
#include "InstData.h"
#include "r_format.h"
#include "i_format.h"
#include "s_format.h"
#include "b_format.h"
#include "j_format.h"
#include "u_format.h"
#include "functs.h"
using namespace std;

//goes through the input file and checks for labels, if duplicate or wrong format label found removes it from input file
//else stores it in labels and line_labels unordered_map
void get_labels(unordered_map<string,int> &labels, unordered_map<int,string> &line_labels)
{
    
    string str;
    ifstream MyReadFile("input.s");
    functs f;
    queue<string> q;
    int counter = 0;
    while(getline(MyReadFile,str))
    {
        
        counter++;
        int l = labels.size();
        
        int check = f.store_labels(str,labels,line_labels, counter);
        if(check == 0)
        {
            cout<<"Label cannot be duplicate, removing -> " << str<< " from line "<<counter<<endl;
            counter--;
            continue;
        }
        if(check == 2)
        {
            cout<<"Label format is wrong, removing -> " << str<< " from line "<<counter<<endl;
            counter--;
            continue;
        }
        q.push(str);
    }
    
    MyReadFile.close();
    remove("input.s");

    ofstream newFile("input.s");
    while(!q.empty())
    {
        newFile<<q.front()<<endl;
        q.pop();
    }
    newFile.close();
}

int main(){
    string inp;
    InstData instdat ;
    unordered_map<string,int> label;
    unordered_map<int,string> line_labels;
    get_labels(label,line_labels);
    ofstream MyFile("output.hex");
    ifstream MyReadFile("input.s");
    unordered_map<string,InstData*> inst_table;
    instdat.getInstData(inst_table);
    int line_num = 0;

    while(getline(MyReadFile, inp))
    {
        //if input is empty continue
        if(inp == "" || inp[0]==';'|| (int(inp[inp.length()-1]) == 13 && inp.length()==1))continue;
        line_num++;
        //if input has a carriage return , remove it
        if(int(inp[inp.length()-1]) == 13) inp = inp.substr(0,inp.length()-1);
        string inp_copy = inp;
        //if line has label remove it
        if(line_labels.count(line_num)) 
        {
            inp = inp.substr(line_labels.at(line_num).length()+2);
            
        }

        string inst = instdat.getInst(inp);
        if(inst == "nop"){
            inp = "x0, x0, 0";
            inst = "addi";
        }
        if(!inst_table.count(inst))
        {
            cout<< "Could not translate " << inp_copy << " (No such instruction found : " <<inst<<" at line number  " << line_num<< endl; 
            continue;
        }
        InstData *temp =  inst_table[inst];
        string hex = ""; 
        try
        {
            if(temp->Opcode == "0110011")
            {
                r_format r;
                hex= r.get_hex(inp,temp);
            }
            else if(temp->Opcode == "0010011")
            {
                i_format i;
                hex= i.get_hex(inp,temp);
            }
            else if(temp->Opcode == "0000011" || temp->Opcode == "1100111")
            {
                i_format i;
                hex= i.get_hex(inp,temp);
            }
            else if(temp->Opcode == "0100011")
            {
                s_format s;
                hex= s.get_hex(inp,temp);
            }
            else if(temp->Opcode == "1100011")
            {
                b_format b;
                hex= b.get_hex(inp,temp,line_num,label);
            }
            else if(temp->Opcode == "1101111")
            {
            
                j_format j;
                hex= j.get_hex(inp,temp,line_num,label);
              
            } 
            else if(temp->Opcode == "0110111" || temp->Opcode == "0010111")
            {
            
                u_format u;
                hex= u.get_hex(inp,temp);
              
            }
            MyFile<<hex<<endl;
        }
        catch(const exception& e)
        {
            cout<< "Could not translate " << inp_copy << " at line number " << line_num<< endl; 
        }
        
        
    }
    MyFile.close();
    MyReadFile.close();
    
    return 0;
}