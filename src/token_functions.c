#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>


int space_char(char c){

   
  // printf("space_char is accessed\n");
  if(c == ' '||c == '\t'){
    

    return 1;}
 
  else return 0;


}


int non_space_char(char c){
  // printf("In non space char, this is c:%c\n",c);
  if (c != ' ' || c != '\t'){
    
  
    return 1;
  }
  else return 0;

}

char *word_start(char *s){
  char *zero_ptr ="0";
  char *temp_ptr;
  char temp;
  temp_ptr = s;
  // printf("in word start\n");
  while(*temp_ptr != '\0'){
    // printf("in while\n");
    temp = *temp_ptr;
    if(non_space_char(temp) == 1){
    return temp_ptr;
    }
    temp_ptr++;
  }
  
    return zero_ptr;
  }


char *word_terminator(char *word){
  char *word_term = "\0";
  char temp;
  // printf("Here in word_term\n");
  while(*word != '\0'){
    temp = *word;
    // printf("%c\n",temp);
    if(space_char(temp)==1){
      *word = '\0';
      break;
    }
    word++;
  }

  
  return word;
}

int count_words(char *str){
  int count,i,in_word;
  count = 0;
  i = 0;
  in_word = 0;
  
  while(i<100){
   
    if(space_char(str[i])==1 && in_word == 1){
      
      in_word = 0;
      
      str++;
      
      
    }
    else if (non_space_char(str[i]) == 1 && in_word ==0 ){
      in_word = 1;
      count++;
    }
    i++;
  }
  return count;
}
char *copy_str(char *inStr, short len){
  char *copy = (char*)malloc((len+1)*sizeof(char)) ;
    
  for(int i = 0; i < len; i++){
    copy[i] = inStr[i];

  }
  copy[len] = '\0';
  printf(copy);
    return copy;

  }

char **tokenize(char* str){
  int words = count_words(str);

  char **tokens = (char**)malloc((words+1)*sizeof(char*));

  char *start_wrd = word_start(str);
  char *end_wrd;

  for(int i = 0; i<words; i++){
    end_wrd = word_terminator(start_wrd);
    *tokens[i] = copy_str(start_wrd, (end_wrd - start_wrd));
    start_wrd = word_start(end_wrd);
  }
  tokens[words+1] = '\0';
  return tokens;


  
}

void print_tokens(char **tokens){
  for(int cr = 0; cr < (tokens+cr); cr++)
    {printf("%s \n", *(tokens+cr));
    }
}
void free_tokens(char **tokens){
  while(*tokens != '\0'){
    free(*tokens);
  }
  free(tokens);

}

