#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void main(int argc, char** argv){
  char test[8] = "racecar";
  int length = strlen(test);
  printf("length = %d\n", length);
  if(isPalindrome(test))
    printf("test string is a palindrome\n");
  else
    printf("test string is not a palindrome\n");
}

int isPalindrome(char *string_in){

  int length = strlen(string_in);
  printf("length = %d\n", length);
  char reverse[length+1];
  int j;
  for(j = 0; j < length-1;j++)
    string_in[j] = tolower(string_in[j]);
  int i,forw = 0;
  for(i = length-1; i >= 0; i--){
    reverse[forw] = string_in[i];
    forw++;
  }
  reverse[forw+1] = '\0';

  printf("%s\n", string_in);
  printf("%s\n", reverse);

  if(strcmp(reverse, string_in) == 0){
    return 1;//true
  }else{
    return 0;//false
  }

}
