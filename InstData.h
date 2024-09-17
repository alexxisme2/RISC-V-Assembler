#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
#ifndef INSTDATA_H
#define INSTDATA_H
class InstData{
    public :
        string Opcode;
        string funct3;
        string funct7;
    public: 
        InstData(string a, string b , string c);
        InstData();
        void getInstData(unordered_map<string,InstData*> &inst_table);
        string getInst(string &s);
};
#endif