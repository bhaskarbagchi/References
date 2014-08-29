#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main ()
{
  char str[100000];// ="- This, a sample string.";
  char target[100000], temp[10000];
  scanf(" %[^\n]", str);
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ");
  strcpy(target, "");
  strcpy(temp, "");
  while (pch != NULL)
  {
    strcpy(temp, pch);
    strcat(temp, " ");
    strcat(temp, target);
    strcpy(target, temp);
    pch = strtok (NULL, " ,.-");
  }
  printf("%s\n", target);
  return 0;
}