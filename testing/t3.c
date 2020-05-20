/*
* t3.c
* License GPL 2.0 JKK Consulting 2019
*
* Boundary unit test for boundaries of validate()
* function attempts to read and cast 3 number values
* from an input string to double variables (a, b, c),
* and will return a integer flag based upon result
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

// INPUT FLOAT TOO LARGE: Verifies that if an input value has number 
// that is too large to fit in a float, the input is invalid.
void inputFloatTooLarge(double* a, double* b, double* c, int* ret){
    *ret = validate("3.5e+38 123 3", a, b, c);
    assert(*ret == -4);
    tearDown(a, b, c, ret);
}

// INPUT FLOAT TOO SMALL: Verifies that if an input value has number
// that is too small to fit in a float, the input is invalid.
void inputFloatTooSmall(double* a, double* b, double* c, int* ret){
    *ret = validate("1.3e-39 123 3", a, b, c);
    assert(*ret == -3);
    tearDown(a, b, c, ret);
}
// INPUT FLOAT MAX OKAY: Verifies that if an input value is the
// largest possible float value, the input is still valid.
void inputFloatMaxOkay(double* a, double* b, double* c, int* ret){
    *ret = validate("3.4e+38 123 3", a, b, c);
    assert(*ret == 0);
    tearDown(a, b, c, ret);
}
  
// INPUT FLOAT MIN OKAY: Verifies that if an input value is
// the smallest possible float value, the input is still valid.
void inputFloatMinOkay(double* a, double* b, double* c, int* ret){
    *ret = validate("1.2e-38 123 3", a, b, c);
    assert(*ret == 0);
    tearDown(a, b, c, ret);
}

int main() {
    double a;
    double b;
    double c;
    int ret;
    inputFloatTooLarge(&a, &b, &c, &ret);
    inputFloatTooSmall(&a, &b, &c, &ret);
    inputFloatMaxOkay(&a, &b, &c, &ret);
    inputFloatMinOkay(&a, &b, &c, &ret);
    fprintf(stdout, "4/4 tests passed.\nAll tests passed!\n\n");
    exit(0);
}