// File name: texttwistdriver.cpp
// Author: Austin Wortley
// userid: wortlear
// Email: austin.r.wortley@vanderbilt.edu
// Class: CS2201
// Assignment Number: 10
// Honor Statement: I have neither given nor recieved authorized aid on this assignment
// Description: runs text twist
// Last Changed:April 25, 2016


#include "texttwist.h"



int main() {
    
    
    //makes a texttwist
    texttwist texttwist_output;
    
    //acquires the user string
    string input = texttwist_output.user_input();
    
    //initiates the solver
    texttwist_output.solver("", input);
    
    //prints the solutions
    texttwist_output.print();

    return 0;
};






