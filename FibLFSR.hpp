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
#pragma once

#ifndef FIBLFSR_HPP
#define FIBLFSR_HPP

#include <iostream>
#include <string>
#include <vector>

class FibLFSR{
    public: 
    FibLFSR(std::string seed);                                          /*Construct object with a given seed (convert to vector)*/ 
    ~FibLFSR();                                                         /*Destroy object*/    

    int step();                                                         /*shift bits and xor taps to get a new sequence*/
    int generate(int k);                    

    friend std::ostream& operator <<(std::ostream& out, FibLFSR &obj);  /*insertion operator for printing out bits*/

    private: 
    std::vector<int>sequence;                                           /*vector containing bits*/
};

#endif