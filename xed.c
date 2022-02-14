/*
* Student Name: Thai Bui
* Class Account: cssc0408@edoras.sdsu.edu
* Course: CS530, Spring 2022
* Assignment #1, Hex/Bin File Reader
* xed.c
*/

#include <stdio.h>
#include <stdlib.h>

void hex(int n, int bound) {
  char addr[100];
    
  int j;
  int i = 0;

  while (n != 0) {
    int temp = 0;
    temp = n % 16;
 
        // check if temp < 10
    if (temp < 10) {
      addr[i] = temp + 48;
      i++;
    } else {
      addr[i] = temp + 55;
      i++;
    }
 
    n = n / 16;
  }
    
  for (j=0; j < bound-i; j++)
    printf("0");

  for (j=i-1; j >= 0; j--) 
    printf("%c",addr[j]);
    
    
}

void bin(int n, int bound) {
  int i, j;

  for (i = bound; i >0; i--) {
    j = n >> i;
    if (j & 1)
      printf("1");
    else 
      printf("0");
  }

  printf(" ");
}

void binEncoded(char *filename) {
  int i = 0;
  char content[100];
  int memAddr = 0;
  int lnbr = 0;
  
  int tmp;
  FILE *fp ;
  char c ;
  fp = fopen ( filename, "r" ) ; // opening an existing file
  if ( fp == NULL ) {
    printf("Error opening file!");
    exit(0);
  } 
  while (1) {
    c = fgetc ( fp ) ; // reading the file
    if ( c == EOF )
      break ;
    if (lnbr == 0) {
      printf("0000000: ");
    }
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
      content[i] = c;
    } else {
      content[i] = '.';
    }
    i++;
    lnbr++;
    tmp = (int) c;
    bin(tmp, 8);
    printf(" ");

    if (lnbr % 6 == 0) {
      printf(" %s",content);
      i = 0;
      memAddr += 6;
      printf("\n");
      hex(memAddr, 7);
      printf(": ");
    }
  }

  if (lnbr % 6 != 0) {
    int r = lnbr % 6;
    for (i = 0; i < 6-r;i++) {
      printf("        ");
      printf("  ");
    }
    printf(" %s", content);
  }

  fclose (fp) ; // Closing the file
}

void main(int argc, char **argv) {
  char *filename;
  if (argc <= 1) {
    printf("Missing filename!");
    exit(0);
  } else if (argc == 2) {
    filename = *(argv+1);
    int i = 0;
  char content[100];
  int memAddr = 0;
  // Hex Mode breakpoints
  int lineBr = 0;
  int byteBr = 0;
  
  int tmp;
  FILE *fp ;
  char c ;
  fp = fopen (filename, "r" ) ; // opening an existing file
  if ( fp == NULL ) {
    printf("Error opening file!");
    exit(0);
  }
  while (1) {
    c = fgetc ( fp ) ; // reading the file
    if ( c == EOF )
      break ;
    if (lineBr == 0) {
      printf("0000000: ");
    }
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
      content[i] = c;
    } else {
      content[i] = '.';
    }
    i++;
    byteBr++;
    lineBr++;
    tmp = (int) c;
    hex(tmp, 2);
    if (byteBr % 2 == 0) 
      printf("  ");

    if (lineBr % 16 == 0) {
      printf("%s",content);
      i = 0;
      memAddr += 16;
      printf("\n");
      hex(memAddr, 7);
      printf(": ");
    }
   }

  if (lineBr % 16 != 0) {
    int r = lineBr % 16;
    for (i = 0; i < (16-r);i++) {
      printf("  ");
      printf(" ");
    }
    if (r % 2 == 0)
      printf("%s", content);
    else 
      printf(" %s", content);
  }

    fclose(fp); // Closing the file
  } else if (argc == 3) {
    filename = *(argv+2);
    binEncoded(filename);
  } else {
    printf("Too many arguments!");
  }

}

