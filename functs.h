#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
#ifndef FUNCTS_H
#define FUNCTS_H
class functs{
    
    public: 
        string bin_to_hex(string bin);
        string to_bin(string num, int len, bool sign);
        void ini_alia(unordered_map<string,string> &alias);
        string get_reg(string &inp);
        string get_imm(string &inp);
        int store_labels(string inp, unordered_map<string,int>&map,unordered_map<int,string>&rev_map, int counter);
        string get_label(string &inp);
};
#endif