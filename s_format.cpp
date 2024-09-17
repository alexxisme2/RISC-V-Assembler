#include<iostream>
#include<string>
#include<unordered_map>
#include "s_format.h"
#include "functs.h"
using namespace std;
//returns the converted hex decimal machine code
string s_format::get_hex(string &inp, InstData *inst_data)
{
    unordered_map<string, string> alias;
    functs fnc;
    fnc.ini_alia(alias);

    string rs2 = fnc.get_reg(inp);
    if(rs2[0] != 'x') rs2 = alias.at(rs2);

    string imm = fnc.get_imm(inp);
    string imm_bin = fnc.to_bin(imm, 12,true);

    string rs1 = fnc.get_reg(inp);
    if(rs1[0] != 'x') rs1 = alias.at(rs1);
    if(inp.length() > 0)
    {
        cout<<"More arguments than required :";
        return rs1.substr(-1);
    }
    string comp_inst =  imm_bin.substr(0,7)+ fnc.to_bin(rs2.substr(1,rs2.length()-1),5,false) +fnc.to_bin(rs1.substr(1,rs1.length()-1),5,false)
                        +inst_data->funct3 + imm_bin.substr(7,5) + inst_data->Opcode;

    string hex_inst = fnc.bin_to_hex(comp_inst);
    
    return hex_inst;
}