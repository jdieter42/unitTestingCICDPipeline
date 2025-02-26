#include "quadratic.h"  // string_to_double
#include <iostream>     // std::cout

/* The solve_quadratic function has four main behaviors:
 * 1. A=0 - Any scenario where this is true should return 0 and shouldn't touch <solutions>
 * 2. 4*a*c > b*b (ex: a=1,b=1,c=1) - Discriminant < 0, return 0 and don't touch <solutions>
 * 3. 4*a*c = b*b (ex: a=1,b=2,c=1) - Discriminant = 0, return 1 and set <solutions>[0]
 * 4. 4*a*c < b*b (ex: a=1,b=3,c=2)- Discriminant > 0, return 2 and set <solutions>[0] and [1]
 * In the last case, <solutions>[0] should be the "b-" answer, and [1] should be the "b+" answer
*/
int main(int argc, char **argv)
{
    // 7 tests - 1 input for case 1, 2 inputs for other cases
    const int num_tests = 7; 

    // Inputs
    const double a[num_tests] = {0, 1, 1, 1, 1, 1, 1};
    const double b[num_tests] = {1, 1, 2, 2, 4, 3, -1};
    const double c[num_tests] = {1, 1, 3, 1, 4, 2, -2};

    // In-out values - -99 is used so we can check if value of solutions is changed
    double solutions[num_tests][2] = {{-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}, {-99, -99}};

    // Expected outputs
    const double expected_solutions[num_tests][2] = {{-99, -99}, {-99, -99}, {-99, -99}, {-1, -99}, {-2, -99}, {-2, -1}, {-1, 2}};
    const int expected_num_solutions[num_tests] = {0, 0, 0, 1, 1, 2, 2}; 

    int errors;
    for (int i=0; i < num_tests; i++)
    {
        int num_solutions = solve_quadratic(a[i], b[i], c[i], solutions[i]);
        if (num_solutions != expected_num_solutions[i] || solutions[i][0] != expected_solutions[i][0] || solutions[i][1] != expected_solutions[i][1])
        {
            std::cout << "Inputs: {" << a[i] << ", " << b[i] << ", " << c[i] << ", {-99, -99}}" << std::endl;
            std::cout << "Outputs: {" << num_solutions << ", {" << solutions[i][0] << ", " << solutions[i][1] << "}}" << std::endl;
            std::cout << "Expected: {" << expected_num_solutions[i] << ", {" << expected_solutions[i][0] << ", " << expected_solutions[i][1] << "}}" << std::endl;
            errors++;
        }
    }
}