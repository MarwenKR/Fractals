#pragma once
#define Y 500
#define X 500
#define MAX 100
#include <cmath>

// Constants
const double PI = 3.1415926535897932385;
const double EPS = 1e-8;


// Utility Functions
double random_double() {
    // Return a random real between 0 and 1.
    return rand() / (RAND_MAX + 1.0);
}

double random_double(double min, double max) {
    return min + (max - min) * random_double();
}
