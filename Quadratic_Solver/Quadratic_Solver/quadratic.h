#include <string>       // std::stod
#include <cstring>      // strlen
#include <cmath>        // sqrt
#include <stdexcept>    // std::invalid_argument, std::out_of_range

//! Attempts to set <value> to parsed value of <string>
/*! Attempts to parse <string> as a double value and set <value>
 * as the parsed double. Returns true if <value> was set to the 
 * parsed value of <string>, and false otherwise
 */
bool string_to_double(const char *string, double *value)
{
    double converted_val;
    size_t converted_pos = 0;

    // Make sure string can be parsed at all
    try
    {
        converted_val = std::stod(string, &converted_pos);
    }
    catch(std::invalid_argument const& ex)
    {
        return false;
    }
    catch(std::out_of_range const& ex)
    {
        return false;
    }

    // Make sure all characters were converted
    int str_len = strlen(string);
    if (converted_pos != str_len)
        return false;

    // If all characters are converted, set <value> and return true
    *value = converted_val;
    return true;    
}

//! Solves the quadratic equation for coefficients a,b,c. Returns # of solutions
/*! Attempts to solve the quadratic equation defined by given a,b,c and store the result(s)
 * in the provided <solutions> array, which must be allocated for at least two doubles.
 * If two solutions are found, the negative solution (b - discriminant) will always come first.
 * Returns the number of solutions found. 
 */
int solve_quadratic(double a, double b, double c, double *solutions)
{
    // A=0 will cause a division-by-zero error - no solution
    if (a == 0)
        return 0;

    double discriminant = b * b - (4 * a * c);
    if (discriminant < 0)
        return 0;
    else if (discriminant == 0)
    {
        solutions[0] = -b / (2 * a);
        return 1;
    }
    else 
    {
        solutions[0] = (-b - sqrt(discriminant)) / (2 * a);
        solutions[1] = (-b + sqrt(discriminant)) / (2 * a);
        return 2;
    }
}