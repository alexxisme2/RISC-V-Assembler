#include<iostream>
#include<string>
#include<unordered_map>
#include "b_format.h"
#include "functs.h"
using namespace std;
//returns the converted hex decimal machine code
string b_format::get_hex(string &inp, InstData *inst_data, int line , unordered_map<string,int> label_map)
{
    unordered_map<string, string> alias;
    functs fnc;
    fnc.ini_alia(alias);

    string rs1 = fnc.get_reg(inp);
    if(rs1[0] != 'x') rs1 = alias.at(rs1);

    string rs2 = fnc.get_reg(inp);
    if(rs2[0] != 'x') rs2 = alias.at(rs2);

    string label =  fnc.get_label(inp);
    string offset = to_string((label_map.at(label) - line)*4);
    if(inp.length() > 0)
    {
        cout<<"More arguments than required :";
        return rs1.substr(-1);
    }
    string off_bin = fnc.to_bin(offset, 13,true);

 
    string comp_inst = off_bin.substr(0,1) + off_bin.substr(2,6)+  fnc.to_bin(rs2.substr(1,rs2.length()-1),5,false) +fnc.to_bin(rs1.substr(1,rs1.length()-1),5,false)
                        +inst_data->funct3+ off_bin.substr(8,4) + off_bin.substr(1,1)  +inst_data->Opcode;

    string hex_inst = fnc.bin_to_hex(comp_inst);
    
    return hex_inst;
}