#include "quadratic.h"  // string_to_double
#include <iostream>     // std::cout

/*! The string_to_double function has three main behaviors:
 * 1. Complete parse: <string> can be fully converted (e.g., "1", "4.5", "1e6"): <flag>=true, <value> set
 * 2. Partial parse: Part of <string> is parsed (e.g., "1a", "12.4f", "4.5.6"): <flag>=false, <value> not set
 * 3. No parse: <string> can't be parsed at all (e.g., "A"): <flag>=false, <value> not set
 */
int main(int argc, char **argv)
{
    const int num_tests = 7;

    const char *input_strings[num_tests] = {"1", "4.5", "1e6", "1a", "12.4f", "4.5.6", "A"};
    
    // In-out variable - passed as a parameter, but value is updated by the function
    double in_out_values[num_tests] = {-99, -99, -99, -99, -99, -99, -99};

    bool expected_flags[num_tests] = {true, true, true, false, false, false, false};
    double expected_values[num_tests] = {1, 4.5, 1e6, -99, -99, -99, -99};

    int errors;
    for (int i=0; i < num_tests; i++)
    {
        bool output_flag = string_to_double(input_strings[i], &in_out_values[i]);
        if (output_flag != expected_flags[i] || in_out_values[i] != expected_values[i])
        {
            std::cout << "Inputs: {'" << input_strings[i] << "', -99}; ";
            std::cout << "Outputs: {" << in_out_values[i] << ", " << output_flag << "}; ";
            std::cout << "Expected: {" << expected_values[i] << ", " << expected_flags[i] << "}" << std::endl;
            errors++;
        }
    }
}