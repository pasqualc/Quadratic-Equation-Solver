/*
* putIt.c
* License GPL 2.0 JKK Consulting 2019 
*/
//Given two roots, x1 and x2, prints them out. The third argumenet, imaginary,
//tells us if the roots are complex or not. If imaginary is set, then the function
//treats x1 as the real part of the root and x2 as the imaginary part.
void printRoots(double x1, double x2, int imaginary, FILE *log){
    if(imaginary == 1){
        printf("x1 = %.9f + %.9fi\n", x1, x2);
        printf("x2 = %.9f - %.9fi\n", x1, x2);
        //print to log
        if(LOG_ENABLE){
            fprintf(log, "x1 = %.9f + %.9fi\n", x1, x2);
            fprintf(log, "x2 = %.9f - %.9fi\n", x1, x2);
        }
    }
    else{
        printf("x1 = %.9f\n", x1);
        printf("x2 = %.9f\n", x2);
        //print to log
        if(LOG_ENABLE){
            fprintf(log, "x1 = %.9f\n", x1);
            fprintf(log, "x2 = %.9f\n", x2);
        }
    }
}

//Prints values of a, b, and c
void printABC(double a, double b, double c, FILE *log){
    printf("a = %e\tb = %e\tc = %e\n", a, b, c );
    //print to log
    if(LOG_ENABLE) fprintf(log, "a = %e\tb = %e\tc = %e\n", a, b, c );
}

//Special function that only prints a, b and c to log file
void logABC(double a, double b, double c, FILE *log){
    fprintf(log, "a = %e\tb = %e\tc = %e\n", a, b, c );
}

//Prints the help message
void printHelp(){
    printf(">> Input should be three normalized floats, separated by one space.\n");
    printf(">> Scientific notation of form ####e# is acceptable.\n");
    printf(">> Example input: 1 2.0 0.1e1  -- OK\n");
    printf(">> inf asdf 2.3.1  -- not OK\n");
    printf(">> Enter 'q' to quit.\n");
}

//int c is the error code. This function prints the error code that corresponds
//to the value passed to it. Also prints each error to log.
void printError(int c, FILE *log){
    switch(c){
        case(-1):
            printf("Error: 3 numbers not detected.\n");
            if(LOG_ENABLE) fprintf(log, "Error: 3 numbers not detected.\n");
            break;
        case(-2):
            printf("Error: first value cannot be zero.\n");
            if(LOG_ENABLE) fprintf(log, "Error: first value cannot be zero.\n");
            break;
        case(-3):
            printf("Error: One or more values is subnormal.\n");
            if(LOG_ENABLE) fprintf(log, "Error: One or more values is subnormal.\n");
            break;
        case(-4):
            printf("Error: One or more values is infinity.\n");
            if(LOG_ENABLE) fprintf(log, "Error: One or more values is infinity.\n");
            break;
        case(-5):
            printf("Error: One or more values is not a number.\n");
            if(LOG_ENABLE) fprintf(log, "Error: One or more values is not a number.\n");
            break;
        default:
            printf("Error: Unknown Error.\n");
            if(LOG_ENABLE) fprintf(log, "Error: Unknown Error.\n");
            break;
    }
}
