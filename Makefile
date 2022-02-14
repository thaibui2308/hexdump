# Student Name: Thai Bui
# Class Account: cssc0408@edoras.sdsu.edu
# Course: CS530, Spring 2022
# Assignment #1, Hex/Bin File Reader
# Makefile


default: xed

xed.o: xed.c 
	gcc -c xed.c -o xed.o

xed: xed.o
	gcc xed.o -o xed

clean:
	-rm -f xed.o
	-rm -f xed