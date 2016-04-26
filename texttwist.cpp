// File name: texttwist.cpp
// Author: Austin Wortley
// userid: wortlear
// Email: austin.r.wortley@vanderbilt.edu
// Class: CS2201
// Assignment Number: 10
// Honor Statement: I have neither given nor recieved authorized aid on this assignment
// Description: Implements texttwist.cpp
// Last Changed:April 25, 2016

#include <iostream>
#include "texttwist.h"

const int MIN_SIZE = 3;

//default constructor, loads in the files.
//pre: class exists
//post: empty private found and used, lexicon loaded
texttwist::texttwist(){
    lexicon.loadFromFile("ospd.txt");
}

//solver function takes input & does recursive
//backtracking to find all valid permutations of text jumble and adds them to Trie
//pre: valid prefix and input
//post: all the valid options are stored in found
void texttwist:: solver(string prefix, string input){
    for(size_t i=0; i<input.length(); i++){
        string temp = prefix + input[i];
        if(lexicon.isPrefix(temp) && !used.isWord(temp)){
            if(temp.length() >= MIN_SIZE && lexicon.isWord(temp)){
                found.insert(temp);
            }
            string remain = input;
            remain = remain.erase(i,1);
            solver(temp, remain);
        }
        used.insert(temp);
    }
}


//prints out found
//pre: valid found trie
//post: found is printed out
void texttwist::print() const{
    found.print();
}

//user input
//prompts the user for a 7 letter length string, if not 7 length or not all chars repromts
//post: returns a 7 letter length string
string texttwist::user_input(){
    cout <<"Please input 7 letters of texttwist game: ";
    string input = "";
    getline(cin, input);
    if (input.length() != 7){
        cout << "Number of characters invalid, please try again"<< endl;
        return user_input();
    }
    for (size_t i = 0; i<7; i++){
        if (!isalpha(input[i])){
            cout << "Not valid character, please try again" <<endl;
            return user_input();
        }
        input[i] = tolower(input[i]);
    }
    return input;
    
}