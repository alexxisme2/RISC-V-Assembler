#include<iostream>
#include<string>
#include<unordered_map>
#include "u_format.h"
#include "functs.h"
using namespace std;
//returns the converted hex decimal machine code
string u_format::get_hex(string &inp, InstData *inst_data)
{
    unordered_map<string, string> alias;
    functs fnc;
    fnc.ini_alia(alias);

    string rd = fnc.get_reg(inp);
    if(rd[0] != 'x') rd = alias.at(rd);

    string imm = fnc.get_imm(inp);
    string imm_bin = fnc.to_bin(imm, 20,true);
   
    if(inp.length() > 0)
    {
        cout<<"More arguments than required :";
        return rd.substr(-1);
    }

    string comp_inst =  imm_bin+ fnc.to_bin(rd.substr(1,rd.length()-1),5,false) + inst_data->Opcode;

    string hex_inst = fnc.bin_to_hex(comp_inst);
    
    return hex_inst;
}