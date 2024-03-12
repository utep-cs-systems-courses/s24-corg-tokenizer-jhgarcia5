#include <stdio.h>
#include "tokenizer.h" //Functions
#include "history.h"

int main()
{
  puts("Hi! Welcome to our character");

  while(1) {

    fputs("Please WOKR input a string to tokenizer ( i ), check history ( h ), or quit ( q )\n>", stdout);
    fflush(stdout);
    int c = getchar();
    while(c == '\n' || c == EOF){ //Ignore entered newlines
      c = getchar();
    }
	  
    switch(c) {
      case 'i':
        fputs("Enter your new string\n>", stdout);
	fflush(stdout);
        char inputString[100];
	getchar();
        fgets(inputString, sizeof(inputString), stdin);
	printf("You inputed: %s", inputString);
	char **tokens = tokenize(inputString);
        print_tokens(tokens);
        //HAVE TO ADD TO LLIST IN HISTORY

        free_tokens(tokens);
        break;

      case 'h':
        break;

      case 'q':
        puts("Thank you for using this program!");
        goto done;

      default:
        puts("Please enter a recognized option");

    }     
  }

  done:
  return 0;
}
