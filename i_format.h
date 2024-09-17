#include<iostream>
#include <string>
#include "InstData.h"
using namespace std;
#ifndef IFORMAT_H
#define IFORMAT_H
class i_format{
    public:
        string get_hex(string &inp, InstData *inst_data);
};
#endif