/*
  CSIS 340: Programming Languages
  This program performs the same function as a unix wc command.
  It displays the word count, number of lines and bytes in a particular file.
  Paul Macfarlane
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

FILE *fr;


int main(int argc, char *argv[]){
  int lineLength = 1000;
  char *line = (char *)malloc(lineLength*sizeof(char));
  char c;
  if (argc!=2){
    fprintf(stderr, "%s: Please run program with parameter filename. \n", argv[0]);
    exit(1);
  }
  
  fr = fopen(argv[1],"r");

  if (fr == NULL) {
    fprintf(stderr, "%s: File '%s' not found. .\n", argv[0], argv[1]);
    fclose(fr);
    exit(1);
  }

  //lineCount
  int lineCount;
  while ( fgets(line,lineLength,fr) != NULL){
    lineCount++;
  }
  fclose(fr);

  //char count
  fr = fopen(argv[1],"r");
  int charCount;
  while((c=getc(fr))!=EOF){
    charCount++;
  } 
  fclose(fr);

  //word count
  char last;  
  fr = fopen(argv[1],"r");
  free(line);
  int wordCount;
  int space;
  while ((c = getc(fr)) != EOF) {
    last = c;
    if (isspace(c)) {
      space = 1;
      wordCount = wordCount + space;
      space = 0;
    }
  }
  
  fclose(fr);
  printf("%6d %6d %6d %s \n ",lineCount, charCount, wordCount, argv[1]);
  return 0;
}
