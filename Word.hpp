#ifndef WORD_HPP
#define WORD_HPP

#include <iostream>
#include <string>

using namespace std;

class Word {
public: 
    //Constructor 
    Word(string word, int index);

    //Destructor
    ~Word();

    string get_word();

    int get_index();

    Word *get_next();

    void set_next ( Word *new_next_word );

private: 
    string current_word; 
    int current_index; 
    Word *next_word; 
};

#endif