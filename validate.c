/*
* validate.c
* License GPL 2.0 JKK Consulting 2019 
*/
//Replaces the first newline character in a string with a null terminator
//https://stackoverflow.com/questions/2693776/removing-trailing-newline-character-from-fgets-buffer
void removeNewLine(char * str){
    char *pos;
    if ((pos=strchr(str, '\n')) != NULL)
        *pos = '\0';
}

//Returns number of decimal points found in a string
int countDecimalPoints(char *str){
    int i, count;
    i = count = 0;
    for (i=0, count=0; str[i]; i++)
        if(str[i] == '.')
            count++;
    return count;
}

//Returns the number of tokens found in a string, delimited by spaces
//https://stackoverflow.com/questions/13078926/is-there-a-way-to-count-tokens-in-c
int countTokens(char *str){
    int count = 0;
    char *ptr = str;
    while((ptr = strchr(ptr, ' ')) != NULL) {
        count++;
        ptr++;
    }
    return ++count;
}

/* Return 0 = Success
   Return -1 = Input error: 3 floats not present
   Return -2 = a is 0 (ie not a quadratic equation)
   Return -3 = One or more values is subnorma    
   Return -4 = One or more values is infinity
   Return -5 = One or more values is NaN
   Return -6 = Number of Arguments != 3
   ---
   This function verifies that the user input is in the format of 
   "[float] [float] [float]". If it detects any errors/invaliad inputs, it 
   returns the corresponding error code. Otherwise it stores the reuslts in
   the values of a, b and c.

*/
int validate(char * line, double * a, double * b, double * c){
    //Declarations
	int flag = 0;
	char * input = malloc(sizeof(char) * 128);
    float af, bf, cf;
	strcpy(input, line);

    // validate num args == 3
    if(countTokens(input) != 3) return -1; 

    //Separate user input into 3 tokens
    char * token1 = strtok(input, " ");
    char * token2 = strtok(NULL, " ");
    char * token3 = strtok(NULL, " ");

    // Test for input like 123.456.789 (too many decimal points); return
    // -1 if invalid number of decimal points detected
    if(countDecimalPoints(token1) > 1) return -1;
    if(countDecimalPoints(token2) > 1) return -1;
    if(countDecimalPoints(token3) > 1) return -1;

    // TODO: count number of significant figures in each value

	//Read input strings into doubles a, b and c
	if(sscanf(line, "%lg %lg %lg", a, b, c) != 3) return -1;

    //Cast doubles to floats for purpose of testing
    af = (float) *a;
    bf = (float) *b;
    cf = (float) *c;

    //Call fpclassify on each value
    int a_fpc = fpclassify(af);
    int b_fpc = fpclassify(bf);
    int c_fpc = fpclassify(cf);

    // Error Tests based on fpclassify return value for af, bf and cf
    if(a_fpc == FP_ZERO)
        flag = -2;
    if(a_fpc == FP_SUBNORMAL || b_fpc == FP_SUBNORMAL || c_fpc == FP_SUBNORMAL)
        flag = -3;
    if(a_fpc == FP_INFINITE || b_fpc == FP_INFINITE || c_fpc == FP_INFINITE)
        flag = -4;
    if(a_fpc == FP_NAN || b_fpc == FP_NAN || c_fpc == FP_NAN){
        flag = -5;
    }
	return flag;
}
