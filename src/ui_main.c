#include <stdio.h>
#include <unistd.h>
#include "tokenizer.h"
int main(){

  puts("Please type your string then press enter:");

  
  char str[100];
  

  fgets(str,100,stdin);
  puts(str);

  
 
 done:
  return 1;
}
