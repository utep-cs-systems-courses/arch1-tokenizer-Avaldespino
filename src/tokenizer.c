#include <stdio.h>
#include "tokenizer.h"


int space_char(char c){

  if(c == " ")
    return 1;
  else if (c == "\t"))
    return 0;
}


int non_space_char(char c){

  return 0;

}


char *word_start(char *s){

  return "c";
}



char *word_terminator(char *word){

  return "c";
}



int count_words(char *s){

  return 0;

}