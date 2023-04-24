//Lexical Analysis

#include <iostream>
#include <string>
#include <sstream>
int main()
{
    std::string input = "c = a*b+d";
    std::stringstream ss(input);
    std::string token;
    while (ss >> token)
    {
        if (token == "c")
        {
            std::cout << "Identifier: " << token << std::endl;
        }
        else if (token == "=")
        {
            std::cout << "Assignment operator" << std::endl;
        }
        else if (token == "a" || token == "b" || token == "d")
        {
            std::cout << "Identifier: " << token << std::endl;
        }
        else if (token == "*" || token == "+")
        {
            std::cout << "Arithmetic operator" << std::endl;
        }
        else
        {
            std::cout << "Invalid token: " << token << std::endl;
            return 1;
        }
    }
    return 0;
}
