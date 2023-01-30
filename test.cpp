/************************************************************
 *Name: <Pratush Kc>
 *Course name: <COMP.2040>
 *Assignment: <PS1: Linear Feedback Shift Register>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/1/2022>
 *Sources Of Help: <Discussions on Dr. Daly's discord server from other students and Dr. Daly>
 Note: Part of the class defintion is taken from the assignment "PS1: Linear Feedback Shift Register (part A)" by Dr. Rykalova
************************************************************/
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Test

#include <boost/test/unit_test.hpp>
#include "FibLFSR.hpp"

/*
    This test case (Step_Check) checks if the step function
    is properly shifting each bit. Since the seed is 16 bits
    long, the taps will be at the farthest left index 
    (15 in this case) along with taps at indices 13, 12 and 10
    as the seed is large enough to have them in range.
*/
BOOST_AUTO_TEST_CASE(Step_Check){
    FibLFSR test("1011011000110110");

    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 0);

}

/*
    This test (Generate_Check) confirms that 
    the generate function works. The values 
    below are given in the assignment. If the
    function is working properly, all of these 
    tests should pass
*/
BOOST_AUTO_TEST_CASE(Generate_Check){
    FibLFSR test("1011011000110110");

    BOOST_CHECK_EQUAL(test.generate(5), 3);
    BOOST_CHECK_EQUAL(test.generate(5), 6);
    BOOST_CHECK_EQUAL(test.generate(5), 14);
    BOOST_CHECK_EQUAL(test.generate(5), 24);
    BOOST_CHECK_EQUAL(test.generate(5), 1);
    BOOST_CHECK_EQUAL(test.generate(5), 13);
    BOOST_CHECK_EQUAL(test.generate(5), 28);
}

/*
    Tests step function with a seed of size 14. 
    Since the seed is size 14, there will be 
    no tap at 13 as end tap will be at index 13.
    As a result, due to the size, one tap should
    be eliminated and there will be one less index
    to xor. If these cases (predtermined by
    hand) pass, the step function is correct at
    this size. 
*/
BOOST_AUTO_TEST_CASE(Seed_Size_14){
    FibLFSR test("10110110001101");

    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 1);

}

/*
    This test is similar to the previous test. 
    Since the end tap will be at 12, there will
    be less taps to xor as 13 will be out of
    range. This test checks that the step
    function is still working with less tap. 
*/
BOOST_AUTO_TEST_CASE(Seed_Size_12){
    FibLFSR test("101101100011");

    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 1);
}

/*
    This test determines whether step 
    works with seeds smaller than 11 bits.
    Since the tap at 10 is out of range, 
    the end tap will be be xored with 
    the bit that comes before it. This will
    work as long as the seed size is 2 or
    above. 
*/
BOOST_AUTO_TEST_CASE(Seed_Size_8){
    FibLFSR test("10110110");

    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 1);
    BOOST_CHECK_EQUAL(test.step(), 0);
    BOOST_CHECK_EQUAL(test.step(), 1);
}