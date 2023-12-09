#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Word.hpp"

#include <iostream>
#include <string>

using namespace std; 

class LinkedList {
public: 
    //constructor
    LinkedList(); 

    //destructor
    ~LinkedList();

    void addWordinHash(string word, int index); 

    int getToken(string word);

    Word *get_head_word();

private: 
    Word *head_word; 
};

#endif