#include <stdio.h>
#include "tokenizer.c" //Functions

int main()
{
  puts("Hi! Welcome to our character");

  while(1) {

    puts("Please input a string to tokenizer ( i ), check history ( h ), or quit ( q )")
    
    int input;
    while((input = getchar() == '\n'); //Ignore entered newlines

    if (input == EOF)
      goto done;
	  
    switch(input) {
    case 'i':
      puts("Enter your new string");
      puts(">");
      char inputString[100];
      fgets(inputString, sizeof(inputString), stdin);
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
      return 0
}
