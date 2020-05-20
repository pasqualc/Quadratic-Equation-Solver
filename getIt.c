/*
* getIt.c
* License GPL 2.0 JKK Consulting 2019 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 Initial prompt for user --
 separate function so we can loop without printing this garbage every time
*/
void firstPrompt(){
	printf("\n>> Quadratic Solver v. 1.01\n");
	printf(">> License GPL 2.0 JKK Consulting 2109\n");
	printf(">> Limit Input to 4 Significant Digits.\n");
	printf(">> Scientific Notation is Allowed.\n");
	printf(">> Enter \"help\" for more detailed information.\n");
}

/*
 This function prompts the user for 3 space-separated floats and
 returns them as a string for further use.
*/
char * getIt(char * input){
	printf("\nEnter 3 floats, separated by a space: \n> ");

	fgets(input, 128, stdin);

	//printf("\nRead >> %s\n", input);

	return input;
}
