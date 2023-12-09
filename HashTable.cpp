#include "HashTable.hpp"

#include <iostream>
#include <string>

using namespace std; 

//Contructor 
HashTable::HashTable(int m){
    hash_size = m;
    //creates a new hashtable
    //new_hashtable[hashSize];

    //new_hashtable = new Word[size];

    new_hashtable = new LinkedList*[hash_size];

    for (int i = 0; i < hash_size; i++){
        new_hashtable[i] = new LinkedList;
    }

    //creates a new dictionary 
    new_dictionary = new Dictionary(hash_size);
}

HashTable::~HashTable(){
    for (int i = 0; i < hash_size; i++){
        delete new_hashtable[i];
    }
    delete[] new_hashtable; 
    delete new_dictionary;
}

bool HashTable::insert(string word){
    Word *hash_word; 
    Word *current_word; 

    //if the word is not all alphabetic
    if (!(allAlphabetic(word))){
        return false;
    }

    //if the word is a duplicate
    if (new_dictionary->duplicate(word)){
        return false; 
    }

    //add word into the dictionary 
    new_dictionary->addWord(word);
    int index = new_dictionary->get_index();

    //get the hash key of the word 
    int hash_key = getHashKey(word);

    new_hashtable[hash_key%hash_size]->addWordinHash(word,index);

    return true;
}

bool HashTable::tokenizeFile(fstream& fin){
    string toRead;
    int inserted_num = 0;

    //reading one string at a time seperated by white space
    while (fin >> toRead){
        //if the word only contains alphabetic characters
        if (allAlphabetic(toRead)){
            insert(toRead);
            inserted_num ++;
        }
    }

    //checks if at least one word was inserted into the dictionary 
    if (inserted_num >= 1){
        return true; 
    }
    return false;
}

void HashTable::getToken(string word){
    int hash_key = getHashKey(word);
    int token = new_hashtable[hash_key%hash_size]->getToken(word);

    if (token > 0){
        cout << token << " "; 
    }else{
        cout << "0" << " ";
    }
}

void HashTable::getWord(int token){
    string word = new_dictionary->get_word(token);

    if (word != ""){
        cout << word << " "; 
    }else if (word == ""){
        cout << "UNKNOWN" << " ";
    }
}

void HashTable::printKeys(int k){
    Word *current_word;

    if (new_hashtable[k] == nullptr){
        cout << "chain is empty" << endl;
        return;
    }

    current_word = new_hashtable[k]->get_head_word();

    while (current_word != nullptr){
        cout << getHashKey(current_word->get_word()) << " "; 
        current_word = current_word->get_next();
    }

    cout << endl;
}

bool HashTable::allAlphabetic (string word){
    int ascii_value = 0;

    for (int i = 0; i < word.size(); i++){
        ascii_value = (int)word[i];
        //if the character is not an alphabetic character
        if ( !((ascii_value >= 65 && ascii_value <= 90) || (ascii_value >= 97 && ascii_value <= 122)) ){
            return false;
        }
    }

    return true;
}

int HashTable::getHashKey(string word){
    int hash_key = 0;

    for (int i = 0; i < word.size(); i++){
        hash_key += (int)word[i];
    }

    return hash_key; 

}

