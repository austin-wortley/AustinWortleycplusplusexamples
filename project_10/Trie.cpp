// File name: Trie.cpp
// Author: Austin Wortley
// userid: wortlear
// Email: austin.r.wortley@vanderbilt.edu
// Class: CS2201
// Assignment Number: 10
// Honor Statement: I have neither given nor recieved authorized aid on this assignment
// Description: Initializes all the functions of Trie class
// Last Changed:April 19, 2016

#include "Trie.h"
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>

//default constructor
Trie::Trie(): root(' ', false){
    //nothing to do
}

//insert
//Insert word into the Trie
//pre: trie object exists and passed string is valid
//post: word is inserted into trie
void Trie::insert (const string& word){
    root.insert(word);
}


//loadFromFile
//Insert all words in the specified file into the Trie. Throws a
//std::invalid_argument exception if the specified file cannot be opened.
//pre: trie object exists and passed string is valid
//post: file is loaded
void Trie::loadFromFile (const string& filename){
    string str;
    
    ifstream file(filename.c_str());
    // Do error checking here
    if (!file) {
        throw std::invalid_argument("invalid file");
    }
    
    string input;
    while (file >> input){
        insert(input);
    }
    
    file.close();
    
}

//isWord
//pre: trie object exists and passed string is valid
//post:Returns true if word is in the Trie, else returns false
bool Trie::isWord (const string& word) const {
    return root.isWord(word);
}

//isprefix
//pre: trie object exists and passed string is valid
//post:Returns true if pre is a prefix of a word in the Trie, else returns false
bool Trie::isPrefix (const string& pre) const {
    return root.isPrefix(pre);
}

//print
//Print all words in the Trie, one per line. Print in alphabetical order.
//pre: Trie object exists
//post: all words in trie printed out in alphabetical order
void Trie::print ( ) const{
    root.print("");
}

//wordCount
//Count all the words in the Trie
//pre: Trie object exists
//post: returns the number of all wors in the trie
size_t Trie::wordCount ( ) const {
    return root.wordCount();
}