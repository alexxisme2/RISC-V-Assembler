#include<iostream>
#include <string>
#include "InstData.h"
using namespace std;
#ifndef BFORMAT_H
#define BFORMAT_H
class b_format{
    public:
        string get_hex(string &inp, InstData *inst_data, int line , unordered_map<string,int> label_map);
};
#endif