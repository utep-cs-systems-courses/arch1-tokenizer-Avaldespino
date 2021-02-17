#include <stdio.h>
#include <unistd.h>
#include "tokenizer.h"
int main(){

  puts("Please type your string then press enter:");

  
   char str[100];
  
   fgets(str,100,stdin);
   puts(str);
   int words;
   words = 0;
  words = count_words(str);
   printf("Word count: %d\n",words);
  
   char *words_term;
   *words_term = *word_start(str);

  
    
    
    //printf("%d\n",str[i]);
      
    // printf("for loop is runing");
    
  

  
 
 done:
  return 1;
}
