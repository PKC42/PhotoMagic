/************************************************************
 *Name: <Pratush Kc>
 *Course name: <COMP.2040>
 *Assignment: <PS1b: LFSR - PhotoMagic>
 *Instructor's name: <Dr. James Daly>
 *Date: <2/9/2022>
 *Sources Of Help: <Discussions on Dr. Daly's discord server from other students and Dr. Daly>
 Note: Part of the class defintion is taken from the assignment "PS1a: Linear Feedback Shift Register (part A)" by Dr. Rykalova
 Additionally, some code was taken from PS1b: LFSR - PhotoMagic.
 Seed:  1011011000110110
************************************************************/
#include <iostream>
#include <string.h>
#include "FibLFSR.hpp"

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//Common terms defined here to make main a bit cleaner
using std::string; 
using std::cin; 
using std::cout;
using std::endl;

using sf::Color;
using sf::Vector2u;
using sf::Event;
using sf::Sprite;
using sf::Texture;
using sf::Image;
using sf::VideoMode;
using sf::RenderWindow; 


/*
Transform takes an Image class term from the sfml
library and an FibLFSR object pointer as parameters.
This function will cause shifts in the seed located 
in the FibLFSR object and change the colors of each 
pixel of the image one by one. 
Note: k has been set to 20 for generate. The tap
locations can be found in FibLFSR.hpp
*/
void transform(Image& image, FibLFSR* shifter){
    int x = 0, y = 0; 
    Vector2u size = image.getSize();                // get size of pixel 
    Color pixel;                                    // variable for color manipulation
    
    for(x = 0; x < (signed)size.x; x++){            // iterate through pixels in x direction
        for(y = 0; y < (signed)size.y; y++){        // iteratie through pixels in y directions
            pixel = image.getPixel(x,y);            // assign pixel to particular pixel and shift color below
            pixel.r ^= shifter->generate(20);
            pixel.g ^= shifter->generate(20); 
            pixel.b ^= shifter->generate(20);        
            image.setPixel(x, y, pixel);            // change the pixel
        }
    }

}

void transform_words(string& message, FibLFSR obj){
    for(int i = 0; i < (int)message.size() - 1; i++){
        message[i] = (message[i]) ^ obj.generate(5);
    }

}

int main(int argc, char* argv[]){
    string input;                                           // contains input file name
    string output;                                          // contains contains output file name
    string seed;                                            // contains seed for encryption and decrption
    
    
    if(argc == 1){                                          // get values from keyboard if all needed command line values are not entered
        cout << "Enter an input file name: ";
        cin >> input; 
        cout << "Enter an output file name: "; 
        cin >> output; 
        cout << "Enter a seed: ";
        cin >> seed; 
    }
    else if(argc == 2){                             // get the outputs from keyboard if output and seed are not entered via command line
        input = argv[1]; 
        cout << "Enter an output file name: "; 
        cin >> output; 
        cout << "Enter a seed: ";
        cin >> seed; 
    }
    else if(argc == 3){                             // get the outputs form keyboard if seed is not entered via command line
        input = argv[1]; 
        output = argv[2]; 
        cout << "Enter a seed: ";
        cin >> seed; 
    }
    else if(argc >= 4){                             // if all values are entered via command line, assign to designated variable
        input = argv[1]; 
        output = argv[2]; 
        seed = argv[3]; 
    }

    FibLFSR lfsr(seed);                             // initialize object with seed for (for image encryption/decrption only)
    FibLFSR lfsr_ec(seed);                          // object initialized for extra credit
    Image image;                                    // create object for image class

    
    if(!image.loadFromFile(input)){                 // load image from file
        cout << "Unable to open file!" << endl; 
        return -1; 
    }

    // Set up window characteristics for the input image

    Vector2u size = image.getSize();                                       

    RenderWindow input_window(VideoMode(size.x, size.y), "Input Image");    
    
    Texture input_texture;                                                  
    input_texture.loadFromImage(image);                                     

    Sprite input_sprite; 
    input_sprite.setTexture(input_texture);

    // Set up window characteristics for the output

    
    RenderWindow output_window(VideoMode(size.x, size.y), "Output Image");
    
    transform(image, &lfsr);

    Texture output_texture;
    output_texture.loadFromImage(image);

    Sprite output_sprite; 
    output_sprite.setTexture(output_texture);

    //keep windows open unless the window is closed
    while(output_window.isOpen() || input_window.isOpen()){
        Event event; 
        while(output_window.pollEvent(event)){
            if(event.type == Event::Closed){
                output_window.close();
            }
        }

        while(input_window.pollEvent(event)){
            if(event.type == Event::Closed){
                input_window.close();
            }
        }

            output_window.clear(Color::White);
            output_window.draw(output_sprite);
            output_window.display();

            input_window.clear(Color::White);
            input_window.draw(input_sprite);
            input_window.display();
    }

    // Save image as output
    if(!image.saveToFile(output)){
        return -1; 
    }

    //Extra Credit Stuff
    string password = "ILikePizza22";  // string for extra credit

    cout << "This is the original password we want to encrypt: " << password << endl; 

    transform_words(password, lfsr_ec);
    
    cout << "This is the password after encryption: " << password << endl; 

    transform_words(password, lfsr_ec);

    cout << "This is the password after decryption: " << password << endl; 
    
    return 0; 
}


