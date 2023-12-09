#include "HashTable.hpp"
#include "Dictionary.hpp"
#include "Word.hpp"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    HashTable *new_hashtable; 
    string command; 

    while (cin >> command){
        if (command == "M"){
            int m; 
            cin >> m;
            new_hashtable = new HashTable(m);
            cout << "success" << endl;
        }

        else if (command == "INSERT"){
            string word; 
            cin >> word; 
            if (new_hashtable->insert(word)){
                cout << "success" << endl; 
            }else{
                cout << "failure" << endl;
            }
        }

        else if (command == "READ"){
            string filename; 
            cin >> filename; 
            fstream fin(filename.c_str());
            if (new_hashtable->tokenizeFile(fin)){
                cout << "success" << endl; 
            }else{
                cout << "failure" << endl; 
            }
        }

        else if (command == "TOKENIZE"){
            string word; 
            cin >> word; 
            new_hashtable->getToken(word);
            cout << endl;
        }

        else if (command == "RETRIEVE"){
            int token; 
            cin >> token;
            new_hashtable->getWord(token);
            cout << endl;
        }

        else if (command == "STOK"){
            string word; 
            while (cin >> word && word != "_DONE_"){
                new_hashtable->getToken(word);
            }
            cout << endl;
        }

        else if (command == "TOKS"){
            int token; 
            while (cin >> token && token != -1){
                new_hashtable->getWord(token);
            }
            cout << endl;
        }

        else if (command == "PRINT"){
            int k;
            cin >> k;
            new_hashtable->printKeys(k);
        }

        else if (command == "EXIT"){
            delete new_hashtable;
        }
    }

    return 0;

}