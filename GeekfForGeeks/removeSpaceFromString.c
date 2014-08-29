//Removes all spaces from a given string
//risky, if string is not null terminated, gives SegFault
//Also doesn't check if null pointer is passed.

#include <stdio.h>
#include <stdlib.h>

void removeSpace(char *str) {
  char *p1 = str, *p2 = str;
  do 
    while (*p2 == ' ')
      p2++;
  while (*p1++ = *p2++);
}

int main(int argc, char* argv[]){
	char str[100];
	printf("Enter the string: ");
	scanf(" %[^\n]", str);
	printf("Initially %s\n", str);
	removeSpace(str);
	printf("Finally %s\n", str);
	return 0;
}