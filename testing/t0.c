/*
* t0.c
* License GPL 2.0 JKK Consulting 2019
*
* Unit tests for qsolve_roots()
* solves a * x^2 + b x + c = 0
* for roots x1 and x2
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include "qsolve_roots.c"

// TEAR DOWN: function to set values of testing variables to zero
void tearDown(double* a, double* b, double* c, double* x1, double* x2, int* ret) {
    *a = 0;
    *b = 0;
    *c = 0;
    *x1 = 0;
    *x2 = 0;
    *ret = 0;
}

// QUAD HAS ONE ROOT: Verifies that the quad has only one root when 
// the descriminant is zero.
void quadHasOneRoot(double* a, double* b, double* c, double* x1, double* x2, int* ret) {
    double  expected_x1, expected_x2;
    *a = 1;
    *b = 2;
    *c = 1;
    expected_x1 = -1;
    expected_x2 = -1;
    *ret = qsolve_roots(*a, *b, *c, x1, x2);
    assert(*ret == 0);
    assert(*x1 == expected_x1);
    assert(*x2 == expected_x2);
    assert(*x1 == *x2);
    tearDown(a, b, c, x1, x2, ret);
}

// QUAD ROOTS VALID ERROR: Veriries that the absolute difference between the expected result
// and the actual result is less than FLT_EPSILON.
void quadRootsValidError(double* a, double* b, double* c, double* x1, double* x2, int* ret){
    *a = 2.235;
    *b = 236.12;
    *c = 20.39;
    double expected_x1 = -0.086425097;
    double expected_x2 = -105.560107342;
    *ret = qsolve_roots(*a, *b, *c, x1, x2);
    assert(fabs(expected_x1 - *x1) <= FLT_EPSILON);
    assert(fabs(expected_x2 - *x2) <= FLT_EPSILON);    
}

// QUAD HAS NO REAL ROOTS: Verifies that the quad has no real roots when
// the descriminant is negative.
void quadHasNoRealRoots(double* a, double* b, double* c, double* x1, double* x2, int* ret) {
    *a = 3;
    *b = 2;
    *c = 1;
    *ret = qsolve_roots(*a, *b, *c, x1, x2);
    assert(*ret == 1);
    tearDown(a, b, c, x1, x2, ret);
}

int main() {
    double	a, b, c;
    double  x1, x2;
    int	ret;
    quadRootsValidError(&a, &b, &c, &x1, &x2, &ret);
    quadHasOneRoot(&a, &b, &c, &x1, &x2, &ret);
    quadHasNoRealRoots(&a, &b, &c, &x1, &x2, &ret);
    fprintf(stdout, "3/3 tests passed.\nAll tests passed!\n\n");
    exit(0);
}