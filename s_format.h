#include<iostream>
#include <string>
#include "InstData.h"
using namespace std;
#ifndef SFORMAT_H
#define SFORMAT_H
class s_format{
    public:
        string get_hex(string &inp, InstData *inst_data);
};
#endif