#include <stdio.h>
#include "tokenizer.h"
#include <stdlib.h>
#include <string.h>


int space_char(char c){

   
  // printf("space_char is accessed\n");
  if(c == ' ' || c == '\t'){
    

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
//char *word_start(char *s){
// char *zero_ptr ="0";
// char *temp_ptr;
// char temp;
// temp_ptr = s;
  // printf("in word start\n");
// while(*temp_ptr != '\0'){
    // printf("in while\n");
//  temp = *temp_ptr;
//  if(non_space_char(temp) == 1){
//  return temp_ptr;
//  }
//  temp_ptr++;
// }
  
//  return zero_ptr;
// }

char *word_start(char *s){
  if(s == "\0") return "NULL";
  // printf("This is current word start: %c\n",s);
  if((int)non_space_char(s)){
    // printf("Here is word start: %c\n", s);
    return &s;}
  word_start(*s+1);
}

char *word_terminator(char *s){
  if(s == '\0') return "NULL";
  if((int)space_char(s)){
    // *s = '\0';
    // printf("word_term: %c\n",(*s-1));
    return *s;}

}
//char *word_terminator(char *word){
// char *word_term = "\0";
// char temp;
  // printf("Here in word_term\n");
// while(*word != '\0'){
// temp = *word;
    // printf("%c\n",temp);
// if(space_char(temp)==1){
// *word = '\0';
//    break;
//  }
//  word++;
//}

  
//return word;
//}

int count_words(char *str){
  int count,i,in_word;
  count = 0;
  i = 0;
  in_word = 0;
  
  while(i<100){
    
    // printf("inword = %i\n",in_word);
    if(space_char(str[i])==1 && in_word == 1){
       printf("This is space_char: %c", str[i]);
      in_word = 0;
      
      str++;
      
      
    }
    if (non_space_char(str[i]) == 1 && in_word ==0 ){
      in_word = 1;
       printf("This is non_space_char: %c", str[i]);
      count++;
    }
    i++;
  }
  // printf("This is count: %i", count);
  return count;
}
char *copy_str(char *inStr, short len){
  printf("First line of copy str\n");
  
  char *copy;
  copy = malloc(len+1);
  if(!copy){printf("Error in copy allocate\n");}
  printf("IN copy str\n");
  while(*inStr){
    *copy++ = *inStr++;
  }
  // for(int i = 0; i <= len; i++){
  //copy[i] = inStr[i];

  //}
  
  printf("Out of loop\n");
  copy[len] = '\0';
  printf(copy);
    return copy;

  }

char **tokenize(char* str){
  
  int words = count_words(str);

  char **tokens = (char**)malloc((words+1)*sizeof(char*));

  char *start_wrd = word_start(str);
  char *end_wrd;
  printf("This is tokenize \n");
  printf("words = %i \n", words);
  printf("First letter is: %c  \n", start_wrd);
  

  for(int i = 0; i<words; i++){
    end_wrd = word_terminator(start_wrd);
    printf("in loop in tokenize\n");
    tokens[i] = copy_str(start_wrd, (end_wrd - start_wrd));
    printf("After set tokens[i]\n");
    start_wrd = word_start(end_wrd);
  }
  tokens[words+1] = '\0';
  return tokens;


  
}

void print_tokens(char **tokens){
  for(int cr = 0; cr < (tokens+cr); cr++)
    {printf("Here is a check for print_tokens \n");
      printf("%s \n", *(tokens+cr));
    }
}
void free_tokens(char **tokens){
  while(*tokens != '\0'){
    free(*tokens);
  }
  free(tokens);

}

