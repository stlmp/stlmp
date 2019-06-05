#include "../../include/stlmp.h"

using namespace stlmp::HashMap;
using std::pair;

template<typename K, typename V>
HashMap<K, V>::HashMap(int capacity, unsigned (*hash_function)(const K&, int), unsigned (*secondary_hash)(const K&, int)){
    this->m_table = new pair<K, V>*[capacity];

    this->m_should_check = new bool[capacity];

    this->m_capacity = capacity;
    this->m_size = 0;
    this->primary_hash= hash_function;
    this->secondary_hash = secondary_hash;

    reset_arrays();
}

template<typename K, typename V>
HashMap<K, V>::~HashMap(){

}

template<typename K, typename V>
void HashMap<K, V>::reset_arrays(){
    for(int i=0; i<m_size; i++){
        m_table[i] = nullptr;
        m_should_check[i] = false;
    }
}

template<typename K, typename V>
int HashMap<K, V>::find_index(const K& key){
    int inc = 1;
    //Use double hashing if we can
    if (secondary_hash != nullptr){
        inc = secondary_hash(key, m_capacity);
    }

    for(int idx = primary_hash(key, m_capacity); m_table[idx] != nullptr && m_should_check[idx]; idx = (idx + inc) % m_capacity){
        if (m_table[idx]->first == key){
            return idx;
        }
    }
    return -1;
}

template<typename K, typename V>
void HashMap<K, V>::insert(const K& key, const V& value){
    m_size++;
    if (m_size >= 0.7 * m_capacity){
        resize_table();
    }

    int idx = primary_hash(key, m_capacity);
    int inc = 1;
    if (secondary_hash != nullptr){
        inc = secondary_hash(key, m_capacity);
    }
    for(; m_table[idx] != nullptr; idx = (idx + inc) % m_capacity);

    m_table[idx] = new std::pair<K, V>(key, value);
    m_should_check[idx] = true;
}

template<typename K, typename V>
V HashMap<K, V>::get(const K& key){
    int index = find_index(key);
    return index == -1 ? V() : m_table[index]->second;
}

template<typename K, typename V>
V HashMap<K, V>::remove(const K& key){
    int index = find_index(key);
    V rv = m_table[index]->second;

    if (index != -1){
        m_size--;
        delete m_table[index];
        m_table[index] = nullptr;
        m_should_check[index] = false;
    }
    return rv;
}

template<typename K, typename V>
int HashMap<K, V>::size(){
    return m_size;
}

template<typename K, typename V>
int HashMap<K, V>::capacity(){
    return m_capacity;
}

template<typename K, typename V>
void HashMap<K, V>::resize_table(){

}
