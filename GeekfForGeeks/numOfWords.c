#include <stdio.h>
#include <stdlib.h>

int countNumWords(const char *str) {
  int inWord = 0;
  int wordCount = 0;
  while (*str) {
    if (!inWord && isalpha(*str)) {
      inWord = 1;
      wordCount++;
    }
    else if (inWord && *str == ' ') {
      inWord = 0;
    }
    str++;
  }
  return wordCount;
}

int main(int argc, char* argv[]){
  char str[100];
  printf("Enter String : ");
  scanf(" %[^\n]", str);
  printf("Given String : %s \n", str);
  printf("Numer of words = %d \n", countNumWords(str));
  return 0;
}