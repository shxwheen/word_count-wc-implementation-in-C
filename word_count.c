#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
   FILE *fh;
   // open file
   if(argc > 1){
      fh = fopen(argv[1], "r");
      if (fh==NULL){
         printf("error opening file");
         return 1;
         }
      }
   // no arguments then use user input
   else {
      fh = stdin;
   }
   // intitialize char variable and counts
   char ch;
   int count = 0;
   int words = 0;
   int lines = 0;
   // initialize flag
   // if flag is 0, then not in word, if flag is 1, then in word
   int flag = 0;
   // while not EOF, parse thru chars
   while((ch = fgetc(fh)) != EOF){
      count++;
      // line count
      if(ch == '\n'){
         lines++;
      }
      // word count
      if(isspace(ch) || ch == '\n'){
         // flag to check if in word
         if(flag){
            // reset flag
            flag = 0;
            words++;
         }
      } else{
         // trigger flag if not in space
         flag = 1;
      }


   }
   // if flag is triggered, count last word
   // need this if no space after last word
   if (flag){
      words++;
   }
   // print wc
   printf("lines:%d\n", lines);
   printf("words:%d\n", words);
   printf("chars:%d\n",count);
   // close file
   fclose(fh);
   return 0;
   
   }
