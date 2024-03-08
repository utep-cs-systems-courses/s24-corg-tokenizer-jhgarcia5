#ifndef _TOKENIZER_
#define _TOKENIZER_
#include <stdio.h>
#include <stdlib.h>

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if ((c == ' ') | (c == '\t')){
    return 1;
  }

  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)
{
  if ((c == ' ') | (c == '\t') | (c ==  '\0')){
    return 0;
  }
  return 1;
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str)
{
  while (space_char(*str)) {
    str += 1;
  }
  return str;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token)
{
  while(non_space_char(*token)){   
    token += 1;
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str)
{
  int tokens_found = 0;
  char *index = str;
  while(*index != '\0') {

    //Continuously ask for token start and end, count 1 everytime we complete.
    
    index = token_start(index);

    if (*index){
      tokens_found += 1;
      index = token_terminator(index);
    }
  }
  return tokens_found;
}

/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len)
{
  char *copyInStr = malloc((len + 1) * sizeof(char));
  int stringIndex = 0;

  while(stringIndex < len){
    copyInStr[stringIndex] = inStr[stringIndex];
    stringIndex += 1;
  }  
  return copyInStr;
}
 
 
/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
 char **tokenize(char* str)
 {
   int numTokens = count_tokens(str);
   char **tokens = malloc((numTokens + 1) * sizeof(char));

   int tokenIndex = 0;
   char *index = str;
      
   while(*index != '\0'){

     index = token_start(index);
     char *endOfString = token_terminator(index);
     char length = endOfString - index;

     tokens[tokenIndex] = copy_str(index, length); 

     tokenIndex += 1;
     index = endOfString;
   }
   return tokens;
 }
 
/* Prints all tokens. */
void print_tokens(char **tokens)
{

  for (int i = 0; tokens[i] != NULL; i++){
    printf("%d = %s", i, tokens[i]);
  }
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{

  for (int i = 0; tokens[i] != NULL; i++){
    free(tokens[i]);
  }

  free(tokens);
}

#endif
