#include <cassert>
#include <string>
#include "stlmp.h"

using namespace stlmp::HashMap;
using std::string;

void test_default_hash_functions(){
    HashMap<string, int> hashmap;

    assert(hashmap.capacity() == 2);
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

void test_resizing(){
    HashMap<int, int> hashmap;
    for(int i=0; i<2000; i++){
        hashmap.insert(i, i);
    }
    for(int i=0; i<2000; i++){
        assert(hashmap.get(i) == i);
    }
    assert(hashmap.size() == 2000);
    assert(hashmap.capacity() == 4096);
}

int main(){
    test_resizing();
    test_default_hash_functions();
}
