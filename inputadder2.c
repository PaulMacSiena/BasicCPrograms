/*
  CSIS 340: Programming Languages
  This program reads in integers and displays the cummulative sum until the user exits or enters an invalid input
  In addition, the program prints the addition problem and its solution at the end of execution.
  Paul Macfarlane
 
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
  
  int sum;
  int x;
  int retval;
  sum=0;
  int *a = (int *)malloc(10*sizeof(int));
  int size = 10;
  int i;
  int currentSize;
  
  //while loop that takes care of scanning all the ints and current sum
  retval = scanf("%d", &x);
  while (retval == 1) {
    a[i] = x;
    i++;
    currentSize++;
    sum =  sum + x;
    printf("Sum to this point: %d\n",sum);
    retval = scanf("%d", &x);
    if (i == size){
      size = size * 2;
      a = (int *)realloc(a,size*sizeof(int));
    }
  }

  //displays the math equation
  int j;
  if (currentSize==1){
    printf("%d = %d", a[0],a[0]);
  }
  else{
    printf("%d", a[0]);
    for (j=1;j<currentSize-1;j++){
      printf(" + %d + ",a[j]); 
    }
    printf("%d = %d ",a[currentSize-1],sum);
    }
  
  free(a);
  return 0;
}
