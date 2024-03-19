#include <stdio.h>
#include "tokenizer.h" //Functions
#include "history.h"

int main()
{
  puts("Hi! Welcome to our character");
  //Have to create a History list here
  List* history = init_history();
  //char inputString[100];
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
	add_history(history, inputString);
	puts("Passed adding to history");
        free_tokens(tokens);
	puts("Freed tokenss");
        break;

      case 'h':

	fputs("Do you want to access a specific index or all history? (Input the '!' for a specific index or 'a' for all)\n>", stdout);
	fflush(stdout);

	int h = getchar();
	while(h == '\n' || h == EOF){
	  h = getchar();
	}
	switch(h){ 
	  case 'a':
	    print_history(history);
	    break;

	  case '!':
	    printf("Enter the number you want to retrieve\n>");
	    getchar();
	    int o = getchar();
	    //puts("PASSING");
	    //Its inputting something into o directly
	    printf(get_history(history, o));	  
	    break; 
	}
	
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
