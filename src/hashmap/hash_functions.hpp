#include "../../include/stlmp.h"

using namespace stlmp::HashMap;
typedef unsigned long long u_ll;

u_ll djb2(const std::string& input){
    u_ll rv = 5831;
    for(char c : input){
        rv = ((rv << 5) + rv) + c;
    }
    return rv;
}

u_ll sbdm(const std::string& input){
    u_ll rv = 0;
    for(char c : input){
        rv = c + (rv << 6) + (rv << 16) - rv;
    }
    return rv;
}
