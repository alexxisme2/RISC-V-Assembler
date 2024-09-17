#include<iostream>
#include <string>
#include "InstData.h"
using namespace std;
#ifndef JFORMAT_H
#define JFORMAT_H
class j_format{
    public:
        string get_hex(string &inp, InstData *inst_data, int line , unordered_map<string,int> label_map);
};
#endif