#include<iostream>
#include<string>
#include<unordered_map>
#include "i_format.h"
#include "functs.h"
using namespace std;
//returns the converted hex decimal machine code
string i_format::get_hex(string &inp, InstData *inst_data)
{
    unordered_map<string, string> alias;
    functs fnc;
    fnc.ini_alia(alias);
    int bin_Len = 12;
    string rd;
    string rs1;
    string imm;
    bool sign = true;

    if(inst_data->Opcode =="0010011" ){
        rd = fnc.get_reg(inp);
        if(rd[0] != 'x') rd = alias.at(rd);

        rs1 = fnc.get_reg(inp);
        if(rs1[0] != 'x') rs1 = alias.at(rs1);

        imm = fnc.get_imm(inp);
        
        if(inst_data->funct3 == "001" || inst_data->funct3 == "101"){
            bin_Len = 6;
            sign = false;
        } 
    }
    else{
        rd = fnc.get_reg(inp);
        if(rd[0] != 'x') rd = alias.at(rd);
 
        imm = fnc.get_imm(inp);

        rs1 = fnc.get_reg(inp);
        if(rs1[0] != 'x') rs1 = alias.at(rs1);

    }

    if(inp.length() > 0)
    {
        cout<<"More arguments than required :";
        return rd.substr(-1);
    }
    string imm_bin = fnc.to_bin(imm,bin_Len,sign);
    

    string comp_inst = imm_bin + fnc.to_bin(rs1.substr(1,rs1.length()-1),5,false)
                        +inst_data->funct3+  fnc.to_bin(rd.substr(1,rd.length()-1),5,false) +inst_data->Opcode;

    if(bin_Len == 6) comp_inst = inst_data->funct7 + comp_inst;
    
    string hex_inst = fnc.bin_to_hex(comp_inst);

    return hex_inst;
}