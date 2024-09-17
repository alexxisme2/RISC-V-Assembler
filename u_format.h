#include<iostream>
#include <string>
#include "InstData.h"
using namespace std;
#ifndef UFORMAT_H
#define UFORMAT_H
class u_format{
    public:
        string get_hex(string &inp, InstData *inst_data);
};
#endif