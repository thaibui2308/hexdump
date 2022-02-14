default: xed

xed.o: xed.c 
	gcc -c xed.c -o xed.o

xed: xed.o
	gcc xed.o -o xed

clean:
	-rm -f xed.o
	-rm -f xed