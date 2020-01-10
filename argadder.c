/*
  CSIS 340: Programming Languages
  This program takes an arbitrary number of command-line parameters, each of which should represent an integer value and prints out the sum of the values provided.
  Paul Macfarlane
 
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
  
  int sum;
  int i; 
  
  sum=0;

  for(i=1; i<argc; i++)
  {
      sum += atoi(argv[i]);
  }
  
  printf("Sum: %d\n",sum);
  
  return 0;
}
