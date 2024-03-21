#include <stdio.h>
#include "tokenizer.h" //Functions
#include "history.h"

int main()
{
  printf("Hi! Welcome to our character");
  //Have to create a History list here
  List* history = init_history();
  //char inputString[100];
  while(1) {

    printf("Please WOKR input a string to tokenizer ( i ), check history ( h ), or quit ( q )\n>");
    int c = getchar();
    while(c == '\n' || c == EOF){ //Ignore entered newlines
      c = getchar();
    }
	  
    switch(c) {
      case 'i':
        printf("Enter your new string\n>");
        char inputString[100];
	getchar();
        fgets(inputString, sizeof(inputString), stdin);
	printf("You inputed: %s", inputString);
	char **tokens = tokenize(inputString);
        print_tokens(tokens);

	//HAVE TO ADD TO LLIST IN HISTORY
	add_history(history, inputString);
        free_tokens(tokens);
        break;

      case 'h':

	printf("Do you want to access a specific index or all history? (Input the '!' for a specific index or 'a' for all)\n>");
	getchar();

	char h = getchar();
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
	    char o = getchar();
	    int val = atoi(o);
	    
	    //puts("PASSING");
	    //Its inputting something into o directly
	    printf(get_history(history, o));	  
	    break; 
	}
	
	break;

      case 'q':
        puts("Thank you for using this program!");
	free_history(history);
	goto done;

      default:
        puts("Please enter a recognized option");

    }     
  }

  done:
  return 0;
}
