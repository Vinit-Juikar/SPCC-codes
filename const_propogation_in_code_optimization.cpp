#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
struct Expression
{
    string op;
    string arg1;
    string arg2;
    string result;
};
unordered_map<string, int> constants = {
    {"a", 5},
    {"b", 10},
    {"c", 2}};
int main()
{
    vector<Expression> expressions = {
        {"+", "a", "b", "t1"},
        {"*", "t1", "c", "t2"},
        {"-", "t2", "b", "t3"},
        {"/", "t3", "c", "t4"}};
    // perform constant propagation
    for (int i = 0; i < expressions.size(); i++)
    {
        Expression expr = expressions[i];
        if (constants.count(expr.arg1))
        {
            expr.arg1 = to_string(constants[expr.arg1]);
        }
        if (constants.count(expr.arg2))
        {
            expr.arg2 = to_string(constants[expr.arg2]);
        }
        if (expr.op == "+" && constants.count(expr.arg1) && constants.count(expr.arg2))
        {
            expressions[i].result = to_string(constants[expr.arg1] + constants[expr.arg2]);
        }
        else if (expr.op == "-" && constants.count(expr.arg1) && constants.count(expr.arg2))
        {
            expressions[i].result = to_string(constants[expr.arg1] - constants[expr.arg2]);
        }
        else if (expr.op == "*" && constants.count(expr.arg1) && constants.count(expr.arg2))
        {
            expressions[i].result = to_string(constants[expr.arg1] * constants[expr.arg2]);
        }
        else if (expr.op == "/" && constants.count(expr.arg1) && constants.count(expr.arg2))
        {
            expressions[i].result = to_string(constants[expr.arg1] / constants[expr.arg2]);
        }
    }
    // display the optimized code
    cout << "Optimized Code:" << endl;
    for (int i = 0; i < expressions.size(); i++)
    {
        cout << expressions[i].result << " = " << expressions[i].arg1 << " " << expressions[i].op
             << " " << expressions[i].arg2 << endl;
    }
    return 0;
}
