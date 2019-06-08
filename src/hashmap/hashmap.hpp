#include "../../include/stlmp.h"
#include <type_traits>
#include <functional>

using namespace stlmp::HashMap;
using std::pair;

template<typename K, typename V>
HashMap<K, V>::HashMap(){
    this->m_capacity = 2;
    this->m_size = 0;
    this->m_table = new pair<K, V>*[m_capacity];
    this->m_should_check = new bool[m_capacity];

    reset_arrays(m_table, m_should_check, m_capacity);
}

template<typename K, typename V>
HashMap<K, V>::HashMap(const HashMap& other){
    copy_data(other);
}

template<typename K, typename V>
const HashMap<K, V>& HashMap<K, V>::operator=(const HashMap<K, V>& other){
    delete_memory();
    copy_data(other);
    return *this;
}

template<typename K, typename V>
HashMap<K, V>::~HashMap(){
    delete_memory();
}

template<typename K, typename V>
void HashMap<K, V>::reset_arrays(pair<K, V> **& table, bool *& should_check, int len){
    for(int i=0; i<len; i++){
        table[i] = nullptr;
        should_check[i] = false;
    }
}

template<typename K, typename V>
int HashMap<K, V>::find_index(const K& key){
    for(int idx = hash_function(key) % m_capacity; m_table[idx] != nullptr || m_should_check[idx]; idx = (idx + 1) % m_capacity){
        if (m_table[idx] == nullptr){
            continue;
        }
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
    int idx = hash_function(key) % m_capacity;
    for(; m_table[idx] != nullptr || (m_table[idx] != nullptr && m_table[idx]->first == key); idx = (idx + 1) % m_capacity);

    //update elem
    if (m_table[idx] != nullptr){
        m_table[idx]->first = key;
        m_table[idx]->second = value;
    }
    //new elem
    else {
        m_table[idx] = new pair<K, V>(key, value);
    }
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
bool HashMap<K, V>::operator==(const HashMap<K, V>& rhs){
    if (m_size != rhs.m_size && m_capacity != rhs.m_capacity){
        return false;
    }
    for(int i=0; i<m_capacity; i++){
        bool this_is_nullptr = m_table[i] == nullptr;
        bool other_is_nullptr = rhs.m_table[i] == nullptr;
        if (this_is_nullptr ^ other_is_nullptr){
            return false;
        }
        if (m_table[i] != nullptr && *m_table[i] != *rhs.m_table[i]){
            return false;
        }
        if (m_should_check[i] != rhs.m_should_check[i]){
            return false;
        }
    }
    return true;
}

template<typename K, typename V>
void HashMap<K, V>::resize_table(){
    int new_capacity = m_capacity * 2;
    pair<K, V> **new_table = new pair<K, V>*[new_capacity];
    delete[] m_should_check;
    m_should_check = new bool[new_capacity];

    reset_arrays(new_table, m_should_check, new_capacity);

    //re-hash everything
    for(int i=0; i<m_capacity; i++){
        if (m_table[i] != nullptr){
            int idx = hash_function(m_table[i]->first) % new_capacity;
            for(; new_table[idx] != nullptr; idx = (idx + 1) % new_capacity);
            new_table[idx] = m_table[i];
            m_should_check[idx] = true;
        }
    }

    delete[] m_table;
    m_table = new_table;
    m_capacity = new_capacity;
}

template<typename K, typename V>
void HashMap<K, V>::delete_memory(){
    for(int i=0; i<m_capacity; i++){
        if (m_table[i]){
            delete m_table[i];
            m_table[i] = nullptr;
        }
    }
    delete[] m_table;
    delete[] m_should_check;
}

template<typename K, typename V>
void HashMap<K, V>::copy_data(const HashMap<K, V>& other){
    this->m_size = other.m_size;
    this->m_capacity = other.m_capacity;
    this->hash_function = other.hash_function;

    this->m_table = new pair<K, V>*[m_capacity];
    this->m_should_check = new bool[m_capacity];

    for(int i=0; i<m_capacity; i++){
        if (other.m_table[i] != nullptr){
            this->m_table[i] = new pair<K, V>(other.m_table[i]->first, other.m_table[i]->second);
        }
        else{
            this->m_table[i] = nullptr;
        }
        this->m_should_check[i] = other.m_should_check[i];
    }
}
