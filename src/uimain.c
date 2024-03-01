#include <stdio.h>
#include "tokenizer.c" //Functions

int main()
{
  puts("Hi! Welcome to our character");

  while(1) {

    puts("Would you like to input a string ( i ) ");

    int input;
    while((input = getChar() == '\n'); //Ignore entered newlines

    if (input == EOF)
      goto done;
	  
    switch(input) {
    case 'i':
      puts("Enter your new string");
      break;

    case 'h':
      break;
    }
  }
}
