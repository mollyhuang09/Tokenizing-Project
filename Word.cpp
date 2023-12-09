#include "Word.hpp" 

#include <iostream> 
#include <string>

Word::Word(string word, int index){
    current_word = word; 
    current_index = index; 
    next_word = nullptr; 
}

Word::~Word(){
    current_word = "";
    current_index = -1;
    next_word = nullptr;
}

string Word::get_word(){ 
    return current_word; }

int Word::get_index(){ 

    return current_index; 
}

Word *Word::get_next() { return next_word; }

void Word::set_next(Word *new_next_child){
    next_word = new_next_child; 
}