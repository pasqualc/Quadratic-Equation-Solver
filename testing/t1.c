/*
* t1.c
* License GPL 2.0 JKK Consulting 2019
*
* Unit tests for validate()
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

// INPUT VALID WITH INTEGERS: Verifies that 3 integers can be read from an input
// and pass as valid input.
void inputValidWithIntegers(double* a, double* b, double* c, int* ret){
    *ret = validate("12 3 2", a, b, c);
    assert(*ret == 0);
    tearDown(a, b, c, ret);
}

// INPUT VALID WITH FLOATS: Verifies that 3 floats can be read from an input and pass as valid input.
void inputValidWithFloats(double* a, double* b, double* c, int* ret){
    *ret = validate("0.32 .23 12.5", a, b, c);
    assert(*ret == 0);
    tearDown(a, b, c, ret);
}

// INPUT VALID WITH SCIENTIFIC NOTATION: Verifies that 3 numbers expressed in scientific
// can be read from input and pass as valid input.
void inputValidWithScientificNotation(double* a, double* b, double* c, int* ret){
    *ret = validate("1.234e23 1.23e-10 1.2350300000e-4", a, b, c);
    assert(*ret == 0);
    tearDown(a, b, c, ret);
}

// INPUT IS NOT QUADRATIC: Verifies that input is not valid when first number expressed is
// zero (ie a == 0 thus input does not represent quadratic function).
void inputIsNotQuadratic(double* a, double* b, double* c, int* ret){
    *ret = validate("0 2 4", a, b, c);
    assert(*ret == -2);
    tearDown(a, b, c, ret);
}

// INPUT HAS LESS THAN THREE NUMBERS: Verifies that when 3 numbers are not
// given in an input string, the input does not pass as valid.
void inputHasLessThanThreeNumbers(double* a, double* b, double* c, int* ret){
    *ret = validate("1 2", a, b, c);
    assert(*ret == -1);
    tearDown(a, b, c, ret);
}

// INPUT HAS NON NUMERIC TOKENS: Verifies that when there is a token
// in the input string, the input does not pass as valid.
void inputHasNonNumericTokens(double* a, double* b, double* c, int* ret){
    *ret = validate("12 2.3 adf", a, b, c);
    assert(*ret == -1);
    tearDown(a, b, c, ret);
}

// INPUT HAS INFINITY: Verifies that when there is an input token that
// evaluates to infinity, the input does not pass as valid.
void inputHasInfinity(double* a, double* b, double* c, int* ret) {
    *ret = validate("1.000e10000 1.023e-4 1.23", a, b, c);
    assert(*ret == -4);
    tearDown(a, b, c, ret);
}

// INPUT HAS NAN: Verifies that when there is an input token that evaluates
// to NaN, the input does not pass as valid.
void inputHasNan(double* a, double* b, double* c, int* ret){
    *ret = validate("NaN 123 3", a, b, c);
    assert(*ret == -5);
    tearDown(a, b, c, ret);
}

// INPUT HAS SUBNORMAL: Verifies that when there is an input token that
// evaluates to a subnormal normal, the input does not pass as valid.
void inputHasSubnormal(double* a, double*b, double*c, int* ret){
    *ret = validate("0.12e-38 -255 123", a, b, c);
    assert(*ret == -3);
    tearDown(a, b, c, ret);
}

int main() {
    double a;
    double b;
    double c;
    int ret;
    inputValidWithIntegers(&a, &b, &c, &ret);
    inputValidWithFloats(&a, &b, &c, &ret);
    inputValidWithScientificNotation(&a, &b, &c, &ret);
    inputIsNotQuadratic(&a, &b, &c, &ret);
    inputHasLessThanThreeNumbers(&a, &b, &c, &ret);
    inputHasNonNumericTokens(&a, &b, &c, &ret);
    inputHasInfinity(&a, &b, &c, &ret);
    inputHasSubnormal(&a, &b, &c, &ret);
    inputHasNan(&a, &b, &c, &ret);
    fprintf(stdout, "9/9 tests passed.\nAll tests passed!\n\n");
    exit(0);
}