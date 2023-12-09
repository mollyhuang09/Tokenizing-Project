#include "HashTable.hpp"

#include <iostream>
#include <string>

using namespace std;

Dictionary::Dictionary(int m){
    capacity = m; 
    size = 0;
    dictionaryArray = new string[capacity];
}

Dictionary::~Dictionary(){
    delete[] dictionaryArray;
}

void Dictionary::addWord(string word){
    dictionaryArray[size] = word; 

    size ++; 

    if (size >= capacity) {
        capacity += 50; 
        string* temp = new string[capacity];

        for (int i = 0; i < size; i++){
            temp[i] = dictionaryArray[i];
        }

        delete [] dictionaryArray;
        dictionaryArray = temp; 
    }
}

bool Dictionary::duplicate(string word){
    for (int i = 0; i < size; i++){
        //duplicate word
        if (word == dictionaryArray[i]){
            return true;
        }
    }

    return false; 

}

int Dictionary::get_index() { return size; }

string Dictionary::get_word(int token) { 
    if (token <= size){
        return dictionaryArray[token-1];
    }else{
        return "";
    }
}