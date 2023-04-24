// common_sub_expression_elimination_in_code_optimization

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

string eliminate_common_subexpressions(string code)
{
    // Initialize an empty unordered_map to store expressions and their computed values
    unordered_map<string, string> computed_values;
    // Initialize an empty string to store the optimized code
    string optimized_code = "";
    // Split the code into individual statements using newline character as delimiter
    size_t pos = 0;
    string delimiter = "\n";
    while ((pos = code.find(delimiter)) != string::npos)
    {
        string statement = code.substr(0, pos);
        code.erase(0, pos + delimiter.length());
        // Check if the statement is an assignment statement
        if (statement.find("=") != string::npos)
        {
            // Split the statement into left-hand side and right-hand side using the equal sign as delimiter
            size_t equal_pos = statement.find("=");
            string lhs = statement.substr(0, equal_pos);
            string rhs = statement.substr(equal_pos + 1);
            // Check if the right-hand side is already computed and stored in the unordered_map
            if (computed_values.find(rhs) != computed_values.end())
            {
                // Use the computed value instead of computing the expression again
                optimized_code += lhs + " = " + computed_values[rhs] + ";\n";
            }
            else
            {
                // Compute the value of the expression and store it in the unordered_map
                optimized_code += statement + "\n";
                computed_values[rhs] = lhs;
            }
        }
        else
        {
            // The statement is not an assignment statement, so it doesn't have any sub-expressions to eliminate
            optimized_code += statement + "\n";
        }
    }
    return optimized_code;
}

int main()
{
    // Example code to optimize
    string code = "a = 2 + 3;\nb = a * 4;\nc = a + b;\nd = a + b;\n";
    // Optimize the code by eliminating common sub-expressions
    string optimized_code = eliminate_common_subexpressions(code);
    // Print the optimized code
    cout << optimized_code;
    return 0;
}
