#include "../../include/stlmp.h"

using namespace stlmp::HashMap;
using std::pair;

typedef unsigned long long u_ll;

template<typename K, typename V>
HashMap<K, V>::HashMap(int capacity, u_ll (*hash_function)(K, int), u_ll (*secondary_hash)(K, int)){
    this->table = new pair<K, V>[capacity];

    this->should_check = new bool[capacity];

    this->capcity = capacity;
    this->size = 0;
    this->primary_hash= hash_function;
    this->secondary_hash = secondary_hash;

    reset_arrays();
}

template<typename K, typename V>
void HashMap<K, V>::reset_arrays(){
    for(int i=0; i<size; i++){
        table[i] = nullptr;
        should_check[i] = false;
    }
}

template<typename K, typename V>
int HashMap<K, V>::find_index(const K& key){
    int inc = 1;
    //Use double hashing if we can
    if (secondary_hash != nullptr){
        inc = secondary_hash(key, size);
    }

    for(int idx = primary_hash(key, size); table[idx] != nullptr && should_check[idx]; idx = (idx + inc) % size){
        if (table[idx]->first == key){
            return idx;
        }
    }
    return -1;
}

template<typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value){
    size++;
    if (size >= 0.7 * capacity){
        resize_table();
    }

    int idx = primary_hash(key, size);
    int inc = 1;
    if (secondary_hash != nullptr){
        inc = secondary_hash(key, size);
    }
    for(; table[idx] != nullptr; idx = (idx + inc) % size);

    table[idx] = new std::pair<K, V>(key, value);
    should_check[idx] = true;
}

template<typename K, typename V>
V HashMap<K, V>::get(const K& key){
    int index = find_index(key);
    return index == -1 ? V() : table[index]->second;
}

template<typename K, typename V>
V HashMap<K, V>::remove(const K& key){
    int index = find_index(key);
    V rv = table[index]->second;

    if (index != -1){
        size--;
        delete table[index];
        table[index] = nullptr;
        should_check[index] = false;
    }
    return rv;
}
