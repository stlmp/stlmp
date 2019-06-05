#include <cassert>
#include <string>
#include "stlmp.h"

using namespace stlmp::HashMap;
using std::string;

unsigned int djb2(const std::string& input, int len){
    unsigned int rv = 5831;
    for(char c : input){
        rv = ((rv << 5) + rv) + c;
    }
    return rv % len;
}

unsigned int sbdm(const std::string& input, int len){
    unsigned int rv = 0;
    for(char c : input){
        rv = c + (rv << 6) + (rv << 16) - rv;
    }
    return rv % len;
}

void test_custom_hash_functions(){
    //Arguments: initial_capacity, primary hash function, secondary hash function (for double hashing).
    HashMap<string, int> hashmap(10, djb2, sbdm);

    assert(hashmap.capacity() == 10);
    assert(hashmap.size() == 0);

    hashmap.insert("Hello", 1);
    hashmap.insert("World", 2);
    hashmap.insert("!", 3);

    assert(hashmap.size() == 3);

    assert(hashmap.get("Hello") == 1);
    assert(hashmap.get("World") == 2);
    assert(hashmap.get("!") == 3);
    assert(hashmap.size() == 3);

    assert(hashmap.remove("Hello") == 1);
    assert(hashmap.remove("World") == 2);
    assert(hashmap.remove("!") == 3);
    assert(hashmap.size() == 0);
}

int main(){
    test_custom_hash_functions();
}
