#include "LinkedList.hpp"

#include <iostream>
#include <string>

using namespace std; 

LinkedList::LinkedList(){
    head_word = 0; 
}

LinkedList::~LinkedList(){
    Word *current_word = head_word;

    while (head_word != nullptr){
        head_word = head_word->get_next();
        delete current_word;
        current_word = nullptr;
        current_word = head_word;
    }
}
 
void LinkedList::addWordinHash(string word, int index){
    Word *current_word; 
    Word *new_word = new Word(word,index);

    if (head_word == nullptr){
        head_word = new_word; 
    }else{
        current_word = head_word; 

        while (current_word->get_next() != nullptr){
            current_word = current_word->get_next();
        }

        current_word->set_next(new_word);
    }
}

int LinkedList::getToken(string word){
    Word *current_word = head_word;

    while (current_word != nullptr){
        if (current_word->get_word() == word){
            return current_word->get_index();
        }else{
            current_word = current_word->get_next();
        }
    }

    return 0;
}

Word *LinkedList::get_head_word(){ return head_word; }