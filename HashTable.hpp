#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP 

#include "Dictionary.hpp"
#include "LinkedList.hpp" 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class HashTable {
public: 
    //Constructor
    HashTable(int m);

    //Detructor
    ~HashTable();

    int getHashKey (string word);

    bool insert(string word);

    bool tokenizeFile (fstream& fin);

    void getToken(string word);

    void getWord(int token);

    void printKeys(int k);

    bool allAlphabetic (string word);

private: 
    int hash_size; 
    Dictionary *new_dictionary; 
    LinkedList **new_hashtable;
};

#endif