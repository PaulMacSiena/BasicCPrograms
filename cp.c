/*
  CSIS 340: Programming Languages
  This program performs the same function as a unix cp command.
  It copies one file to another file
  Paul Macfarlane
 
*/

#include <stdio.h>
#include <stdlib.h>

FILE *fr;
FILE *fw;

int main(int argc, char *argv[]){
 
  if (argc!=3){
    fprintf(stderr, "%s: Please run program with [Name of File to Copy from] [Name of File to copy too]. Program Terminated.\n", argv[0]);
    exit(1);
  }
  
  
  fr = fopen(argv[1],"r");
  if (fr == NULL) {
    fprintf(stderr, "%s: File '%s' not found. Program Terminated.\n", argv[0], argv[1]);
    exit(1);
  }

  fw = fopen(argv[2],"w");
  char c;
  while((c=getc(fr))!=EOF)
    putc( c, fw); 
  fclose(fr); 
  fclose(fw);; 
  
  return 0;
}
