// File name: TrieNode.h
// Author: Austin Wortley
// userid: wortlear
// Email: austin.r.wortley@vanderbilt.edu
// Class: CS2201
// Assignment Number: 10
// Honor Statement: I have neither given nor recieved authorized aid on this assignment
// Description:Declares all functions and variables of TriNode class
// Last Changed:April 19, 2016

#ifndef TrieNode_h
#define TrieNode_h

using namespace std;
#include <string>

const int ALPHABET_SIZE= 26;



class TrieNode{
    
private:
    //character value to store
    char val;
    
    //boolean store
    bool flag;
    
    //array of values
    TrieNode* index[ALPHABET_SIZE];
    
 typedef TrieNode* TrieNodePtr;
    
    
public:
    
    
    //base constructor
    //takes a char and boolean value and establishes the trienode
    //pre:valid char and bool
    //post: created TrieNode
    TrieNode (char c, bool b);
    
    //copy constructor
    //pre:takes a valid TrieNode object
    //post: creates a TrieNode object identical to the passed one
    TrieNode(const TrieNode& rhs);
    
    //assignment operator, assigns one TrieNode to another
    // pre: both class objects exist
    // post: this class object gets assigned a copy of the parameter class object
    const TrieNode& operator= (const TrieNode& rhs) ;
    
    // Class Destructor
    // Destroys a TrieNode
    // pre:  Class object exists
    // post: Class object does not exist
    ~TrieNode( ) ;
    
    //Insert str starting with the given TrieNode. Create new TrieNodes as
    //needed and be sure to set the boolean flag on the last node to true.
    //pre: string object exists
    //entierty of word is added and the final node is flagged to true
    void insert (const string& str);
    
    //isword
    //pre:string object passed is valid
    //post: Returns true if str is in the sub-Trie starting at the given TrieNode
    //else returns false
    bool isWord (const string& str) const ;
    
    //isPrefix
    //pre: passed string pre exists
    //Returns true if pre is a prefix of a word in the sub-Trie starting at the
    //given TrieNode, else returns false
    bool isPrefix (const string& pre) const;
    
    //print
    //Prints all words starting at the given TrieNode. The parameter string
    //str contains the letters of all ancestors of the given TrieNode
    //pre:passed string object is valid
    //post: correct number of nodes int he sub-Trie that end a word
    void print (const string& str) const ;
    
    //word count
    //pre: trie object exists
    //post: correct number of nodes in the sub-Trie that end a word
    size_t wordCount ( ) const;
    
};

#endif /* TrieNode_h */
