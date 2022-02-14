// Student Name: Thai Bui
// Class Account: cssc0408@edoras.sdsu.edu
// Course: CS530, Spring 2022
// Assignment #1, Hex/Bin File Reader
// README.txt

# This project contains four files in total:
    xed.c
    Makefile
    README.txt
    sample.txt

# Compile instructions
    * In order to install this application, run this bash command in your terminal: make 

# Operating instructions 
    * To read and print the file specified by in ASCII/hex format
        xed <filename>
    * To read and print the file specified by in ASCII/bin format
        xed -b <filename>

# One of the design decisions that I personally think that is significant for this program
  is to not use an array to store all the bytes read from the file for the purpose of memory efficient 
  because each time the application is evoked, it only runs one time and then terminates so 
  instead of using an array as a buffer to store all the bytes of a file and then encoding them to 
  their respective hex/bin values, I just encoded each byte read from the file directly. 

# Before doing this project, I thought that the file I/O operation in C as well as other programming languages 
  is only efficient for text file only but since one of the requirement of this assignment is to be able to execute your 
  application with various file format, I have learned that file I/O of any language is generic to any format because the input stream
  read from the file comes in in terms of a stream of bytes.  


