#include <iostream>     // cout, cin
#include <string>       // string, stod
#include <stdlib.h>     // atof

#include "quadratic.h"  // string_to_double

/* This is a quadratic equation solver where the user
 * passes coefficients for the quadratic formula (y = ax^2+bx+c)
 * and calculates zero, one, or two solutions.
 * The number of solutions is determined by the determinant of the formula:
 * negative - zero solutions; 0 - one solution; positive - two solutions
 * The solver also checks to make sure there aren't any divide by 0 errors
 * in the final step: (b +/- determinant) / (2*a)
 */
int main(int argc, char **argv)
{

    // Check for arguments and convert to doubles
    // Will crash if non-numeric values are entered (intended)
    if (argc < 4)
        throw std::runtime_error("Missing one or more required arguments");

    double a, b, c;
    if (!string_to_double(argv[1], &a))
        return 1;
    if (!string_to_double(argv[2], &b))
        return 1;
    if (!string_to_double(argv[3], &c))
        return 1;

    double solutions[2];
    int num_solutions = solve_quadratic(a, b, c, solutions);

    if (num_solutions == 0)
        std::cout << "" << std::endl;
    else if (num_solutions == 1)
        std::cout << solutions[0] << std::endl;
    else if (num_solutions == 2)
        std::cout << solutions[0] << "," << solutions[1] << std::endl;
    else
        return 1;
}