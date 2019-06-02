#include "stlmp.h"

using namespace stlmp::HashMap;
using std::pair;

template<typename K, typename V>
HashMap<K, V>::HashMap(int capacity, int (*hash_function)(K)){
    this->table = new pair<K, V>[capacity];

    this->should_check = new bool[capacity];

    this->size = capacity;
    this->hash_function = hash_function;

    reset_arrays();
}

template<typename K, typename V>
void HashMap<K, V>::reset_arrays(){
    for(int i=0; i<size; i++){
        if (table[i] != nullptr){
            delete table[i];
        }
        table[i] = nullptr;

        should_check[i] = false;
    }
}
