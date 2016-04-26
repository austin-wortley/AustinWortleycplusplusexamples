// File name: TrieNode.cpp
// Author: Austin Wortley
// userid: wortlear
// Email: austin.r.wortley@vanderbilt.edu
// Class: CS2201
// Assignment Number: 10
// Honor Statement: I have neither given nor recieved authorized aid on this assignment
// Description: initalize the TrieNode class
// Last Changed:April 19,2016

#include "TrieNode.h"
#include <stdexcept>
#include <iostream>

//base constructor
//takes a char and boolean value and establishes the trienode
//pre:valid char and bool
//post: created TrieNode
TrieNode::TrieNode (char c, bool b): val(c), flag(b){
    for (size_t i=0; i<ALPHABET_SIZE; i++){
        index[i] = nullptr;
    }
    
}

//copy constructor
//pre:takes a valid TrieNode object
//post: creates a TrieNode object identical to the passed one
TrieNode::TrieNode(const TrieNode& rhs): val(rhs.val), flag(rhs.flag){
    for (size_t i=0; i<ALPHABET_SIZE; i++){
        if (rhs.index[i] != nullptr){
            index[i] = new TrieNode(*rhs.index[i]);
        }else{
            index[i] = nullptr;
        }
    }
}


//assignment operator, assigns one TrieNode to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
const TrieNode& TrieNode::operator= (const TrieNode& rhs){
    TrieNode twp(rhs);
    std::swap(flag, twp.flag);
    std::swap(val, twp.val);
    for (int i=0; i<ALPHABET_SIZE; i++){
        std::swap(index[i], twp.index[i]);
    }
    return *this;
}

// Class Destructor
// Destroys a TrieNode
// pre:  Class object exists
// post: Class object does not exist
TrieNode::~TrieNode( ){
    for (int i= 0; i<ALPHABET_SIZE; i++){
        delete index[i];
        index[i] = nullptr;
    }
}

//Insert str starting with the given TrieNode. Create new TrieNodes as
//needed and be sure to set the boolean flag on the last node to true.
//pre: string object exists
//entierty of word is added and the final node is flagged to true
void TrieNode::insert (const string& str){
    if (str.length() == 0){
        flag = true;
    }else{
        int location = str[0] - 'a';
        if (index[location] == nullptr){
            index[location] = new TrieNode(str[0], false);
        }
        string pass = str.substr(1, str.length()-1);
        index[location]->insert(pass);
    }
}

//isword
//pre:string object passed is valid
//post: Returns true if str is in the sub-Trie starting at the given TrieNode
//else returns false
bool TrieNode::isWord (const string& str) const {
    int location = str[0] - 'a';
    if (str.length() ==0 && flag ==true){
        return true;
    }else if (index[location] != nullptr){
            string pass = str.substr(1, str.length()-1);
           return index[location]->isWord(pass);
        
    }else{
        
    return false;
        
    }
}

//isPrefix
//pre: passed string pre exists
//Returns true if pre is a prefix of a word in the sub-Trie starting at the
//given TrieNode, else returns false
bool TrieNode::isPrefix (const string& pre) const{
    int location = pre[0] - 'a';
    if (pre.length() ==0){
        return true;
    }else if (index[location] != nullptr){
        string pass = pre.substr(1, pre.length()-1);
        return index[location]->isPrefix(pass);
    }else{
        
    return false;
        
    }
}

//print
//Prints all words starting at the given TrieNode. The parameter string
//str contains the letters of all ancestors of the given TrieNode
//pre:passed string object is valid
//post:Prints all words starting at the given TrieNode
void TrieNode::print (const string& str) const {
    string word = str;
    if (val != ' '){
        word += val;
    }
    if (flag){
        cout <<word << endl;
    }
    
    for (size_t i=0; i<ALPHABET_SIZE; i++){
        if(index[i] != nullptr){
            index[i]->print(word);
        }
    }
}


//word count
//pre: trie object exists
//post: correct number of nodes in the sub-Trie that end a word
size_t TrieNode::wordCount() const{
    size_t counter=0;
    for (size_t i=0; i<ALPHABET_SIZE; i++){
        if (index[i] != nullptr && index[i]->flag== true){
            counter++;
            
        }
        if (index[i] != nullptr){
            counter+= index[i]->wordCount();
        }
    }
    return counter;
}