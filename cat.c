/*
  CSIS 340: Programming Languages
  This program performs the same function as a unix cat command.
  It displays the contents of a file, with the option to display the number of all output lines,
  number for all nonempty output lines, or no lines specified at all.
  Paul Macfarlane
 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
FILE *fr;

int main(int argc, char *argv[]){

  if (argc<2 || argc>3){
    fprintf(stderr, "%s: Please run program with [OPTIONAL PARAM -n or -b] and/or filename. \n", argv[0]);
    exit(1);
  }

  int lineNumber = 1;
  int lineLength = 10000;
  char *line = (char *)malloc(lineLength*sizeof(char));
  if (argc == 2){
    fr = fopen(argv[1],"r");
    if (fr == NULL) {
      fprintf(stderr, "%s: File '%s' not found. .\n", argv[0], argv[1]);
      free(line);
      fclose(fr);
      exit(1);
    }
    while ( fgets(line,lineLength,fr) != NULL){;
      printf(" %s", line);
    }
  }

  if (argc == 3){
    fr = fopen(argv[2],"r");
    if (fr == NULL) {
      fprintf(stderr, "%s: File '%s' not found. .\n", argv[0], argv[1]);
      free(line);
      fclose(fr);
      exit(1);
    }


    char *cmd = argv[1];
    if (strcmp(cmd, "-n") == 0) {
      //show line numbers for all lines
      while ( fgets(line,lineLength,fr) != NULL){;
	printf("%6d %s",lineNumber, line);
	lineNumber++;
      }
    }
    else if  (strcmp(cmd, "-b") == 0) {
      //show line numbers for all lines                                                                                                                                              
      while ( fgets(line,lineLength,fr) != NULL){;
	if (strcmp(line, "") == 0){
	  printf(" %s", line);
	}
	else{
	  printf("%6d %s",lineNumber, line);
	  lineNumber++;
	}
      }
    }
    else {
      //error, invalid command/param for argv
      fprintf(stderr, "%s: '%s' is not a valid option. Please use -n, -b, or omit the parameter althogether.\n", argv[0], argv[1]);
      free(line);
      fclose(fr);
      exit(1);
    }
  }   

  free(line);
  fclose(fr);

  return 0;
}
