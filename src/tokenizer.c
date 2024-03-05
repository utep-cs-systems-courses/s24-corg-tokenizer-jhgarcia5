#ifndef _TOKENIZER_
#define _TOKENIZER_

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if (strcmp(c," ") | strcmp(c, "\t")){
    return 1;
  }

  return 0;
}

/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c)

  if (strcmp(c," ") | strcmp(c,"\t") | strcmp(c, "\0")){
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
  while(non_space_char(*token){   
      token += 1
  }
  return token;
}

/* Counts the number of tokens in the string argument. */
int count_tokens(char *str)
{
  int tokens_found = 0;
  int *i = str;
  while(i != '\O') {

    //Continuously ask for token start and end, count 1 everytime we complete.
    
    i = token_start(i);

    if (*i){
      tokens_found += 1;
      i = token_terminator(i);
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
   int lenStr = strlen(str);
   
   while(index < lenStr){

     index = token_start(index);
     char *endOfString = token_terminator(index);
     char length = endOfString - index;

     token[token_index] = copy_str(index, length); 

     tokenIndex += 1;
     ptr = endOfString
   }
 }
 
/* Prints all tokens. */
void print_tokens(char **tokens)
{
  int index = 0;
  while(tokens[index] != '\0'){
    printf(tokens[index]);
    index += 1;
  }
  printf(tokens[index]);
}

/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens)
{
  int index = 0;
  while(tokens[index] != '\0'){
    free(tokens[index]);
    index += 1;

  }

  free(tokens[index]);
  free(tokens);
}

#endif
