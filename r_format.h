#include<iostream>
#include <string>
#include "InstData.h"
using namespace std;
#ifndef RFORMAT_H
#define RFORMAT_H
class r_format{
    public:
        string get_hex(string &inp, InstData *inst_data);
};
#endif