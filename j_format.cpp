#include<iostream>
#include<string>
#include<unordered_map>
#include "j_format.h"
#include "functs.h"
using namespace std;
//returns the converted hex decimal machine code
string j_format::get_hex(string &inp, InstData *inst_data, int line , unordered_map<string,int> label_map)
{
    unordered_map<string, string> alias;
    functs fnc;
    fnc.ini_alia(alias);

    string rd = fnc.get_reg(inp);
    if(rd[0] != 'x') rd = alias.at(rd);

    string label =  fnc.get_label(inp);
    string offset = to_string((label_map.at(label) - line)*4);
    if(inp.length() > 0)
    {
        cout<<"More arguments than required :";
        return rd.substr(-1);
    }
    string off_bin = fnc.to_bin(offset, 21,true);


    string comp_inst = off_bin.substr(0,1) + off_bin.substr(10,10) + off_bin.substr(9,1) + off_bin.substr(1,8)
                        +fnc.to_bin(rd.substr(1,rd.length()-1),5,false)+inst_data->Opcode;

    string hex_inst = fnc.bin_to_hex(comp_inst);
    
    return hex_inst;
}