// lexical analysis on int a, b, c

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string line = "int a, b, c;";
    vector<string> tokens;
    string token = "";
    bool is_declaring = false;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
        { // skip whitespace
            continue;
        }
        else if (line[i] == ',')
        { // end of variable declaration
            is_declaring = true;
            if (token != "")
            { // check for empty token
                tokens.push_back(token);
                token = "";
            }
        }
        else if (line[i] == ';')
        { // end of statement
            is_declaring = false;
            if (token != "")
            { // check for empty token
                tokens.push_back(token);
                token = "";
            }
        }
        else
        { // add character to current token
            token += line[i];
            if (!is_declaring)
            { // if not declaring, add token to vector and reset it
                tokens.push_back(token);
                token = "";
            }
        }
    }
    // output the tokens
    cout << "Tokens: ";
    for (int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i] << " ";
    }
    cout << endl;
    return 0;
}
