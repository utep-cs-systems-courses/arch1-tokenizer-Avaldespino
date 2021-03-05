#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "tokenizer.h"
int main(){

  puts("Please type your string then press enter:");

  
   char str[100];
  
   fgets(str,100,stdin);
   puts(str);
   
   char **tokens = tokenize(str);
   
   printf("Checking to see if it changed\n");
   print_tokens(tokens);
    
    
    //printf("%d\n",str[i]);
      
    // printf("for loop is runing");
    
  

  
 
 done:
  return 0;
}
