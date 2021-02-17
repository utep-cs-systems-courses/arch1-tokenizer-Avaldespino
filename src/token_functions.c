#include <stdio.h>
#include "tokenizer.h"


int space_char(char c){

  
  // printf("space_char is accessed\n");
  if(c == ' '||c == '\t'){
    

    return 1;}
 
  else return 0;


}


int non_space_char(char c){
  
  if (c != ' ' || c != '\t'){
    
  
    return 1;
  }
  else return 0;

}

char *word_start(char *s){
  char *word_start_ptr = s;
  int i;
  int in_word;
  in_word = 0;
  i = 0;
  while(i < 100){
    if(space_char(s[i])== 1 && in_word == 1){
      in_word = 0;
    }

    if(non_space_char(s[i]) == 1 && in_word == 0)
      in_word = 1;
    *word_start_ptr = s[i];
    i++;
  }
  

  return word_start_ptr;
}

char *word_terminator(char *word){
  return "a";
}

int count_words(char *str){
  int count,i,in_word;
  count = 0;
  i=0;
  in_word = 0;
  
  while(i < 100){
   
    if(space_char(str[i])== 1 && in_word == 1){
      
      in_word = 0;
      
    }
    else if (non_space_char(str[i]== 1) && in_word ==0 ){
      in_word = 1;
      count++;
    }
    i++;
  }
  return count;
  
    


}
