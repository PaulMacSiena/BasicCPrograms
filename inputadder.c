/*
  CSIS 340: Programming Languages
  This program reads in integers and displays the cummulative sum until the user exits or enters an invalid input
  Paul Macfarlane
 
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
  
  int sum;
  int i;
  int retval;
  sum=0;

  retval = scanf("%d", &i);
  while (retval == 1) {
    sum =  sum + i;
    printf("Sum: %d\n",sum);
    retval = scanf("%d", &i);
  }
  fprintf(stderr, "%s: Could not parse integer value from input. Program Terminated.\n", argv[0]);
  exit(1);
    
  return 0;
}
