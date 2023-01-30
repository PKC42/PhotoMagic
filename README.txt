/**********************************************************************
 *  LFSR - PhotoMagic
 **********************************************************************/
Pratush Kc
2/9/2022


/**********************************************************************
 Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
 This assignment builds upon the previous part (ps1a) which establishes
 a LFSR shifter class which essentially shifts a "seed" or a binary 
 string around. In this assignment, this class is implemented using SFML
 to encrypt and image and later decrypt the encrypted image.

/**********************************************************************
 *  Explain the representation you used for the register bits 
 *  (how it works, and why you selected it)
 **********************************************************************/
 I utlized a vector for the register bits. Since the string is entered
 as if it was a left shift register, I loaded the bits into the vector
 backwards. As a result, the vector, its indices are correct in relation
 to the taps. To print the vector, I overloaded the insertion operator
 to iterate through the vector (backwards) to print in a left shifting
 register format. 

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
I have gotten help from the class's official discord server by reading
discussions between students and the professor. Additionally, I got help
from the provided program (pixels.cpp).

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
To access the member functions in the transform function, I was using
. instead of ->. As a result, the function did not work until I made
the correction. 

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
I encrypted a password with the program (can be found towards the bottom
of the code at main in PhotoMagic.cpp). A transform_ec function was written
particularly for this purpose. It works the same way as the image transform 
function. For it to work, the transform function is a pass by value function
as the seed should not change. Because of this, only a copy of the object is
passed. The name of the password used is ILikePizza22.
