#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Dictionary {
public: 
    Dictionary(int m);

    ~Dictionary();

    void addWord(string word);

    bool duplicate (string word);

    int get_index();

    string get_word(int token);

private: 
    int size; 
    int capacity; 
    string *dictionaryArray;
};

#endif