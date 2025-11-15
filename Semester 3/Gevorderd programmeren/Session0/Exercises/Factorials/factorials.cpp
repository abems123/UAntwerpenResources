#include "factorials.h"
#include <iostream>

unsigned long int getFactorialRec(int n) {
    if (n == 0) {
        return 1;
    }
    return n * getFactorialRec(n - 1);
}

unsigned long int getFactorialIter(int n) {
    if (n == 0) return 1;
    
    unsigned long int r = 1;
    for (unsigned long int i = n; i > 1; i--) {
	r *=  i;
    }
    return r;
}
