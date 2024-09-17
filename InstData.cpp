#include<iostream>
#include<string>
#include<unordered_map>
#include "InstData.h"
using namespace std;

//New class which stores opcode, funct3 and funct7 and its constructor
InstData::InstData(string a, string b , string c){
        this->Opcode = a;
        this->funct3 = b;
        this->funct7 = c;
    }
    
InstData:: InstData()
    {
        this->Opcode = "0000000";
        this->funct3 = "000";
        this->funct7 = "0000000";
    }
//stores the InstData for the corresponding instructions in the unordered_map inst_table
void InstData::getInstData(unordered_map<string,InstData*> &inst_table)
{
    InstData *temp;
    //R Format
    temp = new InstData("0110011", "000", "0000000");
    inst_table["add"]  = temp; 
    temp = new InstData("0110011", "000", "0100000");
    inst_table["sub"]  = temp; 
    temp = new InstData("0110011", "100", "0000000");
    inst_table["xor"]  = temp; 
    temp = new InstData("0110011", "110", "0000000");
    inst_table["or"]   = temp; 
    temp = new InstData("0110011", "111", "0000000");
    inst_table["and"]  = temp; 
    temp = new InstData("0110011", "001", "0000000");
    inst_table["sll"]  = temp; 
    temp = new InstData("0110011", "101", "0000000");
    inst_table["srl"]  = temp; 
    temp = new InstData("0110011", "101", "0100000");
    inst_table["sra"]  = temp; 
    temp = new InstData("0110011", "010", "0000000");
    inst_table["slt"]  = temp; 
    temp = new InstData("0110011", "011", "0000000");
    inst_table["sltu"] = temp; 
    //I Format
    temp = new InstData("0010011", "000", "");
    inst_table["addi"] = temp; 
    temp = new InstData("0010011", "100", "");
    inst_table["xori"] = temp; 
    temp = new InstData("0010011", "110", "");
    inst_table["ori"] = temp;
    temp = new InstData("0010011", "111", "");
    inst_table["andi"] = temp; 
    temp = new InstData("0010011", "001", "000000");
    inst_table["slli"] = temp; 
    temp = new InstData("0010011", "101", "000000");
    inst_table["srli"] = temp; 
    temp = new InstData("0010011", "101", "010000");
    inst_table["srai"] = temp; 
    temp = new InstData("0010011", "010", "");
    inst_table["slti"] = temp; 
    temp = new InstData("0010011", "011", "");
    inst_table["sltiu"] = temp;  
    // I Format Load
    temp = new InstData("0000011", "000", "");
    inst_table["lb"] = temp;
    temp = new InstData("0000011", "001", "");
    inst_table["lh"] = temp;
    temp = new InstData("0000011", "010", "");
    inst_table["lw"] = temp;
    temp = new InstData("0000011", "011", "");
    inst_table["ld"] = temp;
    temp = new InstData("0000011", "100", "");
    inst_table["lbu"] = temp;
    temp = new InstData("0000011", "101", "");
    inst_table["lhu"] = temp;
    temp = new InstData("0000011", "110", "");
    inst_table["lwu"] = temp; 
    //S Format
    temp = new InstData("0100011", "000", "");
    inst_table["sb"] = temp; 
    temp = new InstData("0100011", "001", "");
    inst_table["sh"] = temp; 
    temp = new InstData("0100011", "010", "");
    inst_table["sw"] = temp; 
    temp = new InstData("0100011", "011", "");
    inst_table["sd"] = temp; 
    //B Format
    temp = new InstData("1100011", "000", "");
    inst_table["beq"] = temp;
    temp = new InstData("1100011", "001", "");
    inst_table["bne"] = temp;
    temp = new InstData("1100011", "100", "");
    inst_table["blt"] = temp;
    temp = new InstData("1100011", "101", "");
    inst_table["bge"] = temp;
    temp = new InstData("1100011", "110", "");
    inst_table["bltu"] = temp;
    temp = new InstData("1100011", "111", "");
    inst_table["bgeu"] = temp;
    //Jal , Jalr
    temp = new InstData("1101111", "", "");
    inst_table["jal"] = temp;
    temp = new InstData("1100111", "000", "");
    inst_table["jalr"] = temp;
    //U format
    temp = new InstData("0110111", "", "");
    inst_table["lui"] = temp;
    temp = new InstData("0010111", "", "");
    inst_table["auipc"] = temp;
}
//Iterates through input string and returns the instruction string
string InstData::getInst(string &s)
{
    string str = "";
    int i  = 0;
    while(s[i] != ' ')
    {
        str += s[i];
        i++;
    }
     s= s.substr(i+1,s.length()-i);
    return str;
}