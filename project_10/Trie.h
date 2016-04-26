// File name: Trie.h
// Author: Austin Wortley
// userid: wortlear
// Email: austin.r.wortley@vanderbilt.edu
// Class: CS2201
// Assignment Number: 10
// Honor Statement: I have neither given nor recieved authorized aid on this assignment
// Description: Declares all the functions and variable of Trie class
// Last Changed:April 19, 2016

#ifndef Trie_h
#define Trie_h

#include "TrieNode.h"



class Trie{
    
private:
    typedef TrieNode* TrieNodePtr;
    
    TrieNode root;
    
    
public:
    
    
    // The default constructor
    Trie( );
    
    
    //insert
    //Insert word into the Trie
    //pre: trie object exists and passed string is valid
    //post: word is inserted into trie
    void insert (const string& word);
    
    //loadFromFile
    //Insert all words in the specified file into the Trie. Throws a
    //std::invalid_argument exception if the specified file cannot be opened.
    //pre: trie object exists and passed string is valid
    //post: file is loaded
    void loadFromFile (const string& filename);
    
    //isWord
    //pre: trie object exists and passed string is valid
    //post:Returns true if word is in the Trie, else returns false
    bool isWord (const string& word) const ;
    
    //isprefix
    //pre: trie object exists and passed string is valid
    //post:Returns true if pre is a prefix of a word in the Trie, else returns false
    bool isPrefix (const string& pre) const ;
    
    //print
    //Print all words in the Trie, one per line. Print in alphabetical order.
    //pre: Trie object exists
    //post: all words in trie printed out in alphabetical order
    void print ( ) const;
    
    //wordCount
    //Count all the words in the Trie
    //pre: Trie object exists
    //post: returns the number of all wors in the trie
    size_t wordCount ( ) const ;
    
};

#endif /* Trie_h */
