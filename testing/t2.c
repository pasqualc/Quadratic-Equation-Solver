/*
* t2.c
* License GPL 2.0 JKK Consulting 2019
*
* Monkey tests for validate()
* Monkey attempts to pass 3 input tokens that can be parsed/cast to a double.
* NOTE: All of these tests expect the validate function to return -1 flag.
* flags:
* 0 = Success
* -1 = Input error: 3 floats not present
* -2 = a is 0 (ie not a quadratic equation)
* -3 = One or more values is subnormal
* -4 = One or more values is infinity
* -5 = One or more values is NaN
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include "validate.c"

// TEAR DOWN: function to set values of testing variables to zero
void tearDown(double* a, double* b, double* c, int* ret){
    *a = 0;
    *b = 0;
    *c = 0;
    *ret = 0;
}

            


        
// MONKEY ONE: Monkey enters gibberish, and the system rejects it as valid input.
void monkeyOne(double* a, double* b, double* c, int* ret){
    *ret = validate("sadk3klz039", a, b, c);
    assert(*ret == -1);
    tearDown(a, b, c, ret);
}

// MONKEY TWO: Monkey enters gibberish resembling 3 float numbers,
// and the system rejects it as valid input.
void monkeyTwo(double* a, double* b, double* c, int* ret){
    *ret = validate("2983 20d0 20d.e", a, b, c);
    assert(*ret == -1);
    tearDown(a, b, c, ret);
}
                
// MONKEY THREE: Monkey enters input with too many decimal points,
// and the system rejects it as valid input.
void monkeyThree(double* a, double* b, double* c, int* ret){
    *ret = validate("2983.3.2.3. 20d020d.e", a, b, c);
    assert(*ret == -1);
    tearDown(a, b, c, ret);
}

// MONKEY FOUR: Monkey enters more input consecutive decimal points,
// and the system rejects it as valid input.
void monkeyFour(double* a, double* b, double* c, int* ret){
    *ret = validate(".2983.. 200 20.2", a, b, c);
    assert(*ret == -1);
    tearDown(a, b, c, ret);
}

int main() {
    double a;
    double b;
    double c;
    int ret;
    monkeyOne(&a, &b, &c, &ret);
    monkeyTwo(&a, &b, &c, &ret);
    monkeyThree(&a, &b, &c, &ret);
    monkeyFour(&a, &b, &c, &ret);
    fprintf(stdout, "4/4 tests passed.\nAll tests passed!\n\n");
    exit(0);
}