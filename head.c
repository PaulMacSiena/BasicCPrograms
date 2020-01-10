/*
  CSIS 340: Programming Languages
  This program performs the same function as a unix head command.
  It displays the first n (userspecified) lines of a file, or first 10 lines if user does not specify
  Paul Macfarlane
 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

FILE *fr;

int main(int argc, char *argv[]){
   
  if (argc<2 || argc>3){
    fprintf(stderr, "%s: Please run program with [OPTIONAL PARAM -n where n is number of lines to displat] and/or filename. \n", argv[0]);
    exit(1);
  }
  int lineLength = 1000;
  int linesToDisplay;
  char *line = (char *)malloc(lineLength*sizeof(char));
  if (argc == 2){
    fr = fopen(argv[1],"r");
    if (fr == NULL) {
      fprintf(stderr, "%s: File '%s' not found. .\n", argv[0], argv[1]);
      free(line);
      fclose(fr);
      exit(1);
    }
    linesToDisplay = 10;
    int i;//will increment until it reaches 10 or end of file
    while ( fgets(line,lineLength,fr) != NULL && i <linesToDisplay){;
      printf("%s", line);
      i++;
    }
  }
  
  if (argc == 3){
    fr = fopen(argv[2],"r");
    if (fr == NULL) {
      fprintf(stderr, "%s: File '%s' not found. .\n", argv[0], argv[2]);
      free(line);
      fclose(fr);
      exit(1);
    }
    int i; //increments until it reaches lines to Diplay, or end of file
    linesToDisplay = atoi(argv[1]);
    while ( fgets(line,lineLength,fr) != NULL && i<linesToDisplay){;
	printf("%s",line);
	i++;
    }                                                                            
  }

  free(line);
  fclose(fr);

  return 0;
}
