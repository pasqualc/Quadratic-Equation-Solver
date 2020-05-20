/*
* main.c
* License GPL 2.0 JKK Consulting 2019 
*/
#define LOG_ENABLE 0
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<float.h>
#include"getIt.c"
#include"putIt.c"
#include"validate.c"
#include"qsolve_roots.c"

//On a loop, prompts the user for their input. Calls functions to validate input,
//and if input is valid, proceeds to call the qsolve_roots function.
int main(int argc, char const *argv[]){
    int iflag, vflag;
    FILE *log = fopen("qsolve.log","a+");
    double a, b, c, x1, x2;
  	char * line = malloc(sizeof(char)*128);
  	firstPrompt();
  	while(1){
  	  line = getIt(line);
      removeNewLine(line);
      if(strcmp(line, "q\0") == 0) break; //exit if user enters "q"
      if(strcmp(line, "help\0") == 0){    //printHelp() if user enters "help"
          printHelp();
          continue;
      }
      if((vflag = validate(line, &a, &b, &c)) == 0){ //validate input
          iflag = qsolve_roots(a, b, c, &x1, &x2);   //solve
          printABC(a, b, c, log);                    //print results
          printRoots(x1, x2, iflag, log);
      }
      else{
        if(LOG_ENABLE) logABC(a, b, c, log);
        printError(vflag, log);
      } 
  	}
    if(LOG_ENABLE) fclose(log);
    return 0;
}
