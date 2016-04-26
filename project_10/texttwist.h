// File name: texttwist.h
// Author: Austin Wortley
// userid: wortlear
// Email: austin.r.wortley@vanderbilt.edu
// Class: CS2201
// Assignment Number: 10
// Honor Statement: I have neither given nor recieved authorized aid on this assignment
// Description: Initialized texttwist class
// Last Changed:April 25, 2016

#ifndef texttwist_h
#define texttwist_h
#include "Trie.h"

class texttwist{
    
private:
    //dictionary to import
    Trie lexicon;
    
    //good words from dicitonary
    Trie found;
    
    //words that have already been checked
    Trie used;
    
public:
    
    //default constructor, loads in the files.
    //pre: class exists
    //post: empty private found and used, lexicon loaded
    texttwist();
    
    
    //solver function takes input & does recursive
    //backtracking to find all valid permutations of text jumble and adds them to Trie
    //pre: valid prefix and input
    //post: all the valid options are stored in found
    void solver(string prefix, string input);
    
    
    //prints out found
    //pre: valid found trie
    //post: found is printed out
    void print() const;
    
    //user input
    //prompts the user for a 7 letter length string, if not 7 length or not all chars repromts
    //post: returns a 7 letter length string
    string user_input();
    
    
};

#endif /* texttwist_h */
