/************************************************************
 *Name: <Pratush Kc>
 *Course name: <COMP.2040>
 *Assignment: <PS1b: LFSR - PhotoMagic>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/9/2022>
 *Sources Of Help: <Discussions on Dr. Daly's discord server from other students and Dr. Daly>
 Note: Part of the class defintion is taken from the assignment "PS1a: Linear Feedback Shift Register (part A)" by Dr. Rykalova
 Additionally, some code was taken from PS1b: LFSR - PhotoMagic.
************************************************************/

#include "FibLFSR.hpp"
#include <iostream>
#include <string>
#include <sstream>

/*
Initialize the sequence with the given seed
To keep consistency with shifting and indices, 
the seed should be loaded into the vector backwards. 
*/
FibLFSR::FibLFSR(std::string seed){
    
    for(int i = (int)seed.size() - 1; i >= 0; i--){
        sequence.push_back(seed[i] - '0');
    }
    
}

/*
Used for deallocating any memory
*/
FibLFSR::~FibLFSR(){
    sequence.clear();
}

/*
Shift all bits to the left (or to the side containing the most significant bit).
The tapped positions are: 13, 12 and 10
*/
int FibLFSR:: step(){    
    int new_bit; 
    int size = (int)sequence.size(); 

    if(sequence.size()-1 > 13){
        new_bit = sequence[sequence.size()- 1] ^ sequence[13] ^ sequence[12] ^ sequence[10];
    }

    if(sequence.size()-1 <= 13 && sequence.size()-1 > 12){
        new_bit = sequence[sequence.size()- 1] ^ sequence[12] ^ sequence[10]; 
    }

    if(sequence.size()-1 <= 12 && sequence.size()-1 > 10){
        new_bit = sequence[sequence.size()- 1]  ^ sequence[10];
    }

    if(sequence.size()-1 <= 10){
        new_bit = sequence[sequence.size()- 1] ^  sequence[sequence.size()-2];  //moving index in case sequence is too small 
    }

    for(int i = size - 1; i >= 1; i--){
        sequence[i] = sequence[i-1];
    }

    sequence[0] = new_bit; 

    return new_bit;
}

/*
Cycles through k steps and returns k-bit integer
*/
int FibLFSR:: generate(int k){  
    int sum = 0; 
    for(int i = 0; i < k; i++){
        sum = (sum*2)+step(); 
    }
    return sum; 
}


/*
Print out the register as a string using the insertion operator
Since the string in reality should be a "left" shift operator 
(int this setup, we have it in right configuration to match with
the vector indices), the vector should printed backwards
*/
std::ostream& operator <<(std::ostream& out, FibLFSR& obj){


    for(int i = obj.sequence.size() - 1; i >= 0 ; i--){
        out << obj.sequence.at(i);
    } 

    return out; 
}