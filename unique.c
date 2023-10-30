#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(int argc, char *argv[]) {
    // open file
     FILE *fp;
     if(argc > 1){
        fp = fopen(argv[1], "r");
        if(fp == NULL){
            printf("Error opening the file :-(");
            return 1;
        }
     } else {
        // no argument so use user input
        fp = stdin;
     }


    // initialize pointers for previous and current line
    // initialize variables for length of previous and current line
    char *line = NULL;
    size_t prevLen = 0;
    char *prevLine = NULL;
    size_t len = 0;
    // initialize variable to store what's read
    size_t read;


    // read until EOF
    while((read = getline(&line, &len, fp)) != -1){
        if(line != NULL){
            // comparing lines character by character
            // compare chars up to len of previous line and dont access memory beyond bytes read
            size_t i;
            for(i = 0; i < prevLen && i < read; i++){
                // if chars are different
                if(prevLine[i] != line[i]){
                    // exit and go onto next
                    printf("%s",prevLine);
                    //breaks right as first difference is found
                    break;
                }
            }
        }


        // swap pointers so prevLine always points to line that was in previous line from loop
        // loop can now change line to new upcoming line
        prevLen = read;
        char *temp = prevLine;
        prevLine = line;
        line = temp;
    }
    // print last line
    printf("%s",prevLine);
    fclose(fp);
    return 0;


}
