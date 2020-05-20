/*
* qsolve_roots.c
* License GPL 2.0 JKK Consulting 2019
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int qsolve_roots(double a, double b, double c, double *x1, double *x2){
    int retval = -1;
    double root1, root2, discrim;
    discrim = (b*b)-(4.0*a*c);
    if(discrim > 0){
        retval = 0;
        root1 = (-b + sqrt(discrim))/(2*a);
        root2 = (-b - sqrt(discrim))/(2*a);
    }
    else if(discrim == 0){
        retval = 0;
        root1 = -b/(2*a);
        root2 = root1;
    }
    else{  //discrim < 0
        retval = 1;
        root1 = -b/(2.0*a);
        root2 = sqrt(-discrim)/(2.0*a);
    }
    *x1 = root1;
    *x2 = root2;
    return retval;
}